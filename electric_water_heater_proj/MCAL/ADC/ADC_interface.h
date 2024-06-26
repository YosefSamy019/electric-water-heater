/*
 * ADC_interface.h
 *
 * Created: 2024-02-26 8:45:23 PM
 *  Author: asus
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*		Input Channel and Gain Selections		*/
#define ADC_SINGLE_CHANNEL_0 0
#define ADC_SINGLE_CHANNEL_1 1
#define ADC_SINGLE_CHANNEL_2 2
#define ADC_SINGLE_CHANNEL_3 3
#define ADC_SINGLE_CHANNEL_4 4
#define ADC_SINGLE_CHANNEL_5 5
#define ADC_SINGLE_CHANNEL_6 6
#define ADC_SINGLE_CHANNEL_7 7
#define ADC_DIFF_CHANNEL_0_0_10X 8
#define ADC_DIFF_CHANNEL_1_0_10X 9
#define ADC_DIFF_CHANNEL_0_0_200X 10
#define ADC_DIFF_CHANNEL_1_0_200X 11
#define ADC_DIFF_CHANNEL_2_2_10X 12
#define ADC_DIFF_CHANNEL_3_2_10X 13
#define ADC_DIFF_CHANNEL_2_2_200X 14
#define ADC_DIFF_CHANNEL_3_2_200X 15
#define ADC_DIFF_CHANNEL_0_1_1X 16
#define ADC_DIFF_CHANNEL_1_1_1X 17
#define ADC_DIFF_CHANNEL_2_1_1X 18
#define ADC_DIFF_CHANNEL_3_1_1X 19
#define ADC_DIFF_CHANNEL_4_1_1X 20
#define ADC_DIFF_CHANNEL_5_1_1X 21
#define ADC_DIFF_CHANNEL_6_1_1X 22
#define ADC_DIFF_CHANNEL_7_1_1X 23
#define ADC_DIFF_CHANNEL_0_2_1X 24
#define ADC_DIFF_CHANNEL_1_2_1X 25
#define ADC_DIFF_CHANNEL_2_2_1X 26
#define ADC_DIFF_CHANNEL_3_2_1X 27
#define ADC_DIFF_CHANNEL_4_2_1X 28
#define ADC_DIFF_CHANNEL_5_2_1X 29
#define ADC_SINGLE_CHANNEL_1P22_VBG 30
#define ADC_SINGLE_CHANNEL_0_GND 31

/*		Prototypes		*/
void ADC_init(void);
u32 ADC_read(u8 channel);


#endif /* ADC_INTERFACE_H_ */