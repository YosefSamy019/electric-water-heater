/*
 * app.c
 *
 * Created: 2024-02-26 10:52:29 PM
 *  Author: asus
 */ 

#include "app.h"

RGB_LED led;
STATE appState = offState;

u8 desiredTemp = INITIAL_DESIRED_TEMP;
u8 sensorTemp = INITIAL_DESIRED_TEMP;

u32 stateTimer = 0;

void APP_start(void){
	/*		MCAL		*/
	GIE_enable();
	EXT_INT_0_init();
	EXT_INT_1_init();
	EXT_INT_2_init();
	ADC_init();
	TIMER2_init();
	
	/*		HAL		*/
	HEATER_init();
	COOLER_init();
	LM35_init();
	SEV_SEG_init();
	RGB_LED_init(&led,COMMON_CATHODE,PC7,PC6,PC5);
	
	/*		SERVICES	*/
	SCHEDULER_init();
	
	// initial state is off
	APP_setState(offState);
	
	EXT_INT_0_setCallBack(App_UpBtnOnCLick);
	EXT_INT_1_setCallBack(App_DownOffBtnOnCLick);
	EXT_INT_2_setCallBack(App_OnOffBtnOnCLick);
	
	//get the desired temperature from EEPROM
	desiredTemp = EEPROM_readByte(EEPROM_TEMP_SET_LOCATION);
	if((desiredTemp > MAX_TEMP) || (desiredTemp < MIN_TEMP)){
		desiredTemp = INITIAL_DESIRED_TEMP;
	}
}

void APP_update(void){
	switch(appState){
		case offState:
				RGB_LED_turnOff(&led);
				HEATER_turnOff();
				COOLER_turnOff();
			break;
		case onState: 
			SEV_SEG_setDigit(SEV_SEG_DIGIT_2,sensorTemp%10);
			SEV_SEG_setDigit(SEV_SEG_DIGIT_1,sensorTemp/10);
						
			if(sensorTemp < desiredTemp - TEMP_COMPARSION_ERROR){
				COOLER_turnOff();
				HEATER_turnOn();
				SCHEDULER_addTask(APP_blinkLedTask,LED_BLINK_TIMER_HIGH_MS);
			}else if(sensorTemp > desiredTemp + TEMP_COMPARSION_ERROR){
				HEATER_turnOff();
				COOLER_turnOn();
				SCHEDULER_removeTask(APP_blinkLedTask);
				RGB_LED_turnOn(&led);
			}else{
				HEATER_turnOff();
				COOLER_turnOff();
				SCHEDULER_removeTask(APP_blinkLedTask);
				RGB_LED_turnOn(&led);
			}
			
			break;
		case temperatureSetState:
			SEV_SEG_setDigit(SEV_SEG_DIGIT_2,desiredTemp%10);
			SEV_SEG_setDigit(SEV_SEG_DIGIT_1,desiredTemp/10);
			
			RGB_LED_setColor(&led,TEMP_SET_STATE_COLOR);
			
			if(sensorTemp < desiredTemp - TEMP_COMPARSION_ERROR){
				COOLER_turnOff();
				HEATER_turnOn();
			}else if(sensorTemp > desiredTemp + TEMP_COMPARSION_ERROR){
				HEATER_turnOff();
				COOLER_turnOn();
			}else{
				HEATER_turnOff();
				COOLER_turnOff();
			}
			
			
			 if(stateTimer > TEMP_SET_STATE_MAX_TIME){
				 APP_setState(onState);
			 }
			break; 
	}
}

