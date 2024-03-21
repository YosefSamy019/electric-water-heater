/*
 * EEPROM_interface.h
 *
 * Created: 2024-02-29 12:32:49 AM
 *  Author: asus
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_writeByte(u16 location_10bit,u8 data);
u8 EEPROM_readByte(u16 location_10bit);



#endif /* EEPROM_INTERFACE_H_ */