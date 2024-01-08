/* 
 * File:   ecu_dc_motor.c
 * Author: M0rE
 *
 * Created on December 15, 2023, 2:35 PM
 */
#include "ecu_dc_motor.h"


STD_ReturnType dcMotor_intit(const dcMotor_t* motor)
{
    STD_ReturnType ret = E_OK;
    if(NULL == motor){
        ret = E_NOT_OK;
    }else{
        ret= gpio_pin_initialize(&(motor->dcMotor_pins[0]));
        ret= gpio_pin_initialize(&(motor->dcMotor_pins[1]));
    }
    return ret ;
}

STD_ReturnType dcMotor_Move_right(const dcMotor_t* motor)
{
    STD_ReturnType ret = E_OK;
    if(NULL == motor){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[0]),GPIO_HIGH);
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[1]),GPIO_LOW);
    }
    return ret ;
}

STD_ReturnType dcMotor_Move_left(const dcMotor_t* motor)
{
    STD_ReturnType ret = E_OK;
    if(NULL == motor){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[1]),GPIO_HIGH);
    }
    return ret ;
}

STD_ReturnType dcMotor_Stop(const dcMotor_t* motor)
{
    STD_ReturnType ret = E_OK;
    if(NULL == motor){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor->dcMotor_pins[1]),GPIO_LOW);
    }
    return ret ;
}
