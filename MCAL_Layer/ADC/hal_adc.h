/* 
 * File:   hal_adc.h
 * Author: M0rE
 *
 * Created on January 20, 2024, 2:51 PM
 */
#ifndef HAL_ADC_H
#define	HAL_ADC_H

/*  Section : Includes    */
#include "hal_adc_cfg.h"
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"

/*  Section : Macro Declarations     */

#define ADC_UP_TO_AN0_ENABLED       0x0E
#define ADC_UP_TO_AN1_ENABLED       0x0D
#define ADC_UP_TO_AN2_ENABLED       0x0C
#define ADC_UP_TO_AN3_ENABLED       0x0B
#define ADC_UP_TO_AN4_ENABLED       0x0A
#define ADC_UP_TO_AN5_ENABLED       0x09
#define ADC_UP_TO_AN6_ENABLED       0x08
#define ADC_UP_TO_AN7_ENABLED       0x07
#define ADC_UP_TO_AN8_ENABLED       0x06
#define ADC_UP_TO_AN9_ENABLED       0x05
#define ADC_UP_TO_AN10_ENABLED      0x04
#define ADC_UP_TO_AN11_ENABLED      0x03
#define ADC_UP_TO_AN12_ENABLED      0x02
#define ADC_ALL_CH_ENABLED          0x00
#define ADC_ALL_CH_DISABLED         0x0F

#define ADC_CONVERSION_COMPLETED        0x01U
#define ADC_CONVERSION_NOT_COMPLETED    0x00U


/*  Section : Macro Functions Declarations    */
#define ADC_CONVERSTION_STATS()               (ADCON0bits.GO_nDONE)

#define ADC_START_CONVERSION()                (ADCON0bits.GODONE = 1)

#define ADC_CONVERTER_ENABLE()                (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE()               (ADCON0bits.ADON = 0)

#define ADC_ENABLE_VOLTAGE_REF()              (ADCON1bits.VCFG0 = 1, \
                                                ADCON1bits.VCFG1 = 1) 

#define ADC_DISABLE_VOLTAGE_REF()             (ADCON1bits.VCFG0 = 0, \
                                                ADCON1bits.VCFG1 = 0) 

#define ADC_AD_PORT_CONFIG(_cfg)              (ADCON1bits.PCFG = _cfg)

#define ADC_LEFT_ADJUST()                     (ADCON2bits.ADFM = 0)
#define ADC_RIGHT_ADJUST()                    (ADCON2bits.ADFM = 1)

#define ADC_ACQ_TIME_SELECT(_cfg)             (ADCON2bits.ACQT = _cfg)

#define LEFT_ADJUST                            0x00U
#define RIGHT_ADJUST                           0x01U

#define ADC_VREF_ENABLE                        0x01U
#define ADC_VREF_DISABLE                       0x00U

/*  Section : Data Type Declarations    */

typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
} ADC_CHANNELS_SELECT_t;

typedef enum {
    ADC_0TAD = 0,
    ADC_2TAD,
    ADC_4TAD,
    ADC_6TAD,
    ADC_8TAD,
    ADC_12TAD,
    ADC_16TAD,
    ADC_20TAD,
} ADC_ACQ_TIME_t;

typedef enum {
    FoscBy2 = 0,
    FoscBy8,
    FoscBy32,
    Frc,
    FoscBy4,
    FoscBy16,
    FoscBy64,

} ADC_CONVERSION_CLOCK_t;

typedef struct {
#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED
    void (*ADC_CallBack)(void);
    interrupt_priority_cfg priority;
#endif
    ADC_ACQ_TIME_t aqcTime;
    ADC_CONVERSION_CLOCK_t clk;
    ADC_CHANNELS_SELECT_t ch;
    uint8_t ADC_LR_ADJUST : 1;
    uint8_t ADC_Vref : 1;
    uint8_t Reserved : 6;
} ADC_conf_t;

/*  Section : Function Declarations    */
STD_ReturnType ADC_INIT(const ADC_conf_t * obj);
STD_ReturnType ADC_DEINIT(const ADC_conf_t * obj);

STD_ReturnType ADC_SelectChannnel( ADC_conf_t * obj, ADC_CHANNELS_SELECT_t channel);
STD_ReturnType ADC_StartConversion(const ADC_conf_t * obj);
STD_ReturnType ADC_IsConversionDone(const ADC_conf_t * obj, uint8_t * state);
STD_ReturnType ADC_GetConversionRes(const ADC_conf_t * obj, uint16_t* res);
STD_ReturnType ADC_GetResFrom(const ADC_conf_t * obj,ADC_CHANNELS_SELECT_t channel ,uint16_t* res);
STD_ReturnType ADC_GetFrom_NON_BLOCKING(const ADC_conf_t * obj,ADC_CHANNELS_SELECT_t channel );

#endif	/* HAL_ADC_H */

