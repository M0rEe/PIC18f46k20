/* 
 * File:   ecu_lcd.h
 * Author: M0rE
 *
 * Created on December 25, 2023, 2:50 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*  Section : Includes     */

#include "ecu_lcd_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*  Section : Macro Declarations     */
#define _LCD_CLEAR                                  0X01
#define _LCD_RETURN_HOME                            0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF               0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF               0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                 0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                0x14
#define _LCD_DISPLAY_SHIFT_LEFT                     0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                    0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF                 0x08
#define _LCD_8BIT_MODE_2_LINE                       0x38
#define _LCD_4BIT_MODE_2_LINE                       0x28

#define _LCD_CGRAM_START                            0x40
#define _LCD_DDRAM_START                            0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef struct{
    pin_config_t rs;
    pin_config_t en;
    pin_config_t data_pin[4];
}lcd_4bit_t;

typedef struct{
    pin_config_t rs;
    pin_config_t en;
    pin_config_t data_pin[8];
}lcd_8bit_t;
/*  Section : Function Declarations    */
STD_ReturnType lcd_4bit_intialize(const lcd_4bit_t *lcd);
STD_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd, uint8_t command);
STD_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t *lcd, uint8_t data);
STD_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bit_t *lcd,uint8_t row, uint8_t column, uint8_t data);
STD_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd, uint8_t *str);
STD_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str);
STD_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd, uint8_t row, uint8_t column, 
                                         const uint8_t _chr[], uint8_t mem_pos);

STD_ReturnType lcd_8bit_intialize(const lcd_8bit_t *lcd);
STD_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8_t command);
STD_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t *lcd, uint8_t data);
STD_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bit_t *lcd,uint8_t row, uint8_t column, uint8_t data);
STD_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8_t *str);
STD_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str);
STD_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd, uint8_t row, uint8_t column, 
                                         const uint8_t _chr[], uint8_t mem_pos);

STD_ReturnType convert_uint8_to_string(uint8_t value, uint8_t *str);
STD_ReturnType convert_uint16_to_string(uint16_t value, uint8_t *str);
STD_ReturnType convert_uint32_to_string(uint32_t value, uint8_t *str);


#endif	/* ECU_LCD_H */

