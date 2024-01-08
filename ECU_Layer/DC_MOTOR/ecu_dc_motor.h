/* 
 * File:   ecu_dc_motor.h
 * Author: M0rE
 *
 * Created on December 15, 2023, 2:35 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*  Section : Includes     */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_dc_motor_cfg.h"
/*  Section : Macro Declarations     */

/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */

typedef struct {
    pin_config_t dcMotor_pins[2];
}dcMotor_t;
/*  Section : Function Declarations    */
STD_ReturnType dcMotor_intit(const dcMotor_t* motor);
STD_ReturnType dcMotor_Move_right(const dcMotor_t* motor);
STD_ReturnType dcMotor_Move_left(const dcMotor_t* motor);
STD_ReturnType dcMotor_Stop(const dcMotor_t* motor);


#endif	/* ECU_DC_MOTOR_H */

