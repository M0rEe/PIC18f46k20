/* 
 * File:   hal_eeprom.c
 * Author: M0rE
 *
 * Created on January 14, 2024, 3:58 PM
 */
#include "hal_eeprom.h"

/*  Section : Function Declarations    */
STD_ReturnType EEPROM_ReadByte(uint16_t address, uint8_t* retData) {
    STD_ReturnType ret = E_OK;

    if (NULL == retData) {
        ret = E_NOT_OK;
    } else {
        /*Get Interrupt states*/
        uint8_t Global_Interrupt_states = INTCONbits.GIE;
        /*Disable interrupt*/
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        INTERRUPT_GlobalInterruptHighDisable()
#else
        INTERRUPT_GlobalInterruptDisable();
#endif
        /*Write Addres to addresH/L*/
        EEPROM_WRITE_ADDRESH((uint8_t) ((address >> 8)& 0x03));
        EEPROM_WRITE_ADDRESL((uint8_t) ((address)& 0x0ff));
        /*Clear CFGS*/ //Select EEPROM 
        EEPROM_SELECT_PERIPHERAL();
        /*Clear EEPGD*/ //Select EEPROM memory 
        EEPROM_SELECT_DATA_MEMORY();
        /*SET RD*/
        EEPROM_READ_ENABLE();
        NOP();
        NOP();
        /*READ DATA FROM REGISTER*/
        EEPROM_READ_DATA_REG(*retData);
        /*Disable Read*/
        EEPROM_READ_DISABLE();
        /*Restore Interrupt states*/
        INTCONbits.GIE = Global_Interrupt_states;
        ret = E_OK;
    }

    return ret;
}

STD_ReturnType EEPROM_WriteByte(uint16_t address, uint8_t retData) {
    STD_ReturnType ret = E_OK;

    if ( (retData > 255) || (retData < 0)) {
        ret = E_NOT_OK;
    } else {
        /*Get Interrupt states*/
        uint8_t Global_Interrupt_states = INTCONbits.GIE;

        /*Disable interrupt*/
#if INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLED
        INTERRUPT_GlobalInterruptHighDisable()
#else
        INTERRUPT_GlobalInterruptDisable();
#endif
        /*Write Addres to addresH/L*/
        EEPROM_WRITE_ADDRESH((uint8_t) ((address >> 8)& 0x03));
        EEPROM_WRITE_ADDRESL((uint8_t) ((address)& 0x0ff));
        /*Write Data to DAta register*/
        EEPROM_WRITE_DATA_REG(retData);
        /*Clear CFGS*/ //Select EEPROM 
        EEPROM_SELECT_PERIPHERAL();
        /*Clear EEPGD*/ //Select EEPROM memory 
        EEPROM_SELECT_DATA_MEMORY();
        /*Set WREN*/
        EEPROM_WRITE_ENABLE();
        /*WRITE sequence*/
        EEPROM_WRITE_SEQUENCE1();
        EEPROM_WRITE_SEQUENCE2();
        /*Set WR*/
        EEPROM_WRITE();
        /*Wait for write op to complete*/
        while (EEPROM_WRITE_STATE());
        /*Disable Write*/
        EEPROM_WRITE_DISABLE();
        /*Restore Interrupt states*/
        INTCONbits.GIE = Global_Interrupt_states;
        ret = E_OK;
    }

    return ret;
}