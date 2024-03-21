/*
 * HEATER_program.c
 *
 * Created: 2024-02-26 9:01:04 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "HEATER_config.h"
#include "HEATER_interface.h"

void HEATER_init(void){
	DIO_setPinDir(HEATER_CONTROL_PIN,OUTPUT);
	DIO_setPinValue(HEATER_CONTROL_PIN,LOW);
}
void HEATER_turnOn(void){
	DIO_setPinValue(HEATER_CONTROL_PIN,HIGH);
}
void HEATER_turnOff(void){	
	DIO_setPinValue(HEATER_CONTROL_PIN,LOW);
}