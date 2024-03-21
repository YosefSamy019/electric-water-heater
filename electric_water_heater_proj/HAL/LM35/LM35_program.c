/*
 * LM35_program.c
 *
 * Created: 2024-02-26 9:11:22 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/ADC/ADC_interface.h"

/*		Driver		*/
#include "LM35_config.h"
#include "LM35_interface.h"

void LM35_init(void){
	//do nothing
}
u8 LM35_readTemp(void){
	u32 adcRead=0,adcMilliVolt=0;
	u8 temperature = 0;
	
	adcRead= ADC_read(LM35_CHANNEL);
	adcMilliVolt =  (adcRead * LM35_ADC_VREF_MILLI_VOLT) / LM35_ADC_MAX_READ;
	temperature =adcMilliVolt / LM35_MILLI_VOLT_PER_1_CELECIUS;
	
	return temperature;
}
