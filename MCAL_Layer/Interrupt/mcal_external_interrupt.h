/* 
 * File:   mcal_external_interrupt.h
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:33 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/*  Section : Includes     */
#include "mcal_interrupt_cfg.h"
#include "../GPIO/hal_gpio.h"

/*  Section : Macro Declarations     */
#if EXTERNAL_INTERRUPT_INTx_ENABLE == FEATURE_ENABLED
#define EXT_INT0_INTERRUPT_ENABLE()           (INTCONbits.INT0IE = 1)
#define EXT_INT0_INTERRUPT_DISABLE()          (INTCONbits.INT0IE = 0)

#define EXT_INT0_CLEAR_INTERRUPT_FLAG()       (INTCONbits.INT0IF = 0)

#define EXT_INT0_RISING_EDGE_SET()            (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FALIING_EDGE_SET()           (INTCON2bits.INTEDG0 = 0)
/*-------------------------------------------------------------------------------*/
#define EXT_INT1_INTERRUPT_ENABLE()           (INTCON3bits.INT1E = 1)
#define EXT_INT1_INTERRUPT_DISABLE()          (INTCON3bits.INT1E = 0)

#define EXT_INT1_CLEAR_FLAGE()                (INTCON3bits.INT1F = 0)

#define EXT_INT1_RISING_EDGE_SET()            (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FALIING_EDGE_SET()           (INTCON2bits.INTEDG1 = 0)
/*-------------------------------------------------------------------------------*/
#define EXT_INT2_INTERRUPT_ENABLE()           (INTCON3bits.INT2E = 1)
#define EXT_INT2_INTERRUPT_DISABLE()          (INTCON3bits.INT2E = 0)

#define EXT_INT2_CLEAR_FLAGE()                (INTCON3bits.INT2F = 0)

#define EXT_INT2_RISING_EDGE_SET()            (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FALIING_EDGE_SET()           (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

#define EXT_INT1_HIGH_PRIORITY_SET()           (INTCON3bits.INT1IP =1)
#define EXT_INT1_LOW_PRIORITY_SET()            (INTCON3bits.INT1IP =0)

#define EXT_INT2_HIGH_PRIORITY_SET()           (INTCON3bits.INT2IP =1)
#define EXT_INT2_LOW_PRIORITY_SET()            (INTCON3bits.INT2IP =0)

#endif

#endif


#if EXTERNAL_INTERRUPT_ONCHANGE_ENABLE == FEATURE_ENABLED


#define EXT_RBx_ENABLE()             (INTCONbits_t.RBIE = 1)
#define EXT_RBx_DISABLE()            (INTCONbits_t.RBIE = 0)

#define EXT_RBx_CLEAR_FLAG()         (INTCONbits_t.RBIF = 0)


#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

#define EXT_RBx_HIGH_PRIORITY_SET()  (INTCON2bits_t.RBIP = 1)
#define EXT_RBx_LOW_PRIORITY_SET()   (INTCON2bits_t.RBIP = 0)

#endif

#endif
/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef enum {
    FALLING_EDGE = 0,
    RISNIG_EDGE
} interrupt_INTx_edge;

typedef enum {
    EXT_INT0 = 0,
    EXT_INT1,
    EXT_INT2
} interrupt_INTx_src;

typedef struct {
    void(*callback_function)(void);
    pin_config_t pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src src;
    interrupt_priority_cfg priority;
} Interrupt_INTx_t;

typedef struct {
    void(*callback_function)(void);
    pin_config_t pin;
    interrupt_priority_cfg priority;
} Interrupt_RBx_t;


/*  Section : Function Declarations    */
STD_ReturnType Interrupt_INTx_Init(Interrupt_INTx_t * obj);
STD_ReturnType Interrupt_INTx_DeInit(Interrupt_INTx_t * obj);

STD_ReturnType Interrupt_RBx_Init(Interrupt_RBx_t * obj);
STD_ReturnType Interrupt_RBx_DeInit(Interrupt_RBx_t * obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

