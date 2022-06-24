/** ************************************************************* *
 * @file        API_leds.h
 * @brief       
 * 
 * @date        2021-12-08
 * @author      Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * 
 * Mines Space
 * 
 * ************************************************************* **/
#ifndef LEDS_INC_API_LEDS_H_
#define LEDS_INC_API_LEDS_H_

/* ------------------------------------------------------------- --
   includes
-- ------------------------------------------------------------- */
#include "stdint.h"
#include "stdbool.h"

/* ------------------------------------------------------------- --
   types
-- ------------------------------------------------------------- */
/* List of commands available for this API. 
 * -> Stop command      : will stop the motors 
 * -> Open/Close command: will run the motors until reach the end */
typedef enum
{
    E_CMD_LEDS_NONE,
    E_CMD_LEDS_RED,
    E_CMD_LEDS_GREEN,
    E_CMD_LEDS_BLUE
}ENUM_LEDS_CMD_t;

typedef enum
{
    E_LIST_LED_RGB,
    E_LIST_LED_VBAT_SEQ,
    E_LIST_LED_VBAT_RECOV,
    E_LIST_LED_VBAT_PAYLOAD
}ENUM_LEDS_LIST_t;

/* ------------------------------------------------------------- --
   function propotypes
-- ------------------------------------------------------------- */
void API_LEDS_START(void);
void API_LEDS_SEND_PARAMETER(ENUM_LEDS_LIST_t led, ENUM_LEDS_CMD_t command);

/* ------------------------------------------------------------- --
   end of file
-- ------------------------------------------------------------- */

#endif /* LEDS_INC_API_LEDS_H_ */
