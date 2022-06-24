/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOC
#define ACCELEROC_Pin GPIO_PIN_1
#define ACCELEROC_GPIO_Port GPIOH
#define ACCELEROC_EXTI_IRQn EXTI1_IRQn
#define RST_FROM_HMI_Pin GPIO_PIN_0
#define RST_FROM_HMI_GPIO_Port GPIOC
#define RST_FROM_HMI_EXTI_IRQn EXTI0_IRQn
#define LED_VBAT_SEQ_Pin GPIO_PIN_1
#define LED_VBAT_SEQ_GPIO_Port GPIOC
#define LED_VBAT_RECOV_Pin GPIO_PIN_2
#define LED_VBAT_RECOV_GPIO_Port GPIOC
#define LED_VBAT_PAYLOAD_Pin GPIO_PIN_3
#define LED_VBAT_PAYLOAD_GPIO_Port GPIOC
#define VBAT_SEQ_Pin GPIO_PIN_0
#define VBAT_SEQ_GPIO_Port GPIOA
#define VBAT_RECOV_Pin GPIO_PIN_1
#define VBAT_RECOV_GPIO_Port GPIOA
#define VBAT_PAYLOAD_Pin GPIO_PIN_2
#define VBAT_PAYLOAD_GPIO_Port GPIOA
#define M3_CLOSE_Pin GPIO_PIN_3
#define M3_CLOSE_GPIO_Port GPIOA
#define M3_OPEN_Pin GPIO_PIN_4
#define M3_OPEN_GPIO_Port GPIOA
#define M2_CLOSE_Pin GPIO_PIN_5
#define M2_CLOSE_GPIO_Port GPIOA
#define M2_OPEN_Pin GPIO_PIN_6
#define M2_OPEN_GPIO_Port GPIOA
#define M1_CLOSE_Pin GPIO_PIN_7
#define M1_CLOSE_GPIO_Port GPIOA
#define M1_OPEN_Pin GPIO_PIN_4
#define M1_OPEN_GPIO_Port GPIOC
#define M3_ENB_Pin GPIO_PIN_5
#define M3_ENB_GPIO_Port GPIOC
#define M3_ENA_Pin GPIO_PIN_0
#define M3_ENA_GPIO_Port GPIOB
#define M3_INB_Pin GPIO_PIN_1
#define M3_INB_GPIO_Port GPIOB
#define M3_INA_Pin GPIO_PIN_2
#define M3_INA_GPIO_Port GPIOB
#define M3_PWM_Pin GPIO_PIN_10
#define M3_PWM_GPIO_Port GPIOB
#define M2_ENB_Pin GPIO_PIN_12
#define M2_ENB_GPIO_Port GPIOB
#define M2_ENA_Pin GPIO_PIN_13
#define M2_ENA_GPIO_Port GPIOB
#define M2_INB_Pin GPIO_PIN_14
#define M2_INB_GPIO_Port GPIOB
#define M2_INA_Pin GPIO_PIN_15
#define M2_INA_GPIO_Port GPIOB
#define M2_PWM_Pin GPIO_PIN_6
#define M2_PWM_GPIO_Port GPIOC
#define M1_ENB_Pin GPIO_PIN_7
#define M1_ENB_GPIO_Port GPIOC
#define M1_ENA_Pin GPIO_PIN_8
#define M1_ENA_GPIO_Port GPIOC
#define M1_INB_Pin GPIO_PIN_9
#define M1_INB_GPIO_Port GPIOC
#define M1_INA_Pin GPIO_PIN_8
#define M1_INA_GPIO_Port GPIOA
#define M1_PWM_Pin GPIO_PIN_9
#define M1_PWM_GPIO_Port GPIOA
#define RGB1_B_Pin GPIO_PIN_15
#define RGB1_B_GPIO_Port GPIOA
#define RGB1_G_Pin GPIO_PIN_10
#define RGB1_G_GPIO_Port GPIOC
#define RGB1_R_Pin GPIO_PIN_11
#define RGB1_R_GPIO_Port GPIOC
#define IHM_DIO4_Pin GPIO_PIN_2
#define IHM_DIO4_GPIO_Port GPIOD
#define IHM_DIO4_EXTI_IRQn EXTI2_IRQn
#define IHM_DIO3_Pin GPIO_PIN_3
#define IHM_DIO3_GPIO_Port GPIOB
#define IHM_DIO3_EXTI_IRQn EXTI3_IRQn
#define IHM_DIO2_Pin GPIO_PIN_4
#define IHM_DIO2_GPIO_Port GPIOB
#define IHM_DIO2_EXTI_IRQn EXTI4_IRQn
#define IHM_DIO1_Pin GPIO_PIN_5
#define IHM_DIO1_GPIO_Port GPIOB
#define IHM_DIO1_EXTI_IRQn EXTI9_5_IRQn
#define IHM_TX_Pin GPIO_PIN_6
#define IHM_TX_GPIO_Port GPIOB
#define IHM_RX_Pin GPIO_PIN_7
#define IHM_RX_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
