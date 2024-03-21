/*
 * ADC_config.h
 *
 * Created: 2024-02-26 8:46:26 PM
 *  Author: asus
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*		Voltage Reference Selections for ADC		*/
#define ADC_VREF_AREF 0
#define ADC_VREF_AVCC_WITH_CAP 1
#define ADC_VREF_RESERVED 2
#define ADC_VREF_INTERNAL_2P56_WITH_CAP 3
#define ADC_VREF_SELECTION ADC_VREF_AREF

/*		ADC Adjust Result (0 -> right adjust, 1 -> left adjust)		*/
#define ADC_ADJUST 0

/*		ADC Prescaler Selections		*/
#define ADC_DIV_FACT_2 1  //0 or 1
#define ADC_DIV_FACT_4 2
#define ADC_DIV_FACT_8 3
#define ADC_DIV_FACT_16 4
#define ADC_DIV_FACT_32 5
#define ADC_DIV_FACT_64 6
#define ADC_DIV_FACT_128 7
#define ADC_DIV_FACT_SELECTION ADC_DIV_FACT_128

/*		ADC Auto Trigger Enable (0, 1)		*/
#define ADC_Auto_Trigger_Enable 0

/*		ADC Auto Trigger Source Selections		*/
#define ADC_TRIGGER_SOURCE_FREE_RUNNING_MODE 0
#define ADC_TRIGGER_SOURCE_ANALOG_COMPARATOR 1
#define ADC_TRIGGER_SOURCE_EXTERNAL_INT_0 2
#define ADC_TRIGGER_SOURCE_TIMER0_COMPARE_MATCH 3
#define ADC_TRIGGER_SOURCE_TIMER0_OVERFLOW 4
#define ADC_TRIGGER_SOURCE_TIMER1_COMPARE_MATCH_B 5
#define ADC_TRIGGER_SOURCE_TIMER1_OVERFLOW 6
#define ADC_TRIGGER_SOURCE_TIMER1_CAPTURE_EVENT 7
#define ADC_TRIGGER_SOURCE_SELECTION ADC_TRIGGER_SOURCE_FREE_RUNNING_MODE




#endif /* ADC_CONFIG_H_ */