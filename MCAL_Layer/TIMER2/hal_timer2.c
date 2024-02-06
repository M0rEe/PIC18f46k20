/* 
 * File:   hal_timer2.c
 * Author: Om562
 *
 * Created on February 6, 2024, 8:45 PM
 */
#include "hal_timer2.h"

#if TIMER2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
static void (*timer2_interrupt_handler)(void) = NULL;
#endif
uint8_t preVal = 0;

void TMR2_ISR() {
    TIMER2_CLEAR_INTERRUPT_FLAG();
    TMR2 = preVal;
    if (timer2_interrupt_handler) {
        timer2_interrupt_handler();
    }
}

STD_ReturnType Timer2_Init(const Timer2_t* obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;

    } else {
        TIMER2_MODULE_OFF();

        TIMER2_PRESCALER_SELECT(obj->preScalerValue);
        TIMER2_POSTSCALER_SELECT(obj->postScalerValue);
        preVal = obj->preLoadedValue;
        TMR2 = obj->preLoadedValue;

#if TIMER2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
        TIMER2_CLEAR_INTERRUPT_FLAG();
        TIMER2_ENABLE_INTERRUPT();
        timer2_interrupt_handler = obj->tmr2CallBack;

#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable();
        INTERRUPT_PriorityLevelEnable();
        if (LOW_PRIORITY == obj->priority) {
            TIMER2_SET_LOW_PRIORITY();
        } else if (HIGH_PRIORITY == obj->priority) {
            TIMER2_SET_HIGH_PRIORITY();
        }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripherialInterruptEnable();
#endif 
#endif 
        TIMER2_MODULE_ON();
    }
    return ret;
}

STD_ReturnType Timer2_DeInit(const Timer2_t* obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;

    } else {

#if TIMER2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
        TIMER2_DISABLE_INTERRUPT();
#endif
        TIMER2_MODULE_OFF();
    }
    return ret;
}

STD_ReturnType Timer2_ReadValue(const Timer2_t* obj, uint8_t * val) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;

    } else {
        *val = TMR2;
    }
    return ret;
}

STD_ReturnType Timer2_WriteValue(Timer2_t* obj, uint8_t val) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;

    } else {
        TMR2 = val;
        preVal = val;
    }
    return ret;
}
