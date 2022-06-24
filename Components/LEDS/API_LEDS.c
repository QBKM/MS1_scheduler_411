/** ************************************************************* *
 * @file        API_leds.c
 * @brief       
 * 
 * @date        2021-12-08
 * @author      Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * 
 * Mines Space
 * 
 * ************************************************************* **/


/* ------------------------------------------------------------- --
   include
-- ------------------------------------------------------------- */
#include "freeRtos.h"
#include "task.h"
#include "queue.h"
#include "gpio.h"
#include "API_LEDS.h"

#include "MS1_config.h"

/* ------------------------------------------------------------- --
   defines
-- ------------------------------------------------------------- */
typedef struct
{
    ENUM_LEDS_CMD_t     cmd;
    ENUM_LEDS_LIST_t    list;
}STRUCT_LEDS_t;

/* ------------------------------------------------------------- --
   handles
-- ------------------------------------------------------------- */
TaskHandle_t TaskHandle_leds;
QueueHandle_t QueueHandle_leds_cmd;

/* ------------------------------------------------------------- --
   variables
-- ------------------------------------------------------------- */

/* ------------------------------------------------------------- --
   prototypes
-- ------------------------------------------------------------- */
static void handler_leds(void* parameters);

/* ============================================================= ==
   tasks functions
== ============================================================= */
/** ************************************************************* *
 * @brief       This task manage the payload system with the 
 *              opening or closing features. The task need to 
 *              receive command from queue to operate.
 *              Please check at the ENUM_CMD_ID_t enum to send
 *              commands
 * 
 * @param       parameters 
 * ************************************************************* **/
static void handler_leds(void* parameters)
{
    STRUCT_LEDS_t led;

    while(1)
    {
        /* check for new command */
        if(xQueueReceive(QueueHandle_leds_cmd, &led, portMAX_DELAY)) 
        {
            switch (led.list)
            {
                /* LED RGB */
                case E_LIST_LED_RGB :
                    switch (led.cmd)
                    {
                        case E_CMD_LEDS_NONE:   
                            HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_RESET);
                            break;

                        case E_CMD_LEDS_RED:    
                            HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_SET);
                            break;

                        case E_CMD_LEDS_GREEN: 
                            HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_SET);
                            break;

                        case E_CMD_LEDS_BLUE:  
                            HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_RESET);
                            HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_SET);
                            break;

                        default:
                            break;
                    }
                    break;

                /* LED VBAT SEQ */
                case E_LIST_LED_VBAT_SEQ :
                    switch (led.cmd)
                    {
                        case E_CMD_LEDS_NONE:   
                            HAL_GPIO_WritePin(LED_VBAT_SEQ_GPIO_Port, LED_VBAT_SEQ_Pin, GPIO_PIN_RESET);
                            break;

                        case E_CMD_LEDS_RED:    
                        case E_CMD_LEDS_GREEN: 
                        case E_CMD_LEDS_BLUE:  
                            HAL_GPIO_WritePin(LED_VBAT_SEQ_GPIO_Port, LED_VBAT_SEQ_Pin, GPIO_PIN_SET);
                            break;

                        default:
                            break;
                    }

                /* LED VBAT RECOV */
                case E_LIST_LED_VBAT_RECOV :
                    switch (led.cmd)
                    {
                        case E_CMD_LEDS_NONE:   
                            HAL_GPIO_WritePin(LED_VBAT_RECOV_GPIO_Port, LED_VBAT_RECOV_Pin, GPIO_PIN_RESET);
                            break;

                        case E_CMD_LEDS_RED:    
                        case E_CMD_LEDS_GREEN: 
                        case E_CMD_LEDS_BLUE:  
                            HAL_GPIO_WritePin(LED_VBAT_RECOV_GPIO_Port, LED_VBAT_RECOV_Pin, GPIO_PIN_SET);
                            break;

                        default:
                            break;
                    }

                /* LED VBAT PAYLOAD */
                case E_LIST_LED_VBAT_PAYLOAD :
                    switch (led.cmd)
                    {
                        case E_CMD_LEDS_NONE:   
                            HAL_GPIO_WritePin(LED_VBAT_PAYLOAD_GPIO_Port, LED_VBAT_PAYLOAD_Pin, GPIO_PIN_RESET);
                            break;

                        case E_CMD_LEDS_RED:    
                        case E_CMD_LEDS_GREEN: 
                        case E_CMD_LEDS_BLUE:  
                            HAL_GPIO_WritePin(LED_VBAT_PAYLOAD_GPIO_Port, LED_VBAT_PAYLOAD_Pin, GPIO_PIN_SET);
                            break;

                        default:
                            break;
                    }                                        
                    break;
            
                default:
                    break;
            }
        }
    }
}

/* ============================================================= ==
   public functions
== ============================================================= */
/** ************************************************************* *
 * @brief       init and start the payload task
 * 
 * ************************************************************* **/
void API_LEDS_START(void)
{
    BaseType_t status;

    HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_VBAT_SEQ_GPIO_Port, LED_VBAT_SEQ_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_VBAT_RECOV_GPIO_Port, LED_VBAT_RECOV_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_VBAT_PAYLOAD_GPIO_Port, LED_VBAT_PAYLOAD_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_VBAT_SEQ_GPIO_Port, LED_VBAT_SEQ_Pin, GPIO_PIN_RESET);

    HAL_Delay(500);

    HAL_GPIO_WritePin(RGB1_R_GPIO_Port, RGB1_R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_VBAT_SEQ_GPIO_Port, LED_VBAT_SEQ_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_VBAT_RECOV_GPIO_Port, LED_VBAT_RECOV_Pin, GPIO_PIN_RESET);

    HAL_Delay(500);

    HAL_GPIO_WritePin(RGB1_G_GPIO_Port, RGB1_G_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_VBAT_RECOV_GPIO_Port, LED_VBAT_RECOV_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_VBAT_PAYLOAD_GPIO_Port, LED_VBAT_PAYLOAD_Pin, GPIO_PIN_RESET);

    HAL_Delay(500);

    HAL_GPIO_WritePin(RGB1_B_GPIO_Port, RGB1_B_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_VBAT_PAYLOAD_GPIO_Port, LED_VBAT_PAYLOAD_Pin, GPIO_PIN_SET);

    /* create the queues */
    QueueHandle_leds_cmd  = xQueueCreate(32, sizeof(ENUM_LEDS_CMD_t));

    status = xTaskCreate(handler_leds, "task_leds", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_LEDS, &TaskHandle_leds);
    configASSERT(status == pdPASS);
}

/** ************************************************************* *
 * @brief       send a command to the payload task
 * 
 * @param       cmd 
 * ************************************************************* **/
void API_LEDS_SEND_PARAMETER(ENUM_LEDS_LIST_t led, ENUM_LEDS_CMD_t command)
{
    STRUCT_LEDS_t data =
    {
        .cmd = command, 
        .list = led
    };

    xQueueSend(QueueHandle_leds_cmd, &data, (TickType_t)0);
}

/* ------------------------------------------------------------- --
   end of file
-- ------------------------------------------------------------- */
