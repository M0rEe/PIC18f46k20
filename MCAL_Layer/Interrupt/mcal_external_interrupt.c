/* 
 * File:   mcal_external_interrupt.c
 * Author: M0rE
 *
 * Created on January 7, 2024, 5:33 PM
 */
#include "mcal_external_interrupt.h"
static STD_ReturnType interrupt_INTx_Enable(Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Disable(Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Edge_Init(Interrupt_INTx_t * obj);

static STD_ReturnType interrupt_INTx_Pin_Init(Interrupt_INTx_t * obj);
static STD_ReturnType interrupt_INTx_Priority_Init(Interrupt_INTx_t * obj);

STD_ReturnType Interrupt_INTx_Init(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}

STD_ReturnType Interrupt_INTx_DeInit(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {

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

static STD_ReturnType interrupt_INTx_Enable(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->src) {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_ENABLE(); /* Disable the INT0 external interrupt */
                ret = E_OK;
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE(); /* Disable the INT1 external interrupt */
                ret = E_OK;
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE(); /* Disable the INT2 external interrupt */
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType interrupt_INTx_Disable(Interrupt_INTx_t * obj) {
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

static STD_ReturnType interrupt_INTx_Edge_Init(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {
        ret = E_OK;
        switch (obj->edge) {
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

static STD_ReturnType interrupt_INTx_Pin_Init(Interrupt_INTx_t * obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}


#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
static STD_ReturnType interrupt_INTx_Priority_Init(Interrupt_INTx_t * obj) {
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
                EXT_INT2_INTERRUPT_DISABLE();
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
