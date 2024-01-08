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

#define INTERRUPT_PriorityLevelEnable()             (RCONbits_t.IPEN = 1)
#define INTERRUPT_PriorityLevelDisable()            (RCONbits_t.IPEN = 0)

#define  INTERRUPT_GlobalInterruptHighEnable()      (INTCONbits_t.GIEH = 1) 
#define  INTERRUPT_GlobalInterruptHighDisable()     (INTCONbits_t.GIEH = 0)

#define  INTERRUPT_GlobalInterruptLowEnable()       (INTCONbits_t.GIEL = 1)
#define  INTERRUPT_GlobalInterruptLowDisable()      (INTCONbits_t.GIEL = 0)

#else

#define  INTERRUPT_GlobalInterruptEnable()          (INTCONbits_t.GIE = 1) 
#define  INTERRUPT_GlobalInterruptDisable()         (INTCONbits_t.GIE = 0)

#define  INTERRUPT_PeripherialInterruptEnable()     (INTCONbits_t.PEIE = 1)
#define  INTERRUPT_PeripherialInterruptDisable()    (INTCONbits_t.PEIE = 0)

#endif

/*  Section : Data Type Declarations    */
typedef enum {
    LOW_PRIORITY=0,
    HIGH_PRIORITY
}interrupt_priority_cfg;
/*  Section : Function Declarations    */



#endif	/* MCAL_INTERRUPT_CFG_H */

