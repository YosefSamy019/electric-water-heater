/*
 * ADC_program.c
 *
 * Created: 2024-02-26 8:45:39 PM
 *  Author: asus
 */ 


/*		LIB			*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/reg.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

/*		Driver		*/
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_init(void){
	//Enable ADC
	SET_BIT(ADCSRA_REG,7);
	
	//Voltage Reference Selection
	ADMUX_REG = (ADMUX_REG&0b00111111) | (ADC_VREF_SELECTION<<6);
	
	//ADC Prescaler Select Bits
	ADCSRA_REG = (ADCSRA_REG&0b11111000) | (ADC_DIV_FACT_SELECTION&0b00000111);
	
	//ADJUSTEMNT
	#if ADC_ADJUST==0
		CLR_BIT(ADMUX_REG,5);
	#elif ADC_ADJUST==1
		SET_BIT(ADMUX_REG,5);
	#else
		#error ADC ERROR, adjust undefined
	#endif
	
	//ADC Auto Trigger Enable
	#if ADC_Auto_Trigger_Enable==0
		CLR_BIT(ADCSRA_REG,5);
	#elif ADC_Auto_Trigger_Enable==1
		SET_BIT(ADCSRA_REG,5);
		//ADC Auto Trigger Source
		SFIOR_REG = (SFIOR_REG&0b00011111) | (ADC_TRIGGER_SOURCE_SELECTION<<5);
	#else
		#error ADC ERROR, ADC Auto Trigger Enable undefined
	#endif
}

u32 ADC_read(u8 channel){
	u32 returnVal = 0;
	
	ADMUX_REG = (ADMUX_REG&0b11100000) | (channel & 0b00011111);
	
	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,6);
	
	//wait
	while(GET_BIT(ADCSRA_REG,4) == 0);
	
	//read
	#if ADC_ADJUST==0
		returnVal = ((int)(ADCL_REG) + ((int)ADCH_REG<<8));
	#elif ADC_ADJUST==1
		returnVal = (int)ADCL_REG>>6 + (int)ADCH_REG<<2;
	#else
		#error ADC ERROR, adjust undefined
	#endif
	
	return returnVal;
}