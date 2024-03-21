/*
 * EXT_INT_2_program.c
 *
 * Created: 2024-02-26 7:17:29 PM
 *  Author: asus
 */ 


/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/reg.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "EXT_INT_2_config.h"
#include "EXT_INT_2_interface.h"
#include "EXT_INT_2_private.h"

static volatile func_ptr callbackPtr= NULL;

void EXT_INT_2_init(void){
	//sense control
	#if INT2_SENSE_CONTROL == INT2_SENSE_FALLING_EDGE
		CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
	#elif INT2_SENSE_CONTROL==INT2_SENSE_RISING_EDGE
		SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
	#else
		#error INT2 ERROR, sense control not defined
	#endif
	
	
	DIO_setPinDir(INT2_PIN,INPUT);
}

void EXT_INT_2_enable(){
	SET_BIT(GICR_REG,GICR_INT2_BIT);
}

void EXT_INT_2_disable(){
	CLR_BIT(GICR_REG,GICR_INT2_BIT);
}

void EXT_INT_2_setCallBack(func_ptr fptr){
	callbackPtr = fptr;
}

//ISR
void __vector_3(void)__attribute__((signal));
void __vector_3(){
	if(callbackPtr != NULL){
		callbackPtr();
	}
}