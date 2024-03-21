/*
 * DELAY_program.c
 *
 * Created: 2024-02-26 5:36:31 PM
 *  Author: asus
 */ 


/*		LIB		*/
#include "../../LIB/STD_TYPES.h"

/*		DRIVER		*/
#include "DELAY_interface.h"

/*		OTHER		*/
#define F_CPU 16000000ul
#include <util/delay.h>

void DELAY_milli(u32 ms){
	while(ms>0){
		if(ms >= 1000){
			_delay_ms(1000);
			ms -= 1000;
		}
		else if(ms >= 100){
			_delay_ms(100);
			ms -= 100;
		}else if(ms >= 10){
			_delay_ms(10);
			ms -= 10;
		}else{
			_delay_ms(1);
			ms -= 1;
		}
	}
}

void DELAY_micro(u32 us){
	while(us>0){
		if(us >= 1000){
			_delay_us(1000);
			us -= 1000;
		}
		else if(us >= 100){
			_delay_us(100);
			us -= 100;
		}else if(us >= 10){
			_delay_us(10);
			us -= 10;
		}else{
			_delay_us(1);
			us -= 1;
		}
	}
}