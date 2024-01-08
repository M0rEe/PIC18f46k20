/* 
 * File:   ecu_7seg.c
 * Author: M0rE
 *
 * Created on December 17, 2023, 3:36 PM
 */
#include "ecu_7seg.h"


STD_ReturnType segInit(const segment_t *seg)
{
    STD_ReturnType ret = E_OK;
    if(NULL == seg){
        ret = E_NOT_OK;
    }else{
       uint8_t i;
        for (i = 0; i < 4; i++) {
            gpio_pin_initialize(&(seg->segPins[i]));
        }
    }
    return ret;
}

STD_ReturnType segWrite(const segment_t *seg,uint8_t num)
{
    STD_ReturnType ret = E_OK;
    if((NULL == seg)&&(num >9)){
        ret = E_NOT_OK;
    }else{
        gpio_pin_write_logic(&(seg->segPins[0]),(num)&0x01);
        gpio_pin_write_logic(&(seg->segPins[1]),(num>>1)&0x01);
        gpio_pin_write_logic(&(seg->segPins[2]),(num>>2)&0x01);
        gpio_pin_write_logic(&(seg->segPins[3]),(num>>3)&0x01);
    }
    return ret; 
}

