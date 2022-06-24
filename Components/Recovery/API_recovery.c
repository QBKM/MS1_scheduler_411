/** ************************************************************* *
 * @file        API_recovery.c
 * @brief       
 * 
 * @date        2021-10-11
 * @author      Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * 
 * Mines Space
 * 
 * ************************************************************* **/


/* ------------------------------------------------------------- --
   include
-- ------------------------------------------------------------- */
#include "API_recovery.h"
#include "freeRtos.h"
#include "task.h"
#include "gpio.h"
#include "tim.h"
#include "queue.h"

#include "MS1_config.h"

/* ------------------------------------------------------------- --
   defines
-- ------------------------------------------------------------- */
#define RECOVERY_CCR_M1        3840u   /* 80% PWM (ARR = 4800) */
#define RECOVERY_CCR_M2        3840u   /* 80% PWM (ARR = 4800) */

/* ------------------------------------------------------------- --
   handles
-- ------------------------------------------------------------- */
TaskHandle_t TaskHandle_recovery;
QueueHandle_t QueueHandle_recov_cmd;
QueueHandle_t QueueHandle_recov_mntr;

/* ------------------------------------------------------------- --
   variables
-- ------------------------------------------------------------- */
static STRUCT_RECOV_t recov_mntr = {0};

/* ------------------------------------------------------------- --
   prototypes
-- ------------------------------------------------------------- */
static void handler_recovery(void* parameters);

static void process_cmd(ENUM_RECOV_CMD_t cmd);
static void check_position(void);

/* ============================================================= ==
   tasks functions
== ============================================================= */
/** ************************************************************* *
 * @brief       This task manage the recovery system with the 
 *              opening or closing features. The task need to 
 *              receive command from queue to operate.
 *              Please check at the ENUM_CMD_ID_t enum to send
 *              commands
 * 
 * @param       parameters 
 * ************************************************************* **/
static void handler_recovery(void* parameters)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    
    ENUM_RECOV_CMD_t cmd = E_CMD_RECOV_NONE;

    while(1)
    {
        /* check for new command */
        if(xQueueReceive(QueueHandle_recov_cmd, &cmd, (TickType_t)0)) 
        {
            process_cmd(cmd);
        }

        /* check if the system has reach the end */
        check_position();

        /* wait until next task period */
        vTaskDelayUntil(&xLastWakeTime, TASK_PERIOD_RECOVERY);
    }
}

/** ************************************************************* *
 * @brief       
 * 
 * @param       cmd 
 * ************************************************************* **/
static void process_cmd(ENUM_RECOV_CMD_t cmd)
{
    switch(cmd)
    {
        case E_CMD_RECOV_OPEN :
            /* diasable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_RESET);

            /* disable the pwm */
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);

            /* run motors clockwise */
            HAL_GPIO_WritePin(M1_INA_GPIO_Port, M1_INA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M1_INB_GPIO_Port, M1_INB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_INA_GPIO_Port, M2_INA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_INB_GPIO_Port, M2_INB_Pin, GPIO_PIN_RESET);

            /* enable the pwm */
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

            /* enable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_SET);

            /* update system structure */
            recov_mntr.status 	= E_STATUS_RECOV_RUNNING;
            recov_mntr.last_cmd = cmd;
            break;

        case E_CMD_RECOV_CLOSE :
            /* disable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_RESET);

            /* disable the pwm */
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);

            /* run motors anti-clockwise */
            HAL_GPIO_WritePin(M1_INA_GPIO_Port, M1_INA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_INB_GPIO_Port, M1_INB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_INA_GPIO_Port, M2_INA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_INB_GPIO_Port, M2_INB_Pin, GPIO_PIN_SET);

            /* enable the pwm */
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

            /* enable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_SET);
            
            /* update system structure */
            recov_mntr.status 	= E_STATUS_RECOV_RUNNING;
            recov_mntr.last_cmd = cmd;
            break;

        case E_CMD_RECOV_STOP :
            /* disable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_RESET);

            /* disable the pwm */
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);

            /* update system structure */
            recov_mntr.status 	= E_STATUS_RECOV_STOP;
            recov_mntr.last_cmd = cmd;

        default :
            break;
    }

    /* update monitoring queue */
    xQueueSend(QueueHandle_recov_mntr, &recov_mntr, (TickType_t)0);
}

