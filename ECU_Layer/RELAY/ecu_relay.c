
/* 
 * File:   ecu_relay.c
 * Author: M0rE
 *
 * Created on December 14, 2023, 2:10 PM
 */

#include "ecu_relay.h"

STD_ReturnType relayInit(const relay_t * relay)
{
    STD_ReturnType ret = E_OK;
    if(NULL ==relay){
        ret = E_NOT_OK;
    }else{
         pin_config_t pinObj = {.port=relay->port ,
                                    .pin=relay->pin,
                                    .logic=relay->state,
                                    .direction=GPIO_DIRECTION_OUTPUT
                                                     };
         ret = gpio_pin_initialize(&pinObj);
        
    }

    return ret;
}

STD_ReturnType relayON(const relay_t * relay)
{
    
    STD_ReturnType ret = E_OK;
    if(NULL ==relay){
        ret = E_NOT_OK;
    }else{
           pin_config_t pinObj = {.port=relay->port ,
                                    .pin=relay->pin,
                                    .logic=relay->state,
                                    .direction=GPIO_DIRECTION_OUTPUT
                                                     };
         ret = gpio_pin_write_logic(&pinObj,GPIO_HIGH);
    }

    return ret;
    
}


STD_ReturnType relayOFF(const relay_t * relay)
{
    STD_ReturnType ret = E_OK;
    if(NULL ==relay){
        ret = E_NOT_OK;
    }else{
        pin_config_t pinObj = {.port=relay->port ,
                                    .pin=relay->pin,
                                    .logic=relay->state,
                                    .direction=GPIO_DIRECTION_OUTPUT
                                                     };
         ret = gpio_pin_write_logic(&pinObj,GPIO_LOW);
    }

    return ret;

}
