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
#if ADC_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLED

#define ADC_CLEAR_INTERRUPT_FLAG()  (PIR1bits.ADIF = 0)

#define ADC_ENABLE_INTERRUPT()      (PIE1bits.ADIE = 1)
#define ADC_DISABLE_INTERRUPT()     (PIE1bits.ADIE = 0)

#if INTERRUPT_PRIORITY_LEVELS  == FEATURE_ENABLED

#define ADC_SET_HIGH_PRIORITY()     (IPR1bits.ADIP = 1)
#define ADC_SET_LOW_PRIORITY()      (IPR1bits.ADIP = 0)

#endif

#endif
/*  Section : Data Type Declarations    */

/*  Section : Function Declarations    */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

