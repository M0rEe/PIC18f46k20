/* 
 * File:   ecu_led.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:34 PM
 */
#include "ecu_led.h"

STD_ReturnType led_init(const led_t * led)
{
    STD_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else{
        pin_config_t pin_obj={.port=led->port_name,
                              .direction=GPIO_DIRECTION_OUTPUT,
                              .pin=led->pin,
                              .logic=led->led_status};
        
        ret = gpio_pin_initialize(&pin_obj);
    }

    return ret;
}

STD_ReturnType led_on(const led_t * led)
{
    STD_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;

    }else{
        pin_config_t pin_obj={.port=led->port_name,
                              .direction=GPIO_DIRECTION_OUTPUT,
                              .pin=led->pin,
                              .logic=led->led_status};
        ret = gpio_pin_write_logic(&pin_obj,GPIO_HIGH);
            
    }
    
    
    
    return ret;
}

STD_ReturnType led_off(const led_t * led)
{
    STD_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;

    }else{
        pin_config_t pin_obj={.port=led->port_name,
                              .direction=GPIO_DIRECTION_OUTPUT,
                              .pin=led->pin,
                              .logic=led->led_status};
        ret = gpio_pin_write_logic(&pin_obj,GPIO_LOW);
    }
    
    
    
    return ret;  
}

STD_ReturnType led_toggle(const led_t * led)
{
    STD_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;

    }else{
        pin_config_t pin_obj={.port=led->port_name,
                              .direction=GPIO_DIRECTION_OUTPUT,
                              .pin=led->pin,
                              .logic=led->led_status};
        ret = gpio_pin_toggle_logic(&pin_obj);
    }
    
    
    
    return ret;
}

