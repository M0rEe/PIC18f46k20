/* 
 * File:   hal_gpio.h
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:26 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*  Section : Includes    */
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"

/*  Section : Macro Declarations     */
#define BIT_MASK    0x01  
/*  Section : Macro Functions Declarations    */
#define HWREG8 (_x) (*((volatile uint8_t*)(_x)))
#define SET_BIT(REG,BIT_POS)    (REG |=     (BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)  (REG &=     ~(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS) (REG ^=     (BIT_MASK << BIT_POS))
#define READ_BIT(REG,BIT_POS)   ((REG >> BIT_POS )& BIT_MASK)

/*  Section : Data Type Declarations    */
typedef enum {
    GPIO_LOW =0,
    GPIO_HIGH 
}logic_t;

typedef enum {
    GPIO_DIRECTION_OUTPUT=0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum {
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum {
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct {
    uint8_t port :3;
    uint8_t pin :3;
    uint8_t direction :1;
    uint8_t logic :1;
    
}pin_config_t;


/*  Section : Function Declarations    */


STD_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_config);
STD_ReturnType gpio_pin_initialize(const pin_config_t *pin_config);
STD_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config,direction_t *direction_status );
STD_ReturnType gpio_pin_write_logic( pin_config_t *pin_config,logic_t logic);
STD_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config,logic_t* logic);
STD_ReturnType gpio_pin_toggle_logic( pin_config_t *pin_config);

STD_ReturnType gpio_port_direction_initialize(port_index_t port_num ,uint8_t direction);
STD_ReturnType gpio_port_get_direction_status(port_index_t port_num ,uint8_t *direction_status );
STD_ReturnType gpio_port_write_logic(port_index_t port_num ,uint8_t logic);
STD_ReturnType gpio_port_read_logic(port_index_t port_num ,uint8_t* logic);
STD_ReturnType gpio_port_toggle_logic(port_index_t port_num );



#endif	/* HAL_GPIO_H */

