/* 
 * File:   ecu_7seg.h
 * Author: M0rE
 *
 * Created on December 17, 2023, 3:36 PM
 */

#ifndef ECU_7SEG_H
#define	ECU_7SEG_H


/*  Section : Includes    */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_7seg_cfg.h"

/*  Section : Macro Declarations     */


/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef enum{
    SEG_COMMON_ANODE,
    SEG_COMMON_CATHODE
}segType_t;

typedef struct {
    pin_config_t segPins[4];
    segType_t segType;
}segment_t;

/*  Section : Function Declarations    */
STD_ReturnType segInit(const segment_t *seg);
STD_ReturnType segWrite(const segment_t *seg,uint8_t num);

#endif	/* ECU_7SEG_H */

