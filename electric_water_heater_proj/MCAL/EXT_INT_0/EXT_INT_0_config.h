/*
 * EXT_INT_0_config.h
 *
 * Created: 2024-02-26 7:15:42 PM
 *  Author: asus
 */ 


#ifndef EXT_INT_0_CONFIG_H_
#define EXT_INT_0_CONFIG_H_


/*		sense control		*/
#define INT0_SENSE_LOW_LEVEL  0x00
#define INT0_SENSE_ANY_LOGIC_CHANGE 0x01
#define INT0_SENSE_FALLING_EDGE 0x02
#define INT0_SENSE_RISING_EDGE 0x03
#define INT0_SENSE_CONTROL INT0_SENSE_FALLING_EDGE


#endif /* EXT_INT_0_CONFIG_H_ */