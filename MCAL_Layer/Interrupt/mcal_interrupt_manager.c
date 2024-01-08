/* 
 * File:   mcal_interrupt_manager.c
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:34 PM
 */
#include "mcal_interrupt_manager.h"

#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

void __interrupt() InterruptHighPriority() {




}

void __interrupt(low_priority) InterruptLowPriority() {




}

#else

void __interrupt() InterruptManager() {
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCURE)) {
        INT0_ISR();
    } else if ((INTCON3bits.INT1E == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCURE)) {
        INT1_ISR();
    } else if ((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCURE)) {
        INT2_ISR();
    } else {

    }
}

#endif 