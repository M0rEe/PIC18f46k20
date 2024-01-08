/* 
 * File:   mcal_external_interrupt.c
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:33 PM
 */
#include "mcal_external_interrupt.h"

static void (*INT0_CALBACK)(void) = NULL;
static void (*INT1_CALBACK)(void) = NULL;
static void (*INT2_CALBACK)(void) = NULL;

void INT0_ISR(void) {

    EXT_INT0_CLEAR_FLAG();

    if (INT0_CALBACK)
        INT0_CALBACK();
}

void INT1_ISR(void) {

    EXT_INT1_CLEAR_FLAG();

    if (INT1_CALBACK)
        INT1_CALBACK();

}

void INT2_ISR(void) {

    EXT_INT2_CLEAR_FLAG();

    if (INT2_CALBACK)
        INT2_CALBACK();

}


static STD_ReturnType interrupt_INTx_Enable(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Disable(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Edge_Init(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Pin_Init(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Priority_Init(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Clear_Flag(const Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_CallBack_Init(const Interrupt_INTx_t * obj);


static STD_ReturnType interrupt_RBx_Enable(const Interrupt_RBx_t * obj);
static STD_ReturnType interrupt_RBx_Disable(const Interrupt_RBx_t * obj);
static STD_ReturnType interrupt_RBx_Pin_Init(const Interrupt_RBx_t * obj);
static STD_ReturnType interrupt_RBx_Priority_Init(const Interrupt_RBx_t * obj);

STD_ReturnType Interrupt_INTx_Init(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        /*disable */
        ret = interrupt_INTx_Disable(obj);
        /*clear flag */
        ret = interrupt_INTx_Clear_Flag(obj);
        /*edge */
        ret = interrupt_INTx_Edge_Init(obj);
        /*priority*/
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        ret = interrupt_INTx_Priority_Init(obj);
#endif
        /*pin*/
        ret = interrupt_INTx_Pin_Init(obj);
        /*callback*/
        ret = interrupt_INTx_CallBack_Init(obj);
        /*enable */
        ret = interrupt_INTx_Enable(obj);
    }
    return ret;
}

STD_ReturnType Interrupt_INTx_DeInit(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = interrupt_INTx_Disable(obj);
    }
    return ret;
}

STD_ReturnType Interrupt_RBx_Init(Interrupt_RBx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}

STD_ReturnType Interrupt_RBx_DeInit(Interrupt_RBx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}

static STD_ReturnType interrupt_INTx_Enable(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;

        #if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripherialInterruptEnable();
        #endif
        switch (obj->src) {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_ENABLE(); /* ENABLE the INT0 external interrupt */
                ret = E_OK;
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE(); /* ENABLE the INT1 external interrupt */
                ret = E_OK;
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE(); /* ENABLE the INT2 external interrupt */
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType interrupt_INTx_Disable(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->src) {
                ret = E_OK;
            case EXT_INT0:
                EXT_INT0_INTERRUPT_DISABLE();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_DISABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_DISABLE();
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType interrupt_INTx_Edge_Init(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;

        switch (obj->src) {

            case EXT_INT0:
                if (FALLING_EDGE == obj->edge) {
                    EXT_INT0_FALIING_EDGE_SET();
                } else if (RISNIG_EDGE == obj->edge) {
                    EXT_INT0_RISING_EDGE_SET();
                } else {
                    ret = E_NOT_OK;
                }
                break;

            case EXT_INT1:
                if (FALLING_EDGE == obj->edge) {
                    EXT_INT1_FALIING_EDGE_SET();
                } else if (RISNIG_EDGE == obj->edge) {
                    EXT_INT1_RISING_EDGE_SET();
                } else {
                    ret = E_NOT_OK;
                }
                break;

            case EXT_INT2:
                if (FALLING_EDGE == obj->edge) {
                    EXT_INT2_FALIING_EDGE_SET();
                } else if (RISNIG_EDGE == obj->edge) {
                    EXT_INT2_RISING_EDGE_SET();
                } else {
                    ret = E_NOT_OK;
                }
                break;

            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType interrupt_INTx_Pin_Init(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_initialize(&(obj->pin));
    }
    return ret;
}


#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED

static STD_ReturnType interrupt_INTx_Priority_Init(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->src) {

            case EXT_INT1:
                if (HIGH_PRIORITY == obj->priority) {
                    EXT_INT1_HIGH_PRIORITY_SET();
                } else if (LOW_PRIORITY == obj->priority) {
                    EXT_INT1_LOW_PRIORITY_SET();
                } else {
                    ret = E_NOT_OK;
                }
                break;

            case EXT_INT2:
                if (HIGH_PRIORITY == obj->priority) {
                    EXT_INT2_HIGH_PRIORITY_SET();
                } else if (LOW_PRIORITY == obj->priority) {
                    EXT_INT2_LOW_PRIORITY_SET();
                } else {
                    ret = E_NOT_OK;
                }
                break;

            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

static STD_ReturnType interrupt_INTx_Clear_Flag(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->src) {
            case EXT_INT0:
                EXT_INT0_CLEAR_FLAG();
                break;

            case EXT_INT1:
                EXT_INT1_CLEAR_FLAG();
                break;

            case EXT_INT2:
                EXT_INT2_CLEAR_FLAG();
                break;
        }
    }
    return ret;

}

static STD_ReturnType interrupt_INTx_CallBack_Init(const Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->src) {
            case EXT_INT0:
                if (NULL == obj->callback_function) {
                    ret = E_NOT_OK;
                } else {
                    INT0_CALBACK = obj->callback_function;
                }
                break;

            case EXT_INT1:
                if (NULL == obj->callback_function) {
                    ret = E_NOT_OK;
                } else {
                    INT1_CALBACK = obj->callback_function;
                }
                break;

            case EXT_INT2:
                if (NULL == obj->callback_function) {
                    ret = E_NOT_OK;
                } else {
                    INT2_CALBACK = obj->callback_function;
                }
                break;
        }
    }
    return ret;
}
