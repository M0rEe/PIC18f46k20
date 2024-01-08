
/* 
 * File:   ecu_button.c
 * Author: M0rE
 *
 * Created on December 11, 2023, 1:37 PM
 */

#include "ecu_button.h"


STD_ReturnType btn_init(const button_t *btn )
{
    STD_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_direction_initialize(&btn->btn_pin);
    }
    return ret ;
}

STD_ReturnType btn_read_state(const button_t *btn ,btn_state_t *btn_state)
{
    STD_ReturnType ret = E_OK;
    logic_t logic_st = GPIO_LOW;
    if(NULL == btn || NULL == btn_state){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_read_logic(&(btn->btn_pin),&logic_st);
        if( BUTTON_ACTIVE_HIGH == btn->button_connection ){
            if(GPIO_HIGH ==logic_st ){
                *btn_state = BUTTON_PRESSED;
            }else{
                *btn_state = BUTTON_RELEASED;
                
            }
        }else {
            if(GPIO_HIGH ==logic_st ){
                *btn_state = BUTTON_RELEASED;
            }else{
                *btn_state = BUTTON_PRESSED;
                
            }
        }
        ret = E_OK;
    }
    return ret ;
}