/* 
 * File:   ecu_button.h
 * Author: M0rE
 *
 * Created on December 11, 2023, 1:37 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*  Section : Includes    */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_button_cfg.h"


/*  Section : Macro Declarations     */


/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}btn_state_t;

typedef enum{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}btn_activity_t;

typedef struct {
    pin_config_t btn_pin;
    btn_state_t state;
    btn_activity_t button_connection ;
}button_t;

/*  Section : Function Declarations    */
STD_ReturnType btn_init(const button_t *);
STD_ReturnType btn_read_state(const button_t *,btn_state_t *btn_state);


#endif	/* ECU_BUTTON_H */

