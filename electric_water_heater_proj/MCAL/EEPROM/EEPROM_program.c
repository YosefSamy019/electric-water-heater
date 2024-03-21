/*
 * EEPROM_program.c
 *
 * Created: 2024-02-29 12:32:36 AM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../reg.h"

/*		DRIVER		*/
#include "EEPROM_interface.h"

void EEPROM_writeByte(u16 location_10bit,u8 data){
	//wait until the EEPROM to become ready
	while(GET_BIT(EECR_REG,1)==1);
	
	//write address (10 bits)
	EEARL_REG = location_10bit;
	EEARH_REG = (location_10bit>>8) & 0x03;
	
	//write data to register
	EEDR_REG = data;
	
	//set EEMWE
	asm("SBI 0X1C , 2");
	//set EEWE within 4 clks
	asm("SBI 0X1C , 1");
}

u8 EEPROM_readByte(u16 location_10bit){
	//wait until the EEPROM to become ready
	while(GET_BIT(EECR_REG,1)==1);
	
	//write address (10 bits)
	EEARL_REG = location_10bit;
	EEARH_REG = (location_10bit>>8) & 0x03;
	
	//set the EEPROM Read Enable
	SET_BIT(EECR_REG,0);
	
	//return Data (8 bits)
	return (u8)EEDR_REG;	
}
