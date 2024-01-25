/*
 * File:   Application.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */



#include "Application.h"

volatile uint16_t flag = 0;

led_t led3 = {
	.port_name = PORTC_INDEX,
	.pin = GPIO_PIN0,
	.led_status = LED_OFF
};

void functionss(void)
{
	flag++;
	TOGGLE_BIT(*(&LATC), GPIO_PIN0);
};
timer0_t tt = {
	.prescalerValue = TIMER0_PRESCALER_BY_8,
	.callBack = functionss,
	.preloadedValue = 3036,
	.prescalerEnable = TIMER0_PRESCALER_ENABLE_CFG,
	.mode = TIMER0_TIMER_MODE_CFG,
	.regSize = TIMER0_REGISTER_16BIT_CFG,
};

int main()
{
	led_init(&led3);
	timer0_Init(&tt);
	while (1) {

	}

	return(EXIT_SUCCESS);
}


