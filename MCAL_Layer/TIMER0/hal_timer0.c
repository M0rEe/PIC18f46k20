/* 
 * File:   hal_timer0.c
 * Author: M0rE
 *
 * Created on January 25, 2024, 3:06 PM
 */

#include "hal_timer0.h"
static inline void preScalerConfig(const timer0_t* obj);
static inline void modeSelect(const timer0_t* obj);
static inline void regSelectSize(const timer0_t* obj);

#if TIMER0_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
static void (*Handler)(void) = NULL;
#endif

static uint16_t timer0PreloadValue = 0;

void TMR0_ISR()
{
	TIMER0_CLEAR_INTERRUPT_FLAG();
	TMR0H = (uint8_t) ((timer0PreloadValue) >> 8);
	TMR0L = (uint8_t) (timer0PreloadValue);
	if (Handler)
		Handler();
}

STD_ReturnType timer0_Init(const timer0_t* obj)
{
	STD_ReturnType ret = E_OK;
	if ((NULL == obj)) {
		ret = E_NOT_OK;
	} else {
		TIMER0_MODULE_DISABLE();
		preScalerConfig(obj);
		modeSelect(obj);
		regSelectSize(obj);
		TMR0H = (uint8_t) ((obj->preloadedValue) >> 8);
		TMR0L = (uint8_t) (obj->preloadedValue);
		timer0PreloadValue = obj->preloadedValue;
#if TIMER0_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
		TIMER0_CLEAR_INTERRUPT_FLAG();
		TIMER0_ENABLE_INTERRUPT();
		Handler = obj->callBack;
#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED
		INTERRUPT_GlobalInterruptHighEnable();
		INTERRUPT_GlobalInterruptLowEnable();
		INTERRUPT_PriorityLevelEnable();
		if (HIGH_PRIORITY == obj->priority) {
			TIMER0_SET_HIGH_PRIORITY();
		} else if (LOW_PRIORITY == obj->priority) {
			TIMER0_SET_LOW_PRIORITY();
		} else {
			/*Nothing*/
		}
#else
		INTERRUPT_GlobalInterruptEnable();
		INTERRUPT_PeripherialInterruptEnable();
#endif	

#endif
		TIMER0_MODULE_ENABLE();
	}
	return ret;
}

STD_ReturnType timer0_Deinit(const timer0_t* obj)
{
	STD_ReturnType ret = E_OK;
	if ((NULL == obj)) {
		ret = E_NOT_OK;
	} else {
		TIMER0_MODULE_DISABLE();
#if TIMER0_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
		TIMER0_DISABLE_INTERRUPT();
#endif
	}
	return ret;
}

STD_ReturnType timer0_Write_Value(const timer0_t* obj, uint16_t val)
{
	STD_ReturnType ret = E_OK;
	if ((NULL == obj)) {
		ret = E_NOT_OK;
	} else {
		timer0PreloadValue = val;
		TMR0H = (uint8_t) ((val) >> 8);
		TMR0L = (uint8_t) (val);
	}
	return ret;
}

STD_ReturnType timer0_Read_Value(const timer0_t* obj, uint16_t* val)
{
	STD_ReturnType ret = E_OK;
	if ((NULL == obj) || (NULL == val)) {
		ret = E_NOT_OK;
	} else {
		uint8_t l_lowValue = 0, l_highValue = 0;
		l_lowValue = TMR0L;
		l_highValue = TMR0H;
		*val = (uint16_t) ((l_highValue << 8) + l_lowValue);
	}
	return ret;
}

static inline void preScalerConfig(const timer0_t* obj)
{
	if (TIMER0_PRESCALER_ENABLE_CFG == obj->prescalerEnable) {
		TIMER0_PRESCALER_DISABLE();
		T0CONbits.T0PS = obj->prescalerValue;
	} else if (TIMER0_PRESCALER_DISABLE_CFG == obj->prescalerEnable) {
		TIMER0_PRESCALER_DISABLE();
	} else {
		/*Noting */
	}
}

static inline void modeSelect(const timer0_t* obj)
{
	if (TIMER0_COUNTER_MODE_CFG == obj->mode) {
		TIMER0_COUNTER_MODE_ENABLE();
		if (TIMER0_FALLING_EDGE_CFG == obj->counterEdge) {
			TIMER0_FALLING_EDGE_ENABLE();
		} else if (TIMER0_RISING_EDGE_CFG == obj->counterEdge) {
			TIMER0_RISING_EDGE_ENABLE();
		} else {
			/*Nothing*/
		}
	} else if (TIMER0_TIMER_MODE_CFG == obj->mode) {
		TIMER0_TIMER_MODE_ENABLE();
	} else {
		/*Noting */
	}
}

static inline void regSelectSize(const timer0_t* obj)
{
	if (TIMER0_REGISTER_8BIT_CFG == obj->regSize) {
		TIMER0_8BIT_MODE();
	} else if (TIMER0_REGISTER_16BIT_CFG == obj->regSize) {
		TIMER0_16BIT_MODE();
	} else {
		/*Nothing*/
	}
}