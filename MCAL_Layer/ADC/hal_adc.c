/* 
 * File:   hal_adc.c
 * Author: M0rE
 *
 * Created on January 20, 2024, 2:51 PM
 */
#include "hal_adc.h"
static inline void ADC_CHANNEL_PIN_CONFIGURE(ADC_conf_t * obj);
static inline void ADC_RESULT_ADJUST(ADC_conf_t * obj);
static inline void ADC_VOLTAGE_REFRECE_CONFIGURE(ADC_conf_t * obj);

#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

static void (*ADC_CALLBACK)(void) = NULL;

#endif

STD_ReturnType ADC_INIT(const ADC_conf_t * obj)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj) {
		ret = E_NOT_OK;
	} else {
		/*disable*/
		ADC_CONVERTER_DISABLE();

		/*configure acq time*/
		ADCON2bits.ACQT = obj->aqcTime;
		/*configure conversion clk*/
		ADCON2bits.ADCS = obj->clk;
		/*configure defult channel*/
		ADCON0bits.CHS = obj->ch;
		ADC_CHANNEL_PIN_CONFIGURE(obj);
		/*configure interrupt*/

#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
		ADC_ENABLE_INTERRUPT();
		ADC_CLEAR_INTERRUPT_FLAG();
#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED
		INTERRUPT_GlobalInterruptHighEnable();
		INTERRUPT_GlobalInterruptLowEnable();

		if (HIGH_PRIORITY == obj->priority) {
			ADC_SET_HIGH_PRIORITY();
		} else if (LOW_PRIORITY == obj->priority) {
			ADC_SET_LOW_PRIORITY();
		} else {
			/*Nothing*/
		}
#else
		INTERRUPT_GlobalInterruptEnable();
		INTERRUPT_PeripherialInterruptEnable();

#endif	
		ADC_CALLBACK = obj->ADC_CallBack;
#endif
		/*configure result format*/
		ADC_RESULT_ADJUST(obj);
		/*configure vref*/
		ADC_VOLTAGE_REFRECE_CONFIGURE(obj);

		/*enable*/
		ADC_CONVERTER_ENABLE();
	}
	return ret;
}

STD_ReturnType ADC_DEINIT(const ADC_conf_t * obj)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj) {
		ret = E_NOT_OK;
	} else {
		/*disable module*/
		ADC_CONVERTER_DISABLE();
		/*disable interrupt*/
#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
		ADC_DISABLE_INTERRUPT();
#endif
	}
	return ret;
}

STD_ReturnType ADC_SelectChannnel(ADC_conf_t * obj, ADC_CHANNELS_SELECT_t channel)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj) {
		ret = E_NOT_OK;
	} else {
		ADCON0bits.CHS = channel;
		obj->ch = channel;
		ADC_CHANNEL_PIN_CONFIGURE(obj);
	}
	return ret;
}

STD_ReturnType ADC_StartConversion(const ADC_conf_t * obj)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj) {
		ret = E_NOT_OK;
	} else {
		ADC_START_CONVERSION();
	}
	return ret;
}

STD_ReturnType ADC_IsConversionDone(const ADC_conf_t * obj, uint8_t * state)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj || NULL == state) {
		ret = E_NOT_OK;
	} else {
		*state = (uint8_t)!(ADC_CONVERSTION_STATS());
	}
	return ret;
}

STD_ReturnType ADC_GetConversionRes(const ADC_conf_t * obj, uint16_t* res)
{
	STD_ReturnType ret = E_OK;

	if ((NULL == obj) || (NULL == res)) {
		ret = E_NOT_OK;
	} else {
		if (obj->ADC_LR_ADJUST == LEFT_ADJUST) {
			*res = (uint16_t) (((ADRESH << 8) + ADRESL) >> 6);
		} else if (obj->ADC_LR_ADJUST == RIGHT_ADJUST) {
			*res = (uint16_t) ((ADRESH << 8) + ADRESL);
		} else {
			*res = (uint16_t) ((ADRESH << 8) + ADRESL);
		}
	}
	return ret;
}

