/*
 * SEV_SEG_program.c
 *
 * Created: 2024-02-26 6:27:18 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "SEV_SEG_config.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"

static u8 digit1_num =0;
static u8 digit2_num =0;

static boolean digit1_en =false;
static boolean digit2_en =false;

static boolean digit1_dot =false;
static boolean digit2_dot =false;


void SEV_SEG_init(void){
	DIO_setPinDir(SEV_SEG_EN1_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_EN2_PIN,OUTPUT);
	
	DIO_setPinDir(SEV_SEG_DIP_PIN,OUTPUT);
	
	DIO_setPinDir(SEV_SEG_A_1_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_B_1_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_C_1_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_D_1_PIN,OUTPUT);
	
	DIO_setPinDir(SEV_SEG_A_2_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_B_2_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_C_2_PIN,OUTPUT);
	DIO_setPinDir(SEV_SEG_D_2_PIN,OUTPUT);
}

void SEV_SEG_setDigit(u8 digitNo,u8 num){
	switch(digitNo){
		case SEV_SEG_DIGIT_1:
			digit1_num = num; break;
		case SEV_SEG_DIGIT_2:
			digit2_num = num; break;
	}
}


void SEV_SEG_enableDigit(u8 digitNo){
	switch(digitNo){
		case SEV_SEG_DIGIT_1:
			digit1_en = true; break;
		case SEV_SEG_DIGIT_2:
			digit2_en = true; break;
	}
}

void SEV_SEG_enableDot(u8 digitNo){
	switch(digitNo){
		case SEV_SEG_DIGIT_1:
		digit1_dot = true; break;
		case SEV_SEG_DIGIT_2:
		digit2_dot = true; break;
	}
}

void SEV_SEG_disableDigit(u8 digitNo){
	switch(digitNo){
		case SEV_SEG_DIGIT_1:
		digit1_en = false; break;
		case SEV_SEG_DIGIT_2:
		digit2_en = false; break;
	}
	SEV_SEG_update();
}


void SEV_SEG_disableDot(u8 digitNo){
	switch(digitNo){
		case SEV_SEG_DIGIT_1:
		digit1_dot = false; break;
		case SEV_SEG_DIGIT_2:
		digit2_dot = false; break;
	}
	SEV_SEG_update();
}

void SEV_SEG_update(void){
	DIO_setPinValue(SEV_SEG_A_1_PIN, GET_BIT(digit1_num,0));
	DIO_setPinValue(SEV_SEG_B_1_PIN, GET_BIT(digit1_num,1));
	DIO_setPinValue(SEV_SEG_C_1_PIN, GET_BIT(digit1_num,2));
	DIO_setPinValue(SEV_SEG_D_1_PIN, GET_BIT(digit1_num,3));
		
	DIO_setPinValue(SEV_SEG_EN1_PIN, digit1_en);
	DIO_setPinValue(SEV_SEG_DIP_PIN, digit1_dot);
	
	
	DIO_setPinValue(SEV_SEG_A_2_PIN, GET_BIT(digit2_num,0));
	DIO_setPinValue(SEV_SEG_B_2_PIN, GET_BIT(digit2_num,1));
	DIO_setPinValue(SEV_SEG_C_2_PIN, GET_BIT(digit2_num,2));
	DIO_setPinValue(SEV_SEG_D_2_PIN, GET_BIT(digit2_num,3));
	
	DIO_setPinValue(SEV_SEG_EN2_PIN, digit2_en);
	DIO_setPinValue(SEV_SEG_DIP_PIN, digit2_dot);
	
	
// 	static u8 counter = 0;
// 	
// 	switch (counter){
// 		case 0:
// 			counter = 1;
// 			
// 			DIO_setPinValue(SEV_SEG_EN2_PIN, false);
// 			
// 			DIO_setPinValue(SEV_SEG_A_PIN, GET_BIT(digit1_num,0));
// 			DIO_setPinValue(SEV_SEG_B_PIN, GET_BIT(digit1_num,1));
// 			DIO_setPinValue(SEV_SEG_C_PIN, GET_BIT(digit1_num,2));
// 			DIO_setPinValue(SEV_SEG_D_PIN, GET_BIT(digit1_num,3));
// 			
// 			DIO_setPinValue(SEV_SEG_EN1_PIN, digit1_en);
// 			DIO_setPinValue(SEV_SEG_DIP_PIN, digit1_dot);
// 			break;
// 		
// 		case 1:
// 			counter = 0;
// 			
// 			DIO_setPinValue(SEV_SEG_EN1_PIN, false);
// 			
// 			DIO_setPinValue(SEV_SEG_A_PIN, GET_BIT(digit2_num,0));
// 			DIO_setPinValue(SEV_SEG_B_PIN, GET_BIT(digit2_num,1));
// 			DIO_setPinValue(SEV_SEG_C_PIN, GET_BIT(digit2_num,2));
// 			DIO_setPinValue(SEV_SEG_D_PIN, GET_BIT(digit2_num,3));
// 			
// 			DIO_setPinValue(SEV_SEG_EN2_PIN, digit2_en);
// 			DIO_setPinValue(SEV_SEG_DIP_PIN, digit2_dot);
// 			break;
// 	}
}