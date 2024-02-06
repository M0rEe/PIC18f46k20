/* 
 * File:   hal_timer1.h
 * Author: M0rE
 *
 * Created on February 1, 2024, 1:03 PM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/*  Section : Includes    */
#include "../GPIO/hal_gpio.h"
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*  Section : Macro Declarations     */
#define TIMER1_TIMER_MODE_CFG               0
#define TIMER1_COUNTER_MODE_CFG             1

#define TIMER1_SYNC_COUNTER_CFG             0
#define TIMER1_ASYNC_COUNTER_CFG            1

#define TIMER1_OSC_ENABLE_CFG               1
#define TIMER1_OSC_DISABLE_CFG              0

#define TIMER1_OSCILATOR_SRC                1
#define TIMER1_ANOTHER_SRC                  0

#define TIMER1_16BIT_CFG                    1
#define TIMER1_8BIT_CFG                     0

/*  Section : Macro Functions Declarations    */
#define TIMER1_MODULE_ENABLE()                  (T1CONbits.TMR1ON = 1)
#define TIMER1_MODULE_DISABLE()                 (T1CONbits.TMR1ON = 0)

#define TIMER1_INTERNAL_CLK()                   (T1CONbits.TMR1CS = 0)
#define TIMER1_EXTERNAL_CLK()                   (T1CONbits.TMR1CS = 1)

#define TIMER1_SYNC_COUNTER_ON()                (T1CONbits.T1SYNC = 0)
#define TIMER1_ASYNC_COUNTER_ON()               (T1CONbits.T1SYNC = 1)

#define TIMER1_OSC_ON()                         (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_OFF()                        (T1CONbits.T1OSCEN = 0)

#define TIMER1_16BIT_OP()                       (T1CONbits.RD16 = 1)
#define TIMER1_8BIT_OP()                        (T1CONbits.RD16 = 0)

#define TIMER1_PRESCALER_SELECT(_preScaler_)    (T1CONbits.T1CKPS = _preScaler_)
#define TIMER1_CURRENT_CLK_STATUS()             (T1CONbits.T1RUN)

/*  Section : Data Type Declarations    */
typedef enum {
    Timer1_Prescaler_Div_By_1 = 0,
    Timer1_Prescaler_Div_By_2,
    Timer1_Prescaler_Div_By_4,
    Timer1_Prescaler_Div_By_8,
} Timer1_Prescaler_t;

typedef struct {
#if TIMER1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
    void (*TMR1_CallBackFun) (void);
    interrupt_priority_cfg priority;
#endif
    uint16_t PreLoadedValue;
    Timer1_Prescaler_t PrescalerValue;
    uint8_t Mode : 1;
    uint8_t Sync : 1;
    uint8_t OscMode : 1;
    uint8_t RegSize : 1;
    uint8_t Reserved : 4;
} Timer1_t;
/*  Section : Function Declarations    */
STD_ReturnType Timer1_Init(const Timer1_t* obj);
STD_ReturnType Timer1_Deinit(const Timer1_t* obj);

STD_ReturnType Timer1_Write_Value(Timer1_t* obj, uint16_t val);
STD_ReturnType Timer1_Read_Value(Timer1_t* obj, uint16_t* val);

#endif	/* HAL_TIMER1_H */

