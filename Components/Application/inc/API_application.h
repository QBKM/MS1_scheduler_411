/** ************************************************************* *
 * @file        API_application.h
 * @brief       
 * 
 * @date        2021-09-29
 * @author      Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * 
 * Mines Space
 * 
 * ************************************************************* **/

#ifndef APPLICATION_INC_API_APPLICATION_H_
#define APPLICATION_INC_API_APPLICATION_H_

/* ------------------------------------------------------------- --
   types
-- ------------------------------------------------------------- */

typedef enum
{
    E_APP_ISR_NONE,
    E_APP_ISR_AEROC,
    E_APP_ISR_RECOV_OPEN,
    E_APP_ISR_RECOV_CLOSE,
    E_APP_ISR_PAYLOAD_OPEN,
    E_APP_ISR_PAYLOAD_CLOSE
}ENUM_APP_ISR_ID_t;

/* ------------------------------------------------------------- --
   functions
-- ------------------------------------------------------------- */
void API_APPLICATION_START(void);
void API_APPLICATION_CALLBACK_ISR(ENUM_APP_ISR_ID_t ID);

#endif /* APPLICATION_INC_API_APPLICATION_H_ */
