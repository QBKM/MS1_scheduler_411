/** ************************************************************* *
 * @file        API_buzzer.h
 * @brief       
 * 
 * @date        2021-08-16
 * @author      Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * 
 * Mines Space
 * 
 * ************************************************************* **/

#ifndef AUDIO_BUZZER_INC_API_BUZZER_H_
#define AUDIO_BUZZER_INC_API_BUZZER_H_

/* ------------------------------------------------------------- --
   includes
-- ------------------------------------------------------------- */
#include "stdint.h"

/* ------------------------------------------------------------- --
   function prototypes
-- ------------------------------------------------------------- */
void API_BUZZER_START(void);
void API_BUZZER_SEND_PARAMETER(uint16_t period, float dutycycle);

/* ------------------------------------------------------------- --
   end of file
-- ------------------------------------------------------------- */
#endif /* AUDIO_BUZZER_INC_API_BUZZER_H_ */
