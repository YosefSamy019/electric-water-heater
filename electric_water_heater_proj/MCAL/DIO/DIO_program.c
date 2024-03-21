/*
 * DIO_program.c
 *
 * Created: 2024-02-26 5:17:06 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../reg.h"

/*		DRIVER		*/
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_setPinDir(u8 pin,u8 dir){
	u8 pinNo,portNo;
	pinNo =  pin & 0x0f;
	portNo = pin & 0xf0;
	
	switch(dir){
		case OUTPUT:
			switch (portNo){
				case A:SET_BIT(DDRA_REG,pinNo); break;
				case B:SET_BIT(DDRB_REG,pinNo); break;
				case C:SET_BIT(DDRC_REG,pinNo); break;
				case D:SET_BIT(DDRD_REG,pinNo); break;
			}
			break;
		case INPUT:
			switch (portNo){
				case A:CLR_BIT(DDRA_REG,pinNo); break;
				case B:CLR_BIT(DDRB_REG,pinNo); break;
				case C:CLR_BIT(DDRC_REG,pinNo); break;
				case D:CLR_BIT(DDRD_REG,pinNo); break;
			}
			break;
	}
}

void DIO_setPinValue(u8 pin,u8 value){
	u8 pinNo,portNo;
	pinNo =  pin & 0x0f;
	portNo = pin & 0xf0;
	
	switch(value){
		case HIGH:
		switch (portNo){
			case A:SET_BIT(PORTA_REG,pinNo); break;
			case B:SET_BIT(PORTB_REG,pinNo); break;
			case C:SET_BIT(PORTC_REG,pinNo); break;
			case D:SET_BIT(PORTD_REG,pinNo); break;
		}
		break;
		case LOW:
		switch (portNo){
			case A:CLR_BIT(PORTA_REG,pinNo); break;
			case B:CLR_BIT(PORTB_REG,pinNo); break;
			case C:CLR_BIT(PORTC_REG,pinNo); break;
			case D:CLR_BIT(PORTD_REG,pinNo); break;
		}
		break;
	}
}

u8 DIO_getPinValue(u8 pin){
	u8 pinNo,portNo;
	pinNo =  pin & 0x0f;
	portNo = pin & 0xf0;
	
	switch (portNo){
		case A:return GET_BIT(PINA_REG,pinNo); break;
		case B:return GET_BIT(PINB_REG,pinNo); break;
		case C:return GET_BIT(PINC_REG,pinNo); break;
		case D:return GET_BIT(PIND_REG,pinNo); break;
	}
}

void DIO_togglePin(u8 pin){
	u8 pinNo,portNo;
	pinNo =  pin & 0x0f;
	portNo = pin & 0xf0;
	
	switch (portNo){
		case A: TOG_BIT(PORTA_REG,pinNo); break;
		case B: TOG_BIT(PORTB_REG,pinNo); break;
		case C: TOG_BIT(PORTC_REG,pinNo); break;
		case D: TOG_BIT(PORTD_REG,pinNo); break;
	}
}