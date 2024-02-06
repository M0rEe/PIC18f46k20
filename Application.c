/*
 * File:   Application.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */



#include "Application.h"
#include "MCAL_Layer/TIMER2/hal_timer2.h"

led_t led1 = {
    .port_name = PORTD_INDEX,
    .pin = GPIO_PIN1, 
    .led_status = LED_OFF
};




void fun() {
    //led_toggle(&led1);
    TOGGLE_BIT(LATD,GPIO_PIN1);
}

int main() {
    Timer2_t timer2_obj;
    timer2_obj.tmr2CallBack = fun;
    timer2_obj.preScalerValue = TIMER2_PRESCALER_DIV_BY_16;
    timer2_obj.postScalerValue = TIMER2_POSTSCALER_DIV_BY_16;
    timer2_obj.preLoadedValue = 0;
    led_init(&led1);

    Timer2_Init(&timer2_obj);
    while (1) {
        
    }

    return (EXIT_SUCCESS);
}


