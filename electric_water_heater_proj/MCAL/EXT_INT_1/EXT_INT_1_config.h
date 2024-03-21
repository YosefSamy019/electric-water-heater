/*
 * EXT_INT_1_config.h
 *
 * Created: 2024-02-26 7:16:20 PM
 *  Author: asus
 */ 


#ifndef EXT_INT_1_CONFIG_H_
#define EXT_INT_1_CONFIG_H_

/*		sense control		*/
#define INT1_SENSE_LOW_LEVEL  0x00
#define INT1_SENSE_ANY_LOGIC_CHANGE 0x01
#define INT1_SENSE_FALLING_EDGE 0x02
#define INT1_SENSE_RISING_EDGE 0x03
#define INT1_SENSE_CONTROL INT1_SENSE_FALLING_EDGE


#endif /* EXT_INT_1_CONFIG_H_ */