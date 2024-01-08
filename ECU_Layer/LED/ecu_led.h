/* 
 * File:   ecu_led.h
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:34 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*  Section : Includes    */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"

/*  Section : Macro Declarations     */

typedef enum{
    LED_OFF,
    LED_ON
}led_stauts_t;

typedef struct {
    uint8_t port_name:3;
    uint8_t pin:3;
    uint8_t led_status :1;
    uint8_t Reserved :1;
}led_t;
/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */

/*  Section : Function Declarations    */
STD_ReturnType led_init(const led_t * led);
STD_ReturnType led_on(const led_t * led);
STD_ReturnType led_off(const led_t * led);
STD_ReturnType led_toggle(const led_t * led);

#endif	/* ECU_LED_H */

