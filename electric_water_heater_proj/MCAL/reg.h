/*
 * reg.h
 *
 * Created: 2024-02-26 5:25:51 PM
 *  Author: asus
 */ 


#ifndef REG_H_
#define REG_H_

/*			LIB			*/
#include "../LIB/STD_TYPES.h"

/*			DIO			*/
#define PORTA_REG (*((volatile u8*)0x3B))
#define DDRA_REG  (*((volatile u8*)0x3A))
#define PINA_REG  (*((volatile u8*)0x39))

#define PORTB_REG (*((volatile u8*)0x38))
#define DDRB_REG  (*((volatile u8*)0x37))
#define PINB_REG  (*((volatile u8*)0x36))

#define PORTC_REG (*((volatile u8*)0x35))
#define DDRC_REG  (*((volatile u8*)0x34))
#define PINC_REG  (*((volatile u8*)0x33))

#define PORTD_REG (*((volatile u8*)0x32))
#define DDRD_REG  (*((volatile u8*)0x31))
#define PIND_REG  (*((volatile u8*)0x30))

/*			SREG			*/
#define SREG_REG (*((volatile u8*)0x5F))

/*		External Interrupts		*/
#define GICR_REG (*((volatile u8*)0x5B))
#define GICR_INT0_BIT 6
#define GICR_INT1_BIT 7
#define GICR_INT2_BIT 5

#define MCUCR_REG (*((volatile u8*)0x55))
#define MCUCR_ISC00_BIT 0
#define MCUCR_ISC01_BIT 1
#define MCUCR_ISC10_BIT 2
#define MCUCR_ISC11_BIT 3

#define MCUCSR_REG (*((volatile u8*)0x54))
#define MCUCSR_ISC2_BIT 6

/*		ADC		*/
#define ADMUX_REG (*((volatile u8*)0x27))
#define ADCSRA_REG (*((volatile u8*)0x26))
#define ADCH_REG (*((volatile u8*)0x25))
#define ADCL_REG (*((volatile u8*)0x24))
#define SFIOR_REG (*((volatile u8*)0x50))

/*		TIMER2		*/
#define TCCR2_REG *((volatile u8*)0x45)
#define TCNT2_REG *((volatile u8*)0x44)
#define OCR2_REG  *((volatile u8*)0x43)
#define TIMSK_REG *((volatile u8*)0x59)

/*		EEPROM		*/
#define EEARH_REG *((volatile u8*)0x3F)
#define EEARL_REG *((volatile u8*)0x3E)
#define EEDR_REG  *((volatile u8*)0x3D)
#define EECR_REG  *((volatile u8*)0x3C)


#endif /* REG_H_ */