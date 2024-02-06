/* 
 * File:   hal_timer2.h
 * Author: Om562
 *
 * Created on February 6, 2024, 8:45 PM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H


/*  Section : Includes    */

#include "../GPIO/hal_gpio.h"
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*  Section : Macro Declarations     */

#define TIMER2_POSTSCALER_DIV_BY_1              0
#define TIMER2_POSTSCALER_DIV_BY_2              1
#define TIMER2_POSTSCALER_DIV_BY_3              2
#define TIMER2_POSTSCALER_DIV_BY_4              3
#define TIMER2_POSTSCALER_DIV_BY_5              4
#define TIMER2_POSTSCALER_DIV_BY_6              5
#define TIMER2_POSTSCALER_DIV_BY_7              6
#define TIMER2_POSTSCALER_DIV_BY_8              7
#define TIMER2_POSTSCALER_DIV_BY_9              8
#define TIMER2_POSTSCALER_DIV_BY_10             9
#define TIMER2_POSTSCALER_DIV_BY_11             10
#define TIMER2_POSTSCALER_DIV_BY_12             11
#define TIMER2_POSTSCALER_DIV_BY_13             12
#define TIMER2_POSTSCALER_DIV_BY_14             13
#define TIMER2_POSTSCALER_DIV_BY_15             14
#define TIMER2_POSTSCALER_DIV_BY_16             15


#define TIMER2_PRESCALER_DIV_BY_1                0
#define TIMER2_PRESCALER_DIV_BY_4                1
#define TIMER2_PRESCALER_DIV_BY_16               2


/*  Section : Macro Functions Declarations    */

#define TIMER2_MODULE_ON()                      (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_OFF()                     (T2CONbits.TMR2ON = 0)

#define TIMER2_PRESCALER_SELECT(_preScaler_)    (T2CONbits.T2CKPS = _preScaler_)
#define TIMER2_POSTSCALER_SELECT(_postScaler_)  (T2CONbits.TOUTPS = _postScaler_)


/*  Section : Data Type Declarations    */
typedef struct {
#if TIMER2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
    void (*tmr2CallBack)(void);
    interrupt_priority_cfg priority;
#endif
    uint8_t preLoadedValue;
    uint8_t postScalerValue :4;
    uint8_t preScalerValue :2;
    uint8_t Resserved :2;
}Timer2_t;
/*  Section : Function Declarations    */
STD_ReturnType Timer2_Init(const Timer2_t* obj);
STD_ReturnType Timer2_DeInit(const Timer2_t* obj);
STD_ReturnType Timer2_ReadValue(const Timer2_t* obj,uint8_t * val);
STD_ReturnType Timer2_WriteValue(Timer2_t* obj,uint8_t val);

#endif	/* HAL_TIMER2_H */

