/* 
 * File:   mcal_interrupt_manager.h
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:34 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/*  Section : Includes     */
#include "mcal_interrupt_cfg.h"

/*  Section : Macro Declarations     */

/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */

/*  Section : Function Declarations    */

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8_t src);
void RB5_ISR(uint8_t src);
void RB6_ISR(uint8_t src);
void RB7_ISR(uint8_t src);

void ADC_ISR(void);
void TMR0_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

