/* 
 * File:   ecu_keypad.c
 * Author: M0rE
 *
 * Created on December 17, 2023, 11:12 PM
 */

#include "ecu_keypad.h"

STD_ReturnType keypadInit(const keypad_t * pad)
{
   STD_ReturnType ret = E_OK;
   
   if(NULL == pad){
       ret = E_NOT_OK;
   }else{
       uint8_t i;
        for (i = 0; i < (KEYPAD_ROWs); i++) {
            gpio_pin_initialize(&pad->rowPins[i]);
        }
        for (i = 0; i < (KEYPAD_COLs); i++) {
            gpio_pin_initialize(&pad->colPins[i]);
        }
   }
   return ret;
}
STD_ReturnType keypadReadValue(const keypad_t * pad,uint8_t *val)
{
   STD_ReturnType ret = E_OK;
   
   if((NULL == pad) || (NULL == val)){
       ret = E_NOT_OK;
   }else{
       uint8_t i;
       uint8_t res=0;
       uint8_t j;
       *val = -1;
       for(uint8_t k =0 ;k<KEYPAD_ROWs;k++)
                gpio_pin_write_logic(&(pad->rowPins[k]),GPIO_LOW);
       
        for (i = 0; i < KEYPAD_ROWs; i++) {
            gpio_pin_write_logic(&(pad->rowPins[i]),GPIO_HIGH);
            for (j = 0; j < KEYPAD_COLs; j++) {
                gpio_pin_read_logic(&(pad->colPins[j]),&res);
                if(res){
                    *val = (*(pad->keypadMatrix))[i][j];
                    break;
                }
            }
            gpio_pin_write_logic(&(pad->rowPins[i]),GPIO_LOW);
        }
   }
   return ret;
}

