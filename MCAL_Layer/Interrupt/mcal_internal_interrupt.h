/* 
 * File:   mcal_internal_interrupt.h
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:33 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H


/*  Section : Includes     */
#include "mcal_interrupt_cfg.h"

/*  Section : Macro Declarations     */

/*  Section : Macro Functions Declarations    */

/*---------------------------------------------------       ADC        ---------------------------------------------------------*/
#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define ADC_CLEAR_INTERRUPT_FLAG()  (PIR1bits.ADIF = 0)

#define ADC_ENABLE_INTERRUPT()      (PIE1bits.ADIE = 1)
#define ADC_DISABLE_INTERRUPT()     (PIE1bits.ADIE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define ADC_SET_HIGH_PRIORITY()     (IPR1bits.ADIP = 1)
#define ADC_SET_LOW_PRIORITY()      (IPR1bits.ADIP = 0)

#endif
#endif
/*---------------------------------------------------       ADC        ---------------------------------------------------------*/

/*---------------------------------------------------       TIMER0        ---------------------------------------------------------*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define TIMER0_CLEAR_INTERRUPT_FLAG()  (INTCONbits.TMR0IF = 0)

#define TIMER0_ENABLE_INTERRUPT()      (INTCONbits.TMR0IE = 1)
#define TIMER0_DISABLE_INTERRUPT()     (INTCONbits.TMR0IE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define TIMER0_SET_HIGH_PRIORITY()     (INTCON2bits.TMR0IP = 1)
#define TIMER0_SET_LOW_PRIORITY()      (INTCON2bits.TMR0IP = 0)

#endif
#endif
/*---------------------------------------------------       TIMER0        ---------------------------------------------------------*/

/*---------------------------------------------------       TIMER1        ---------------------------------------------------------*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define TIMER1_CLEAR_INTERRUPT_FLAG()  (PIR1bits.TMR1IF = 0)

#define TIMER1_ENABLE_INTERRUPT()      (PIE1bits.TMR1IE = 1)
#define TIMER1_DISABLE_INTERRUPT()     (PIE1bits.TMR1IE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define TIMER1_SET_HIGH_PRIORITY()     (IPR1bits.TMR1IP = 1)
#define TIMER1_SET_LOW_PRIORITY()      (IPR1bits.TMR1IP = 0)

#endif
#endif
/*---------------------------------------------------       TIMER1        ---------------------------------------------------------*/

/*---------------------------------------------------       TIMER2        ---------------------------------------------------------*/
#if TIMER2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define TIMER2_CLEAR_INTERRUPT_FLAG()  (PIR1bits.TMR2IF = 0)

#define TIMER2_ENABLE_INTERRUPT()      (PIE1bits.TMR2IE = 1)
#define TIMER2_DISABLE_INTERRUPT()     (PIE1bits.TMR2IE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define TIMER2_SET_HIGH_PRIORITY()     (IPR1bits.TMR2IP = 1)
#define TIMER2_SET_LOW_PRIORITY()      (IPR1bits.TMR2IP = 0)

#endif
#endif
/*---------------------------------------------------       TIMER2        ---------------------------------------------------------*/

/*---------------------------------------------------       TIMER3        ---------------------------------------------------------*/
#if TIMER3_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define TIMER3_CLEAR_INTERRUPT_FLAG()  (PIR2bits.TMR3IF = 0)

#define TIMER3_ENABLE_INTERRUPT()      (PIE2bits.TMR3IE = 1)
#define TIMER3_DISABLE_INTERRUPT()     (PIE2bits.TMR3IE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define TIMER3_SET_HIGH_PRIORITY()     (IPR2bits.TMR3IP = 1)
#define TIMER3_SET_LOW_PRIORITY()      (IPR2bits.TMR3IP = 0)

#endif
#endif
/*---------------------------------------------------       TIMER3        ---------------------------------------------------------*/

/*  Section : Data Type Declarations    */

/*  Section : Function Declarations    */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

