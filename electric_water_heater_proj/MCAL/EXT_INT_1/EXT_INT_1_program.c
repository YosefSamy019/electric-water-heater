/*
 * EXT_INT_1_program.c
 *
 * Created: 2024-02-26 7:16:32 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/reg.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*		Driver		*/
#include "EXT_INT_1_config.h"
#include "EXT_INT_1_interface.h"
#include "EXT_INT_1_private.h"

static volatile func_ptr callbackPtr= NULL;

void EXT_INT_1_init(void){
	//sense control
	u8 bitISC10,bitISC11;
	
	bitISC10 = GET_BIT(INT1_SENSE_CONTROL,0);
	bitISC11 = GET_BIT(INT1_SENSE_CONTROL,1);
	
	if(bitISC10 == 0) CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT); else SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
	if(bitISC11 == 0) CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT); else SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);

	DIO_setPinDir(INT1_PIN,INPUT);
}

void EXT_INT_1_enable(){
	SET_BIT(GICR_REG,GICR_INT1_BIT);
}

void EXT_INT_1_disable(){
	CLR_BIT(GICR_REG,GICR_INT1_BIT);
}

void EXT_INT_1_setCallBack(func_ptr fptr){
	callbackPtr = fptr;
}

//ISR
void __vector_2(void)__attribute__((signal));
void __vector_2(){
	if(callbackPtr != NULL){
		callbackPtr();
	}
}