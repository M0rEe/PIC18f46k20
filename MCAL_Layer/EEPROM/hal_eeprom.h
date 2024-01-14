/* 
 * File:   hal_eeprom.h
 * Author: M0rE
 *
 * Created on January 14, 2024, 3:58 PM
 */

/*  Section : Includes    */
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*  Section : Macro Declarations     */


/*  Section : Macro Functions Declarations    */
#define EEPROM_SELECT_DATA_MEMORY() EECON1bits.CFGS = 0
#define EEPROM_SELECT_PERIPHERAL()  EECON1bits.EEPGD =0

#define EEPROM_WRITE_ENABLE()       EECON1bits.WREN =1
#define EEPROM_WRITE_DISABLE()      EECON1bits.WREN =0
#define EEPROM_WRITE()              EECON1bits.WR =1

#define EEPROM_READ_ENABLE()        EECON1bits.RD =1
#define EEPROM_READ_DISABLE()       EECON1bits.RD =0

#define EEPROM_WRITE_ADDRESL(add)   EEADR   = add
#define EEPROM_WRITE_ADDRESH(add)   EEADRH  = add

#define EEPROM_WRITE_DATA_REG(data) EEDATA  = data
#define EEPROM_READ_DATA_REG(data)  data    = EEDATA

#define EEPROM_WRITE_STATE()        EECON1bits.WR

#define EEPROM_WRITE_SEQUENCE1()    EECON2  = 0x55
#define EEPROM_WRITE_SEQUENCE2()    EECON2  = 0xAA
/*  Section : Data Type Declarations    */


/*  Section : Function Declarations    */
STD_ReturnType EEPROM_ReadByte(uint16_t address,uint8_t* retData);
STD_ReturnType EEPROM_WriteByte(uint16_t address,uint8_t retData);


