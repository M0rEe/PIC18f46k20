/*
 * File:   Application.c
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:11 PM
 */

/* testing commit*/

#include "Application.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"

led_t led1 = {
    .port_name = PORTC_INDEX, .led_status = LED_OFF, .pin = GPIO_PIN0
};
uint8_t eeprom_currentval = 0;
uint8_t eeprom_val = 0;

int main(int argc, char **argv) {

    EEPROM_WriteByte(0x110, 0x55);
    led_init(&led1);
    while (1) {
        EEPROM_WriteByte(0x110, eeprom_currentval++);
        __delay_ms(1000);
        EEPROM_ReadByte(0x110,&eeprom_val);
        if (eeprom_val > 5)
            led_on(&led1);
    }

    return (EXIT_SUCCESS);
}
