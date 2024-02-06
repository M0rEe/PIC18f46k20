/* 
 * File:   mcal_interrupt_manager.c
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:34 PM
 */
#include "mcal_interrupt_manager.h"
uint8_t RB4_Flag = 1;
uint8_t RB5_Flag = 1;
uint8_t RB6_Flag = 1;
uint8_t RB7_Flag = 1;
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

void __interrupt() InterruptHighPriority()
{

	if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCURE)) {
		INT0_ISR();
	}
	if ((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCURE)) {
		INT2_ISR();
	}


}

void __interrupt(low_priority) InterruptLowPriority()
{

	if ((INTCON3bits.INT1E == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCURE)) {
		INT1_ISR();
	}


}

#else

void __interrupt() InterruptManager()
{
	/*--------------------------------------------------------------		EXTERNAL INTERRUPT		--------------------------------------------------------------------*/

	if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCURE)) {
		INT0_ISR();
	}
	if ((INTCON3bits.INT1E == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCURE)) {
		INT1_ISR();
	}
	if ((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCURE)) {
		INT2_ISR();
	}
	/*--------------------------------------------------------------		EXTERNAL INTERRUPT		--------------------------------------------------------------------*/


	/*--------------------------------------------------------------		EXTERNAL INTERRUPT		--------------------------------------------------------------------*/

	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB4 == 1) &&(RB4_Flag == 1)) {
		RB4_Flag = 0;
		RB4_ISR(1);
	}
	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB4 == 0) &&(RB4_Flag == 0)) {
		RB4_Flag = 1;
		RB4_ISR(0);
	}
	/*----------------------*/
	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB5 == 1) &&(RB5_Flag == 1)) {
		RB5_Flag = 0;
		RB5_ISR(1);
	}
	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB5 == 0) &&(RB5_Flag == 0)) {
		RB5_Flag = 1;
		RB5_ISR(0);
	}
	/*----------------------*/

	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB6 == 1) &&(RB6_Flag == 1)) {
		RB6_Flag = 0;
		RB6_ISR(1);
	}
	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB6 == 0) &&(RB6_Flag == 0)) {
		RB6_Flag = 1;
		RB6_ISR(0);
	}
	/*----------------------*/

	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB7 == 1) &&(RB7_Flag == 1)) {
		RB7_Flag = 0;
		RB7_ISR(1);
	}
	if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCURE) && (PORTBbits.RB7 == 0) &&(RB7_Flag == 0)) {
		RB7_Flag = 1;
		RB7_ISR(0);
	}
	/*--------------------------------------------------------------		EXTERNAL INTERRUPT		--------------------------------------------------------------------*/

	/*--------------------------------------------------------------		ADC INTERRUPT		--------------------------------------------------------------------*/
	if ((PIE1bits.ADIE == INTERRUPT_ENABLE) && (PIR1bits.ADIF == INTERRUPT_OCCURE)) {
		ADC_ISR();
	}
	/*--------------------------------------------------------------		ADC INTERRUPT		--------------------------------------------------------------------*/

	/*--------------------------------------------------------------		TIMERs INTERRUPT		--------------------------------------------------------------------*/
	if ((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCURE)) {
		TMR0_ISR();
	}
    
	if ((PIE1bits.TMR1IE == INTERRUPT_ENABLE) && (PIR1bits.TMR1IF == INTERRUPT_OCCURE)) {
		TMR1_ISR();
	}
	
    if ((PIE1bits.TMR2IE == INTERRUPT_ENABLE) && (PIR1bits.TMR2IF == INTERRUPT_OCCURE)) {
		TMR2_ISR();
	}
    
	/*--------------------------------------------------------------		TIMERs INTERRUPT		--------------------------------------------------------------------*/


}

#endif 