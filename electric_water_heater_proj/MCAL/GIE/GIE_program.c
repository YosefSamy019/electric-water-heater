/*
 * GIE_program.c
 *
 * Created: 2024-02-26 7:11:07 PM
 *  Author: asus
 */ 


/*		LIB			*/
#include "../../LIB/BIT_MATH.h"

/*		MCAL		*/
#include "../reg.h"

/*		Driver		*/
#include "GIE_interface.h"

void GIE_enable(void){
	SET_BIT(SREG_REG,7);
}

void GIE_disable(void){
	CLR_BIT(SREG_REG,7);
}
