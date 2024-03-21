/*
 * SEV_SEG_interface.h
 *
 * Created: 2024-02-26 6:27:04 PM
 *  Author: asus
 */ 


#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTERFACE_H_


/*		Digits number		*/
#define SEV_SEG_DIGIT_1 0
#define SEV_SEG_DIGIT_2 1

/*		prototypes		*/
void SEV_SEG_init(void);

void SEV_SEG_setDigit(u8 digitNo,u8 num);

void SEV_SEG_enableDigit(u8 digitNo);

void SEV_SEG_enableDot(u8 digitNo);

void SEV_SEG_disableDigit(u8 digitNo);

void SEV_SEG_disableDot(u8 digitNo);

void SEV_SEG_update(void);


#endif /* SEV_SEG_INTERFACE_H_ */