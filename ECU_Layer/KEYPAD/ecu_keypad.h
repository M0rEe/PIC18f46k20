/* 
 * File:   ecu_keypad.h
 * Author: M0rE
 *
 * Created on December 17, 2023, 11:12 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*  Section : Includes     */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"

/*  Section : Macro Declarations     */
#define KEYPAD_ROWs 4
#define KEYPAD_COLs 6
/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef enum{
    KEYPAD_PULLUP,
    KEYPAD_PULLDOWN
}keypad_connection_t;

typedef struct{
    pin_config_t rowPins[KEYPAD_ROWs];
    pin_config_t colPins[KEYPAD_COLs];
    keypad_connection_t conn;
    uint8_t (*keypadMatrix)[KEYPAD_ROWs][KEYPAD_COLs];
    
    
}keypad_t;

/*  Section : Function Declarations    */
STD_ReturnType keypadInit(const keypad_t * pad);
STD_ReturnType keypadReadValue(const keypad_t * pad,uint8_t *val);


#endif	/* ECU_KEYPAD_H */

