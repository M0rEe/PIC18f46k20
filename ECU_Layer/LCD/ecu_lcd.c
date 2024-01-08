
/* 
 * File:   ecu_lcd_cfg.c
 * Author: M0rE
 *
 * Created on December 25, 2023, 2:49 PM
 */

#include "ecu_lcd.h"
static STD_ReturnType lcd_4bit_send_data(lcd_4bit_t*lcd, uint8_t command);
static STD_ReturnType lcd_4bit_blink_en(lcd_4bit_t* lcd);
static STD_ReturnType lcd_4bit_set_cursor_At(lcd_4bit_t* lcd, uint8_t row, uint8_t col);


static STD_ReturnType lcd_8bit_blink_en(lcd_8bit_t*lcd);
static STD_ReturnType lcd_8bit_send_data(lcd_8bit_t*lcd, uint8_t command);
static STD_ReturnType lcd_8bit_set_cursor_AT(lcd_8bit_t* lcd, uint8_t row, uint8_t col);

STD_ReturnType lcd_4bit_intialize(const lcd_4bit_t *lcd) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        //Initialize pins 
        gpio_pin_initialize(&(lcd->en));
        gpio_pin_initialize(&(lcd->rs));
        uint8_t i;
        for (i = 0; i < 4; i++) {
            gpio_pin_initialize(&(lcd->data_pin[i]));
        }
        __delay_ms(20);
        //send commands first to  pins 
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, 0x80);
        ret = lcd_4bit_set_cursor_At(lcd,1,1);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd, uint8_t command) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        //select register to be written on 
        ret = gpio_pin_write_logic(&(lcd->rs), GPIO_LOW);
        //send higher nibble command on pins 4 first
        ret = lcd_4bit_send_data(lcd, (command >> 4));
        //toggle  en 1-> 0 
        ret = lcd_4bit_blink_en(lcd);
        //send lower nibble command on pins 4 
        ret = lcd_4bit_send_data(lcd, (command));
        //toggle  en 1-> 0 
        ret = lcd_4bit_blink_en(lcd);

    }
    return ret;
}

STD_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t *lcd, uint8_t data) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->rs), GPIO_HIGH);
        //send higher nibble of data on pins 4 
        ret = lcd_4bit_send_data(lcd, (data >> 4));
        //toggle  en 1-> 0 
        ret = lcd_4bit_blink_en(lcd);
        //send lower nibble of data on pins 4 
        ret = lcd_4bit_send_data(lcd, (data));
        //toggle  en 1-> 0 
        ret = lcd_4bit_blink_en(lcd);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bit_t *lcd, uint8_t row, uint8_t column, uint8_t data) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_4bit_set_cursor_At(lcd, row, column);
        ret = lcd_4bit_send_char_data(lcd, data);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        while (*str) {
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_4bit_set_cursor_At(lcd, row, column);
        while (*str) {
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd, uint8_t row, uint8_t column,
        const uint8_t _chr[], uint8_t mem_pos) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_4bit_send_command(lcd, (_LCD_CGRAM_START + (mem_pos * 8)));
        uint8_t i;
        for (i = 0; i < 8; i++) {
            ret = lcd_4bit_send_char_data(lcd, _chr[i]);
        }
        ret = lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
    }
    return ret;
}

STD_ReturnType lcd_8bit_intialize(const lcd_8bit_t *lcd) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        //Initialize pins 
        gpio_pin_initialize(&(lcd->en));
        gpio_pin_initialize(&(lcd->rs));
        uint8_t i;
        for (i = 0; i < 8; i++) {
            gpio_pin_initialize(&(lcd->data_pin[i]));
        }
        __delay_ms(20);
        //send commands first to  pins 
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, 0x80);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8_t command) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->rs), GPIO_LOW);

        ret = lcd_8bit_send_data(lcd, command);
        ret = lcd_8bit_blink_en(lcd);

    }
    return ret;
}

