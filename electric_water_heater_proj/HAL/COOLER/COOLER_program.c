/*
 * COOLER_program.c
 *
 * Created: 2024-02-26 9:06:01 PM
 *  Author: asus
 */ 


/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "COOLER_config.h"
#include "COOLER_interface.h"

void COOLER_init(void){
	DIO_setPinDir(COOLER_CONTROL_PIN,OUTPUT);
	DIO_setPinValue(COOLER_CONTROL_PIN,LOW);
}
void COOLER_turnOn(void){
	DIO_setPinValue(COOLER_CONTROL_PIN,HIGH);
}
void COOLER_turnOff(void){
	DIO_setPinValue(COOLER_CONTROL_PIN,LOW);
}