void APP_setState(STATE state){
	appState = state;
	stateTimer = 0;
	
	switch(state){
		case offState:
			SCHEDULER_clearAllTasks();
			SCHEDULER_disable();
		
			//on/off btn
			EXT_INT_2_enable();
			//up btn
			EXT_INT_0_disable();
			//down btn
			EXT_INT_1_disable();
			
			HEATER_turnOff();
			COOLER_turnOff();
			
			SEV_SEG_disableDigit(SEV_SEG_DIGIT_1);
			SEV_SEG_disableDigit(SEV_SEG_DIGIT_2);
			
			RGB_LED_turnOff(&led);
			
			break;
		case onState:
			//up btn
			EXT_INT_0_enable();
			//down btn
			EXT_INT_1_enable();
			SCHEDULER_enable();
			
			SEV_SEG_enableDigit(SEV_SEG_DIGIT_1);
			SEV_SEG_enableDigit(SEV_SEG_DIGIT_2);
			RGB_LED_setColor(&led,ON_STATE_COLOR);
			RGB_LED_turnOn(&led);
			
			SCHEDULER_removeTask(APP_blinkSevSegTask);
			SCHEDULER_addTask(APP_readSensorTask,SENSOR_READ_TIME);
			SCHEDULER_addTask(SEV_SEG_update,SEV_SEG_UPDATE_MS);
			SCHEDULER_addTask(APP_stateTimerTask,1);	//every 1 ms		
			break;
			
		case temperatureSetState:
			RGB_LED_setColor(&led,TEMP_SET_STATE_COLOR);
			RGB_LED_turnOn(&led);
			SCHEDULER_addTask(APP_blinkSevSegTask,SEV_SEG_BLINK_TIMER_HIGH_MS);
			break;
	}
	
}

void App_OnOffBtnOnCLick(){
	if(appState == offState){
		APP_setState(onState);
	}else{
		APP_setState(offState);
	}
}
void App_UpBtnOnCLick(){
	if(appState == temperatureSetState){
		desiredTemp += STEP_TEMP;
		if(desiredTemp>MAX_TEMP){
			desiredTemp = MAX_TEMP;
		}
		EEPROM_writeByte(EEPROM_TEMP_SET_LOCATION,desiredTemp);
	}
	APP_setState(temperatureSetState);
}

void App_DownOffBtnOnCLick(){
	if(appState == temperatureSetState){
		desiredTemp -= STEP_TEMP;
		if(desiredTemp < MIN_TEMP){
			desiredTemp = MIN_TEMP;
		}
		EEPROM_writeByte(EEPROM_TEMP_SET_LOCATION,desiredTemp);
	}
	APP_setState(temperatureSetState);
}

void APP_blinkSevSegTask(void){
	static u8 c=0;
	if(c==0){
		c=1;
		SEV_SEG_disableDigit(SEV_SEG_DIGIT_1);
		SEV_SEG_disableDigit(SEV_SEG_DIGIT_2);
		SCHEDULER_addTask(APP_blinkSevSegTask,SEV_SEG_BLINK_TIMER_LOW_MS);
	}else{	
		c=0;
		SEV_SEG_enableDigit(SEV_SEG_DIGIT_1);
		SEV_SEG_enableDigit(SEV_SEG_DIGIT_2);
		SCHEDULER_addTask(APP_blinkSevSegTask,SEV_SEG_BLINK_TIMER_HIGH_MS);
	}
}

void APP_blinkLedTask(void){
	static u8 c=0;
	if(c==0){
		c=1;
		RGB_LED_turnOff(&led);
		SCHEDULER_addTask(APP_blinkLedTask,LED_BLINK_TIMER_LOW_MS);
	}else{
		c=0;
		RGB_LED_turnOn(&led);
		SCHEDULER_addTask(APP_blinkLedTask,LED_BLINK_TIMER_HIGH_MS);
	}
}


void APP_stateTimerTask(void){
	stateTimer++;
}

void APP_readSensorTask(void){
	static u32 sensorTempSum = 0;
	static u8 counter =0;
	
	counter++;
	sensorTempSum += LM35_readTemp();
	
	if(counter == SENSOR_NO_REPEAT_READ){
		sensorTemp = sensorTempSum / SENSOR_NO_REPEAT_READ;
		sensorTempSum = 0;
		counter = 0;
	}
	
}