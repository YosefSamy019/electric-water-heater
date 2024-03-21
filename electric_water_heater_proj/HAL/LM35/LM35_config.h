/*
 * LM35_config.h
 *
 * Created: 2024-02-26 9:11:51 PM
 *  Author: asus
 */ 


#ifndef LM35_CONFIG_H_
#define LM35_CONFIG_H_

/*		ADC CHANNEL		*/
#define LM35_CHANNEL ADC_SINGLE_CHANNEL_7

/*		ADC Properties		*/
#define LM35_ADC_VREF_MILLI_VOLT 1000
#define LM35_ADC_MAX_READ 1023

#define LM35_MILLI_VOLT_PER_1_CELECIUS 10;

#endif /* LM35_CONFIG_H_ */