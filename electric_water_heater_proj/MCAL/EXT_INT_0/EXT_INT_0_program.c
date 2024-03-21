/*
 * EXT_INT_0_program.c
 *
 * Created: 2024-02-26 7:15:17 PM
 *  Author: asus
 */ 


/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/reg.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "EXT_INT_0_config.h"
#include "EXT_INT_0_interface.h"
#include "EXT_INT_0_private.h"

static volatile func_ptr callbackPtr= NULL;

void EXT_INT_0_init(void){
	//sense control
	u8 bitISC00,bitISC01;
	
	bitISC00 = GET_BIT(INT0_SENSE_CONTROL,0);
	bitISC01 = GET_BIT(INT0_SENSE_CONTROL,1);
	
	if(bitISC00 == 0) CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT); else SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
	if(bitISC01 == 0) CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT); else SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
	
	//pin input
	DIO_setPinDir(INT0_PIN,INPUT);
}

void EXT_INT_0_enable(){
	SET_BIT(GICR_REG,GICR_INT0_BIT);
}

void EXT_INT_0_disable(){
	CLR_BIT(GICR_REG,GICR_INT0_BIT);
}

void EXT_INT_0_setCallBack(func_ptr fptr){
	callbackPtr = fptr;
}

//ISR
void __vector_1(void)__attribute__((signal));
void __vector_1(){
	if(callbackPtr != NULL){
		callbackPtr();
	}
}