STD_ReturnType ADC_GetResFrom(const ADC_conf_t * obj, ADC_CHANNELS_SELECT_t channel, uint16_t* res)
{
	STD_ReturnType ret = E_OK;

	if ((NULL == obj) || (NULL == res)) {
		ret = E_NOT_OK;
	} else {
		ret &= ADC_SelectChannnel(obj, channel);
		ret &= ADC_StartConversion(obj);
		while (ADCON0bits.GO_nDONE);
		ret &= ADC_GetConversionRes(obj, res);

	}
	return ret;
}

STD_ReturnType ADC_GetFrom_NON_BLOCKING(const ADC_conf_t * obj, ADC_CHANNELS_SELECT_t channel)
{
	STD_ReturnType ret = E_OK;

	if (NULL == obj) {
		ret = E_NOT_OK;
	} else {
		ret &= ADC_SelectChannnel(obj, channel);
		ret &= ADC_StartConversion(obj);


	}
	return ret;
}

static inline void ADC_CHANNEL_PIN_CONFIGURE(ADC_conf_t * obj)
{
	switch (obj->ch) {
	case ADC_CHANNEL_AN0:SET_BIT(TRISA, _TRISA_RA0_POSN);
		break;
	case ADC_CHANNEL_AN1:SET_BIT(TRISA, _TRISA_RA1_POSN);
		break;
	case ADC_CHANNEL_AN2:SET_BIT(TRISA, _TRISA_RA2_POSN);
		break;
	case ADC_CHANNEL_AN3:SET_BIT(TRISA, _TRISA_RA3_POSN);
		break;
	case ADC_CHANNEL_AN4:SET_BIT(TRISA, _TRISA_RA5_POSN);
		break;
	case ADC_CHANNEL_AN5:SET_BIT(TRISE, _TRISE_RE0_POSN);
		break;
	case ADC_CHANNEL_AN6:SET_BIT(TRISE, _TRISE_RE1_POSN);
		break;
	case ADC_CHANNEL_AN7:SET_BIT(TRISE, _TRISE_RE2_POSN);
		break;
	case ADC_CHANNEL_AN8:SET_BIT(TRISB, _TRISB_RB2_POSN);
		break;
	case ADC_CHANNEL_AN9:SET_BIT(TRISB, _TRISB_RB3_POSN);
		break;
	case ADC_CHANNEL_AN10:SET_BIT(TRISB, _TRISB_RB1_POSN);
		break;
	case ADC_CHANNEL_AN11:SET_BIT(TRISB, _TRISB_RB4_POSN);
		break;
	case ADC_CHANNEL_AN12:SET_BIT(TRISB, _TRISB_RB0_POSN);
		break;
	};
}

static inline void ADC_RESULT_ADJUST(ADC_conf_t * obj)
{
	if (obj->ADC_LR_ADJUST == LEFT_ADJUST) {
		ADC_LEFT_ADJUST();
	} else if (obj->ADC_LR_ADJUST == RIGHT_ADJUST) {
		ADC_RIGHT_ADJUST();
	} else {
		ADC_RIGHT_ADJUST();
	}
}

static inline void ADC_VOLTAGE_REFRECE_CONFIGURE(ADC_conf_t * obj)
{
	if (obj->ADC_Vref == ADC_VREF_ENABLE) {
		ADC_ENABLE_VOLTAGE_REF();
	} else if (obj->ADC_Vref == ADC_VREF_DISABLE) {
		ADC_DISABLE_VOLTAGE_REF();
	} else {
		ADC_DISABLE_VOLTAGE_REF();
	}

}

void ADC_ISR(void)
{
	ADC_CLEAR_INTERRUPT_FLAG();
	if (ADC_CALLBACK)
		ADC_CALLBACK();
}