STD_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t *lcd, uint8_t data) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->rs), GPIO_HIGH);

        ret = lcd_8bit_send_data(lcd, data);
        ret = lcd_8bit_blink_en(lcd);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bit_t *lcd, uint8_t row, uint8_t column, uint8_t data) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_8bit_set_cursor_AT(lcd, row, column);
        ret = lcd_8bit_send_char_data(lcd, data);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if ((NULL == lcd) || (NULL == str)) {
        ret = E_NOT_OK;

    } else {
        while (*str) {
            ret = lcd_8bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if ((NULL == lcd) || (NULL == str)) {
        ret = E_NOT_OK;

    } else {
        ret = lcd_8bit_set_cursor_AT(lcd, row, column);
        ret = lcd_8bit_send_string(lcd, str);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd, uint8_t row, uint8_t column,
        const uint8_t _chr[], uint8_t mem_pos) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;

    } else {
        ret = lcd_8bit_send_command(lcd, (_LCD_CGRAM_START + (mem_pos * 8)));
        uint8_t i;
        for (i = 0; i < 8; i++) {
            ret = lcd_8bit_send_char_data(lcd, _chr[i]);
        }
        ret = lcd_8bit_send_char_data_pos(lcd, row, column, mem_pos);


    }
    return ret;
}

STD_ReturnType convert_uint8_to_string(uint8_t value, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        memset((char*) str, '\0', 4);
        sprintf(str, "%i", value);
    }
    return ret;
}

STD_ReturnType convert_uint16_to_string(uint16_t value, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        memset((char*) str, '\0', 5);
        sprintf(str, "%i", value);
    }
    return ret;
}

STD_ReturnType convert_uint32_to_string(uint32_t value, uint8_t *str) {
    STD_ReturnType ret = E_OK;

    if (NULL == str) {
        ret = E_NOT_OK;

    } else {
        memset((char*) str, '\0', 11);
        sprintf(str, "%i", value);
    }
    return ret;
}

static STD_ReturnType lcd_4bit_send_data(lcd_4bit_t*lcd, uint8_t command) {

    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        uint8_t i;
        for (i = 0; i < 4; i++) {
            ret = gpio_pin_write_logic(&(lcd->data_pin[i]), (command >> i)&(uint8_t) (0x01));
        }
    }
    return ret;
}

static STD_ReturnType lcd_4bit_blink_en(lcd_4bit_t*lcd) {

    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->en), GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->en), GPIO_LOW);
    }
    return ret;
}

static STD_ReturnType lcd_4bit_set_cursor_At(lcd_4bit_t*lcd, uint8_t row, uint8_t col) {

    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        switch (row) {
            case ROW1:
                ret = lcd_4bit_send_command(lcd, (0x80 + col));
                break;

            case ROW2:
                ret = lcd_4bit_send_command(lcd, (0xc0 + col));
                break;

            case ROW3:
                ret = lcd_4bit_send_command(lcd, (0x94 + col));
                break;

            case ROW4:
                ret = lcd_4bit_send_command(lcd, (0xd4 + col));
                break;
            default: break;

        }
    }
    return ret;
}

static STD_ReturnType lcd_8bit_send_data(lcd_8bit_t*lcd, uint8_t command) {

    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        uint8_t i;
        for (i = 0; i < 8; i++) {
            ret = gpio_pin_write_logic(&(lcd->data_pin[i]), (command >> i)&(uint8_t) (0x01));
        }
    }
    return ret;
}

static STD_ReturnType lcd_8bit_blink_en(lcd_8bit_t*lcd) {
    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->en), GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->en), GPIO_LOW);
    }
    return ret;
}

static STD_ReturnType lcd_8bit_set_cursor_AT(lcd_8bit_t* lcd, uint8_t row, uint8_t col) {

    STD_ReturnType ret = E_OK;

    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        switch (row) {
            case ROW1:
                ret = lcd_8bit_send_command(lcd, (0x80 + col));
                break;

            case ROW2:
                ret = lcd_8bit_send_command(lcd, (0xc0 + col));
                break;

            case ROW3:
                ret = lcd_8bit_send_command(lcd, (0x94 + col));
                break;

            case ROW4:
                ret = lcd_8bit_send_command(lcd, (0xd4 + col));
                break;
            default: break;

        }
    }
    return ret;
}