/*
 * RGB_LED_program.c
 *
 * Created: 2024-02-26 5:47:28 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

/*		MCAL		*/
#include "../../MCAL/DIO/DIO_interface.h"

/*		DRIVER		*/
#include "RGB_LED_interface.h"
#include "RGB_LED_private.h"

void RGB_LED_init(RGB_LED* led,u8 type,u8 r_pin, u8 g_pin, u8 b_pin){
	led->type  = type;
	led->r_pin = r_pin;
	led->g_pin = g_pin;
	led->b_pin = b_pin;
	led->color = COLOR_BLACK;
	
	DIO_setPinDir(r_pin,OUTPUT);
	DIO_setPinDir(g_pin,OUTPUT);
	DIO_setPinDir(b_pin,OUTPUT);
}

void RGB_LED_turnOff(RGB_LED* led){
	DIO_setPinValue(led->r_pin, led->type);
	DIO_setPinValue(led->g_pin, led->type);
	DIO_setPinValue(led->b_pin, led->type);
}

void RGB_LED_turnOn(RGB_LED* led){
	u8 color = led->color;
	switch(led->type){
		case COMMON_CATHODE: break;
		case COMMON_ANODE: color = ~color; break;
	}
	
	DIO_setPinValue(led->r_pin, GET_BIT(color,RGB_LED_REG_INDEX));
	DIO_setPinValue(led->g_pin, GET_BIT(color,RGB_LED_GREEN_INDEX));
	DIO_setPinValue(led->b_pin, GET_BIT(color,RGB_LED_BLUE_INDEX));
}


void RGB_LED_setColor(RGB_LED* led,u8 color){
	led->color = color;
	switch(led->type){
		case COMMON_CATHODE: break;
		case COMMON_ANODE: color = ~color; break;
	}
	
	DIO_setPinValue(led->r_pin, GET_BIT(color,RGB_LED_REG_INDEX));
	DIO_setPinValue(led->g_pin, GET_BIT(color,RGB_LED_GREEN_INDEX));
	DIO_setPinValue(led->b_pin, GET_BIT(color,RGB_LED_BLUE_INDEX));
}