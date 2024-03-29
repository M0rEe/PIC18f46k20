
/* 
 * File:   hal_timer0.h
 * Author: M0rE
 *
 * Created on January 25, 2024, 3:06 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/*  Section : Includes    */
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*  Section : Macro Declarations     */
#define TIMER0_TIMER_MODE_CFG                    1
#define TIMER0_COUNTER_MODE_CFG                  0

#define TIMER0_PRESCALER_ENABLE_CFG              1
#define TIMER0_PRESCALER_DISABLE_CFG             0

#define TIMER0_REGISTER_8BIT_CFG                 1
#define TIMER0_REGISTER_16BIT_CFG                0

#define TIMER0_RISING_EDGE_CFG                   1
#define TIMER0_FALLING_EDGE_CFG                  0


/*  Section : Macro Functions Declarations    */
#define TIMER0_PRESCALER_ENABLE()                   (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE()                  (T0CONbits.PSA = 1)

#define TIMER0_RISING_EDGE_ENABLE()                 (T0CONbits.T0SE = 0)
#define TIMER0_FALLING_EDGE_ENABLE()                (T0CONbits.T0SE = 1)

#define TIMER0_TIMER_MODE_ENABLE()                  (T0CONbits.T0CS = 0) 
#define TIMER0_COUNTER_MODE_ENABLE()                (T0CONbits.T0CS = 1) 

#define TIMER0_8BIT_MODE()                          (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_MODE()                         (T0CONbits.T08BIT = 0)

#define TIMER0_MODULE_ENABLE()                      (T0CONbits.TMR0ON = 1)
#define TIMER0_MODULE_DISABLE()                     (T0CONbits.TMR0ON = 0)

/*  Section : Data Type Declarations    */

typedef enum {
    TIMER0_PRESCALER_BY_2=0,
    TIMER0_PRESCALER_BY_4,
    TIMER0_PRESCALER_BY_8,
    TIMER0_PRESCALER_BY_16,
    TIMER0_PRESCALER_BY_32,
    TIMER0_PRESCALER_BY_64,
    TIMER0_PRESCALER_BY_128,
    TIMER0_PRESCALER_BY_256
} timer0_prescaler_select_t;

typedef struct {
#if TIMER0_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
    void (*TIMR0_CallBack)(void);
    interrupt_priority_cfg priority ;
#endif
    timer0_prescaler_select_t prescalerValue;
    uint16_t preloadedValue;
    uint8_t prescalerEnable : 1;
    uint8_t counterEdge : 1;
    uint8_t mode : 1;
    uint8_t regSize : 1;
    uint8_t Reserved :4;
} timer0_t;
/*  Section : Function Declarations    */
STD_ReturnType timer0_Init(const timer0_t* obj);
STD_ReturnType timer0_Deinit(const timer0_t* obj);

STD_ReturnType timer0_Write_Value(const timer0_t* obj, uint16_t val);
STD_ReturnType timer0_Read_Value(const timer0_t* obj, uint16_t* val);


#endif	/* HAL_TIMER0_H */
