/* 
 * File:   ecu_relay.h
 * Author: M0rE
 *
 * Created on December 14, 2023, 2:10 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*  Section : Includes     */
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*  Section : Macro Declarations     */
#define REALY_STATE_ON 0x01U
#define REALY_STATE_OFF 0x00U
/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef struct {
    uint8_t port:4;
    uint8_t pin:3;
    uint8_t state:1;
}relay_t;

/*  Section : Function Declarations    */
STD_ReturnType relayInit(const relay_t * relay);
STD_ReturnType relayON(const relay_t * relay);
STD_ReturnType relayOFF(const relay_t * relay);

#endif	/* ECU_RELAY_H */

