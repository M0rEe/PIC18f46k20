/* 
 * File:   mcal_std_types.h
 * Author: M0rE
 *
 * Created on December 2, 2023, 12:29 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*  Section : Includes    */
#include "std_libraries.h"
#include "compiler.h"

/*  Section : Macro Declarations     */
#define STD_HIGH    0X01
#define STD_LOWH    0X00
#define STD_ON      0X01
#define STD_OFF     0X00
#define STD_ACTIVE  0X01
#define STD_IDLE    0X00


#define E_OK        (STD_ReturnType) 0x01
#define E_NOT_OK    (STD_ReturnType) 0x00

/*  Section : Macro Functions Declarations    */

/*  Section : Data Type Declarations    */
typedef uint8_t STD_ReturnType ;


/*  Section : Function Declarations    */

#endif	/* MCAL_STD_TYPES_H */

