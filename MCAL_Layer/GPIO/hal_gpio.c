/* 
 * File:   hal_gpio.c 
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */
#include "hal_gpio.h"

static volatile uint8_t *tris_regs[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
static volatile uint8_t *lat_regs[]  = {&LATA,&LATB,&LATC,&LATD,&LATE};
static volatile uint8_t *port_regs[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/**
 * 
 * @param pin_config
 * @param direction
 * @return 
 */
STD_ReturnType gpio_pin_direction_initialize(const pin_config_t * pin_config)
{
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOT_OK;
    }
    else{ 
      switch(pin_config->direction){ 
          case GPIO_DIRECTION_OUTPUT:
              CLEAR_BIT(*(tris_regs[pin_config->port]) ,pin_config->pin );
              break;

          case GPIO_DIRECTION_INPUT:
              SET_BIT(*(tris_regs[pin_config->port]) ,pin_config->pin );
              break;
          default :
              ret = E_NOT_OK;
              break;
      }
    }
    return ret;
}
STD_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config,direction_t *direction_status )
{
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config || NULL == direction_status){
        ret = E_NOT_OK;
    }
    else{ 
        *direction_status = READ_BIT(*(tris_regs[pin_config->port]),pin_config->pin);
    }
    return ret;
}
STD_ReturnType gpio_pin_write_logic(pin_config_t *pin_config,logic_t logic)
{
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOT_OK;
    }
    else{ 
      switch(logic){ 
          case GPIO_LOW:
              CLEAR_BIT(*(lat_regs[pin_config->port]) ,pin_config->pin );
              pin_config->logic = logic;
              break;

          case GPIO_HIGH:
              SET_BIT(*(lat_regs[pin_config->port]) ,pin_config->pin );
              pin_config->logic = logic;
              break;

          default :
              ret = E_NOT_OK;
              break;
      }
    }
    return ret;
}

STD_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config,logic_t* logic)
{
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config || NULL == logic){
        ret = E_NOT_OK;
    }
    else{ 
        *logic = READ_BIT(*(port_regs[pin_config->port]),pin_config->pin);
    }
    return ret;
}

STD_ReturnType gpio_pin_initialize(const pin_config_t *pin_config)
{
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOT_OK;
    }
    else{ 
       gpio_pin_direction_initialize(pin_config);
       gpio_pin_write_logic(pin_config,pin_config->logic);
    }
    return ret;
}

STD_ReturnType gpio_pin_toggle_logic( pin_config_t *pin_config){
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config ){
        ret = E_NOT_OK;
    }
    else{ 
        TOGGLE_BIT(*(lat_regs[pin_config->port]),pin_config->pin);
        pin_config->logic ^= pin_config->logic;
    }
    return ret;
}



STD_ReturnType gpio_port_direction_initialize(port_index_t port_num ,uint8_t direction)
{
    STD_ReturnType ret = E_OK;
    
    *tris_regs[port_num] = direction;
    
    return ret;
}
STD_ReturnType gpio_port_get_direction_status(port_index_t port_num ,uint8_t *direction_status )
{
    STD_ReturnType ret = E_OK;
    if(NULL == direction_status){
        ret= E_NOT_OK;
    }else{
    *direction_status = *tris_regs[port_num];
    }
    return ret;
}
STD_ReturnType gpio_port_write_logic(port_index_t port_num ,uint8_t logic)
{
    STD_ReturnType ret = E_OK;
    
    *lat_regs[port_num] = logic;
    
    return ret;
}
STD_ReturnType gpio_port_read_logic(port_index_t port_num ,uint8_t* logic)
{
    STD_ReturnType ret = E_OK;
    
    if(NULL == logic){
        ret= E_NOT_OK;
    }else{
    *logic = *lat_regs[port_num];
    }
    
    return ret;
}
STD_ReturnType gpio_port_toggle_logic(port_index_t port_num )
{
    STD_ReturnType ret = E_OK;
    
    *tris_regs[port_num] ^= 0xFF ;
    
    return ret;
}
