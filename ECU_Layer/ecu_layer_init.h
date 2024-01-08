/* 
 * File:   ecu_layer_init.h
 * Author: M0rE
 *
 * Created on December 26, 2023, 6:09 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H
#include    "../MCAL_Layer/GPIO/hal_gpio.h"
#include    "LCD/ecu_lcd.h"
#include    "7SEG/ecu_7seg.h"
#include    "BUTTON/ecu_button.h"
#include    "DC_MOTOR/ecu_dc_motor.h"
#include    "KEYPAD/ecu_keypad.h"
#include    "LED/ecu_led.h"
#include    "RELAY/ecu_relay.h"
/*
 */
/*
lcd_4bit_t lcd4 = {
    .rs.port=PORTC_INDEX,
    .rs.pin=GPIO_PIN0,
    .rs.direction=GPIO_DIRECTION_OUTPUT,
    .rs.logic=GPIO_LOW,
    
    .en.port=PORTC_INDEX,
    .en.pin=GPIO_PIN1,
    .en.direction=GPIO_DIRECTION_OUTPUT,
    .en.logic=GPIO_LOW,
    
    .data_pin[0].port=PORTC_INDEX,
    .data_pin[0].pin=GPIO_PIN2,
    .data_pin[0].direction=GPIO_DIRECTION_OUTPUT,
    .data_pin[0].logic=GPIO_LOW,
    
    .data_pin[1].port=PORTC_INDEX,
    .data_pin[1].pin=GPIO_PIN3,
    .data_pin[1].direction=GPIO_DIRECTION_OUTPUT,
    .data_pin[1].logic=GPIO_LOW,
    
    .data_pin[2].port=PORTC_INDEX,
    .data_pin[2].pin=GPIO_PIN4,
    .data_pin[2].direction=GPIO_DIRECTION_OUTPUT,
    .data_pin[2].logic=GPIO_LOW,
    
    .data_pin[3].port=PORTC_INDEX,
    .data_pin[3].pin=GPIO_PIN5,
    .data_pin[3].direction=GPIO_DIRECTION_OUTPUT,
    .data_pin[3].logic=GPIO_LOW,
};


uint8_t mat [4][6]={{'N','7','8','9','*','/'},
                    {'C','4','5','6','-','E'},
                    {'%','1','2','3','+','('},
                    {'^','0','.','=','+',')'}
                 };

keypad_t pad={
    .rowPins[0].port=PORTD_INDEX,
    .rowPins[0].pin=GPIO_PIN0,
    .rowPins[0].direction=GPIO_DIRECTION_OUTPUT,
    .rowPins[0].logic=GPIO_LOW, 
    
    .rowPins[1].port=PORTD_INDEX,
    .rowPins[1].pin=GPIO_PIN1,
    .rowPins[1].direction=GPIO_DIRECTION_OUTPUT,
    .rowPins[1].logic=GPIO_LOW, 
    
    .rowPins[2].port=PORTD_INDEX,
    .rowPins[2].pin=GPIO_PIN2,
    .rowPins[2].direction=GPIO_DIRECTION_OUTPUT,
    .rowPins[2].logic=GPIO_LOW, 
    
    .rowPins[3].port=PORTD_INDEX,
    .rowPins[3].pin=GPIO_PIN3,
    .rowPins[3].direction=GPIO_DIRECTION_OUTPUT,
    .rowPins[3].logic=GPIO_LOW, 
    
    .colPins[0].port=PORTD_INDEX,
    .colPins[0].pin=GPIO_PIN4,
    .colPins[0].direction=GPIO_DIRECTION_INPUT,
    .colPins[0].logic=GPIO_LOW, 
    
    .colPins[1].port=PORTD_INDEX,
    .colPins[1].pin=GPIO_PIN5,
    .colPins[1].direction=GPIO_DIRECTION_INPUT,
    .colPins[1].logic=GPIO_LOW, 
    
    .colPins[2].port=PORTD_INDEX,
    .colPins[2].pin=GPIO_PIN6,
    .colPins[2].direction=GPIO_DIRECTION_INPUT,
    .colPins[2].logic=GPIO_LOW, 
    
    .colPins[3].port=PORTD_INDEX,
    .colPins[3].pin=GPIO_PIN7,
    .colPins[3].direction=GPIO_DIRECTION_INPUT,
    .colPins[3].logic=GPIO_LOW, 
    
    .colPins[4].port=PORTA_INDEX,
    .colPins[4].pin=GPIO_PIN0,
    .colPins[4].direction=GPIO_DIRECTION_INPUT,
    .colPins[4].logic=GPIO_LOW, 
    
    .colPins[5].port=PORTA_INDEX,
    .colPins[5].pin=GPIO_PIN1,
    .colPins[5].direction=GPIO_DIRECTION_INPUT,
    .colPins[5].logic=GPIO_LOW, 
    
    
    .conn=KEYPAD_PULLDOWN,
    .keypadMatrix = &mat
    
};
 */

#endif	/* ECU_LAYER_INIT_H */