/** ************************************************************* *
 * @brief       
 * 
 * ************************************************************* **/
static void check_position(void)
{
    /* check if the system has reach the open point */
    if(HAL_GPIO_ReadPin(M1_OPEN_GPIO_Port, M1_OPEN_Pin) == GPIO_PIN_RESET
    || HAL_GPIO_ReadPin(M2_OPEN_GPIO_Port, M2_OPEN_Pin) == GPIO_PIN_RESET)
    {
    	if(recov_mntr.last_cmd == E_CMD_RECOV_OPEN)
    	{
            /* diasable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_RESET);

            /* disable the pwm */
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);

            /* update the status */
            recov_mntr.status = E_STATUS_RECOV_OPENED;

            /* update monitoring queue */
            xQueueSend(QueueHandle_recov_mntr, &recov_mntr, (TickType_t)0);
    	}
    }

    /* check if the system has reach the close point */
    if(HAL_GPIO_ReadPin(M1_CLOSE_GPIO_Port, M1_CLOSE_Pin) == GPIO_PIN_RESET
    || HAL_GPIO_ReadPin(M2_CLOSE_GPIO_Port, M2_CLOSE_Pin) == GPIO_PIN_RESET)
    {
    	if(recov_mntr.last_cmd == E_CMD_RECOV_CLOSE)
    	{
            /* diasable the motors */
            HAL_GPIO_WritePin(M1_ENA_GPIO_Port, M1_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M1_ENB_GPIO_Port, M1_ENB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENA_GPIO_Port, M2_ENA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M2_ENB_GPIO_Port, M2_ENB_Pin, GPIO_PIN_RESET);

            /* disable the pwm */
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);

            /* update the status */
            recov_mntr.status = E_STATUS_RECOV_CLOSED;

            /* update monitoring queue */
            xQueueSend(QueueHandle_recov_mntr, &recov_mntr, (TickType_t)0);
    	}
    }
}

/* ============================================================= ==
   public functions
== ============================================================= */
/** ************************************************************* *
 * @brief       init and start the recovery task
 * 
 * ************************************************************* **/
void API_RECOVERY_START(void)
{
    BaseType_t status;

    /* init the main structure */
    recov_mntr.last_cmd   = E_CMD_RECOV_NONE;
    recov_mntr.status     = E_STATUS_RECOV_NONE;

    /* init the motors pwm dutycycle */
    TIM2->CCR2 = RECOVERY_CCR_M1;
    TIM3->CCR3 = RECOVERY_CCR_M2;

    /* create the queues */
    QueueHandle_recov_cmd  = xQueueCreate(1, sizeof(ENUM_RECOV_CMD_t));
    QueueHandle_recov_mntr = xQueueCreate(1, sizeof(STRUCT_RECOV_MNTR_t));
    
    /* create the task */
    status = xTaskCreate(handler_recovery, "task_recovery", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_RECOVERY, &TaskHandle_recovery);
    configASSERT(status == pdPASS);
}

/** ************************************************************* *
 * @brief       send a command to the recovery task
 * 
 * @param       cmd 
 * ************************************************************* **/
void API_RECOVERY_SEND_CMD(ENUM_RECOV_CMD_t command)
{
    xQueueSend(QueueHandle_recov_cmd, &command, (TickType_t)0);
}

/** ************************************************************* *
 * @brief       get the recovery status
 * 
 * @param       monitoring 
 * @return      true    new status received
 * @return      false   nothing received
 * ************************************************************* **/
bool API_RECOVERY_GET_MNTR(STRUCT_RECOV_MNTR_t* monitoring)
{
    return (xQueueReceive(QueueHandle_recov_mntr, monitoring, (TickType_t)0)) ? true : false;
}

/* ------------------------------------------------------------- --
   end of file
-- ------------------------------------------------------------- */
