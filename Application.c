/*
 * File:   Application.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */

/* testing commit*/

#include "Application.h"

led_t led = {
    .port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW };

led_t led2 = {
    .port_name = PORTC_INDEX, .pin = GPIO_PIN1, .led_status = GPIO_LOW};

led_t led3 = {
    .port_name = PORTC_INDEX, .pin = GPIO_PIN2, .led_status = GPIO_LOW};

void app_isr()
{
    __delay_ms(500);
    led_toggle(&led);
}

void app_isr2()
{

    led_toggle(&led2);
}

void app_isr3()
{
    led_toggle(&led3);
}

Interrupt_INTx_t int0 = {
    .pin.port = PORTB_INDEX,
    .pin.pin = GPIO_PIN0,
    .pin.direction = GPIO_DIRECTION_INPUT,
    .src = EXT_INT0,
    .edge = RISNIG_EDGE,
    .priority = HIGH_PRIORITY,
    .callback_function = app_isr};

Interrupt_INTx_t int1 = {
    .pin.port = PORTB_INDEX,
    .pin.pin = GPIO_PIN1,
    .pin.direction = GPIO_DIRECTION_INPUT,
    .src = EXT_INT1,
    .edge = FALLING_EDGE,
    .priority = HIGH_PRIORITY,
    .callback_function = app_isr2};

Interrupt_INTx_t int2 = {
    .pin.port = PORTB_INDEX,
    .pin.pin = GPIO_PIN2,
    .pin.direction = GPIO_DIRECTION_INPUT,
    .src = EXT_INT2,
    .edge = FALLING_EDGE,
    .priority = HIGH_PRIORITY,
    .callback_function = app_isr3};

int main(int argc, char **argv)
{

    STD_ReturnType ret = E_OK;
    ret = Interrupt_INTx_Init(&int0);
    ret = Interrupt_INTx_Init(&int1);
    ret = Interrupt_INTx_Init(&int2);
    ret = led_init(&led);
    ret = led_init(&led2);
    ret = led_init(&led3);
    while (1)
    {
    }

    return (EXIT_SUCCESS);
}
