/*
 * File:   Application.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */

/* testing commit*/

#include "Application.h"

void adisr(void);

lcd_4bit_t lcd_1 = {
	.rs.port = PORTC_INDEX,
	.rs.pin = GPIO_PIN0,
	.rs.direction = GPIO_DIRECTION_OUTPUT,
	.rs.logic = GPIO_LOW,
	.en.port = PORTC_INDEX,
	.en.pin = GPIO_PIN1,
	.en.direction = GPIO_DIRECTION_OUTPUT,
	.en.logic = GPIO_LOW,
	.data_pin[0].port = PORTC_INDEX,
	.data_pin[0].pin = GPIO_PIN2,
	.data_pin[0].direction = GPIO_DIRECTION_OUTPUT,
	.data_pin[0].logic = GPIO_LOW,
	.data_pin[1].port = PORTC_INDEX,
	.data_pin[1].pin = GPIO_PIN3,
	.data_pin[1].direction = GPIO_DIRECTION_OUTPUT,
	.data_pin[1].logic = GPIO_LOW,
	.data_pin[2].port = PORTC_INDEX,
	.data_pin[2].pin = GPIO_PIN4,
	.data_pin[2].direction = GPIO_DIRECTION_OUTPUT,
	.data_pin[2].logic = GPIO_LOW,
	.data_pin[3].port = PORTC_INDEX,
	.data_pin[3].pin = GPIO_PIN5,
	.data_pin[3].direction = GPIO_DIRECTION_OUTPUT,
	.data_pin[3].logic = GPIO_LOW
};
ADC_conf_t ad1 = {
	.ADC_CallBack = adisr,
	.ADC_LR_ADJUST = RIGHT_ADJUST,
	.ADC_Vref = ADC_VREF_DISABLE,
	.aqcTime = ADC_12TAD,
	.ch = ADC_CHANNEL_AN0,
	.clk = FoscBy16
};

uint16_t res1 = 0;
uint8_t flag = 0;

void adisr(void)
{
	ADC_GetConversionRes(&ad1, &res1);
	flag++;
}


int main(int argc, char **argv)
{
	ADC_INIT(&ad1);
	//uint8_t state = 0;
	lcd_4bit_intialize(&lcd_1);
	lcd_4bit_send_string_pos(&lcd_1, 1, 7, "ADC TEST");
	__delay_ms(2000);
	while (1) {
		ADC_GetFrom_NON_BLOCKING(&ad1, ADC_CHANNEL_AN0);
	}

	return(EXIT_SUCCESS);
}
