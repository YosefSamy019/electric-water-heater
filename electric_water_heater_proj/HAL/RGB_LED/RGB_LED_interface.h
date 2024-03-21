/*
 * RGB_LED_interface.h
 *
 * Created: 2024-02-26 5:47:18 PM
 *  Author: asus
 */ 


#ifndef RGB_LED_INTERFACE_H_
#define RGB_LED_INTERFACE_H_

/*		RGB Typed		*/
#define COMMON_ANODE   1
#define COMMON_CATHODE 0

/*		Colors		*/
/*the 0-bit is blue, 1-bit is green, 2-bit is red, each (1-> on, 0-> off)*/
#define COLOR_RED		0b00000100
#define COLOR_GREEN		0b00000010
#define COLOR_BLUE		0b00000001
#define COLOR_YELLOW	0b00000110
#define COLOR_CYAN		0b00000011
#define COLOR_MAGENTA	0b00000101
#define COLOR_WHITE		0b00000111
#define COLOR_BLACK		0b00000000

/*		struct model*/
typedef struct {
	u8 r_pin;
	u8 g_pin;
	u8 b_pin;
	u8 type;
	u8 color;
}RGB_LED;

/*		prototypes		*/
void RGB_LED_init(RGB_LED* led,u8 type,u8 r_pin, u8 g_pin, u8 b_pin);
void RGB_LED_turnOff(RGB_LED* led);
void RGB_LED_turnOn(RGB_LED* led);
void RGB_LED_setColor(RGB_LED* led,u8 color);



#endif /* RGB_LED_INTERFACE_H_ */