/* 
 * File:   hal_timer1.c
 * Author: M0rE
 *
 * Created on February 1, 2024, 1:03 PM
 */

#include "hal_timer1.h"
static inline void ModeSelect(const Timer1_t * obj);
static inline void RegSelect(const Timer1_t * obj);
static inline void OscSelect(const Timer1_t * obj);

static uint16_t PreLoadValue = 0;
static void (*TMR1InterruptHandler)(void) = NULL;

void TMR1_ISR() {
    TIMER1_CLEAR_INTERRUPT_FLAG();
    TMR1H = (uint8_t) (PreLoadValue) >> 8;
    TMR1L = (uint8_t) (PreLoadValue);
    if (TMR1InterruptHandler) {
        TMR1InterruptHandler();
    }
}

STD_ReturnType Timer1_Init(const Timer1_t* obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        TIMER1_MODULE_DISABLE();
        ModeSelect(obj);
        TIMER1_PRESCALER_SELECT(obj->PrescalerValue);
        TMR1H = (uint8_t) (obj->PreLoadedValue) >> 8;
        TMR1L = (uint8_t) (obj->PreLoadedValue);
        PreLoadValue = obj->PreLoadedValue;
        RegSelect(obj);
        OscSelect(obj);
#if TIMER1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
        TIMER1_CLEAR_INTERRUPT_FLAG();
        TIMER1_ENABLE_INTERRUPT();
        TMR1InterruptHandler = obj->TMR1_CallBackFun;
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable();
        INTERRUPT_PriorityLevelEnable();
        if (LOW_PRIORITY == obj->priority) {
            TIMER1_SET_LOW_PRIORITY();
        } else if (HIGH_PRIORITY == obj->priority) {
            TIMER1_SET_HIGH_PRIORITY();
        }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripherialInterruptEnable();
#endif

#endif
        TIMER1_MODULE_ENABLE();
    }

    return ret;
}

STD_ReturnType Timer1_Deinit(const Timer1_t* obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        TIMER1_MODULE_DISABLE();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
        TIMER1_DISABLE_INTERRUPT();
#endif
    }

    return ret;
}

STD_ReturnType Timer1_Write_Value(Timer1_t* obj, uint16_t val) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        TMR1H = (uint8_t) (val) >> 8;
        TMR1L = (uint8_t) (val);
        PreLoadValue = val;
        obj->PreLoadedValue = val;
    }

    return ret;
}

STD_ReturnType Timer1_Read_Value(Timer1_t* obj, uint16_t* val) {
    STD_ReturnType ret = E_OK;
    if ((NULL == obj) || (NULL == val)) {
        ret = E_NOT_OK;
    } else {
        uint8_t _lowval = TMR1L;
        uint8_t _highval = TMR1H;

        PreLoadValue = (uint16_t) ((_highval << 8) + _lowval);
        obj->PreLoadedValue = PreLoadValue;
        *val = PreLoadValue;

    }

    return ret;
}

static inline void ModeSelect(const Timer1_t *obj) {
    if (TIMER1_TIMER_MODE_CFG == obj->Mode) {
        TIMER1_INTERNAL_CLK();
    } else if (TIMER1_COUNTER_MODE_CFG == obj->Mode) {
        TIMER1_EXTERNAL_CLK();
        if (TIMER1_ASYNC_COUNTER_CFG == obj->Sync) {
            TIMER1_ASYNC_COUNTER_ON();
        } else if (TIMER1_SYNC_COUNTER_CFG == obj->Sync) {
            TIMER1_SYNC_COUNTER_ON();
        }
    } else {
        /* Nothing*/
    }
}

static inline void RegSelect(const Timer1_t *obj) {
    if (TIMER1_16BIT_CFG == obj->RegSize) {
        TIMER1_16BIT_OP();
    } else if (TIMER1_8BIT_CFG == obj->RegSize) {
        TIMER1_8BIT_OP();
    } else {
        /* Nothing*/
    }
}

static inline void OscSelect(const Timer1_t *obj) {
    if (TIMER1_OSC_ENABLE_CFG == obj->OscMode) {
        TIMER1_OSC_ON();
    } else if (TIMER1_OSC_DISABLE_CFG == obj->OscMode) {
        TIMER1_OSC_OFF();
    } else {
        /* Nothing*/
    }
}

