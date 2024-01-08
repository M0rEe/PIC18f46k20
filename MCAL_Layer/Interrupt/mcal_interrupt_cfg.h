/* 
 * File:   mcal_interrupt_cfg.h
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:34 PM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H


/*  Section : Includes     */

#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "mcal_interrupt_gen_cfg.h"

/*  Section : Macro Declarations     */

#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0
#define INTERRUPT_OCCURE            1
#define INTERRUPT_NOT_OCCURE        0
#define INTERRUPT_PRIORITY_ENABLE   1
#define INTERRUPT_PRIORITY_DISABLE  0


/*  Section : Macro Functions Declarations    */
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

#define INTERRUPT_PriorityLevelEnable()             (RCONbits.IPEN = 1)
#define INTERRUPT_PriorityLevelDisable()            (RCONbits.IPEN = 0)

#define  INTERRUPT_GlobalInterruptHighEnable()      (INTCONbits.GIEH = 1) 
#define  INTERRUPT_GlobalInterruptHighDisable()     (INTCONbits.GIEH = 0)

#define  INTERRUPT_GlobalInterruptLowEnable()       (INTCONbits.GIEL = 1)
#define  INTERRUPT_GlobalInterruptLowDisable()      (INTCONbits.GIEL = 0)

#else

#define  INTERRUPT_GlobalInterruptEnable()          (INTCONbits.GIE = 1) 
#define  INTERRUPT_GlobalInterruptDisable()         (INTCONbits.GIE = 0)

#define  INTERRUPT_PeripherialInterruptEnable()     (INTCONbits.PEIE = 1)
#define  INTERRUPT_PeripherialInterruptDisable()    (INTCONbits.PEIE = 0)

#endif

/*  Section : Data Type Declarations    */
typedef enum {
    LOW_PRIORITY=0,
    HIGH_PRIORITY
}interrupt_priority_cfg;
/*  Section : Function Declarations    */



#endif	/* MCAL_INTERRUPT_CFG_H */

