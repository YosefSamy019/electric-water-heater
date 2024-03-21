/*
 * DIO_interface.h
 *
 * Created: 2024-02-26 5:17:27 PM
 *  Author: asus
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*			PINS			*/
#define PA0 0xA0
#define PA1 0xA1
#define PA2 0xA2
#define PA3 0xA3
#define PA4 0xA4
#define PA5 0xA5
#define PA6 0xA6
#define PA7 0xA7

#define PB0 0xB0
#define PB1 0xB1
#define PB2 0xB2
#define PB3 0xB3
#define PB4 0xB4
#define PB5 0xB5
#define PB6 0xB6
#define PB7 0xB7

#define PC0 0xC0
#define PC1 0xC1
#define PC2 0xC2
#define PC3 0xC3
#define PC4 0xC4
#define PC5 0xC5
#define PC6 0xC6
#define PC7 0xC7

#define PD0 0xD0
#define PD1 0xD1
#define PD2 0xD2
#define PD3 0xD3
#define PD4 0xD4
#define PD5 0xD5
#define PD6 0xD6
#define PD7 0xD7

/*		Values			*/
#define HIGH 1
#define LOW  0

/*			Directions			*/
#define OUTPUT 1
#define INPUT  0

/*			Prototypes			*/
void DIO_setPinDir(u8 pin,u8 dir);
void DIO_setPinValue(u8 pin,u8 value);
u8 DIO_getPinValue(u8 pin);
void DIO_togglePin(u8 pin);

#endif /* DIO_INTERFACE_H_ */