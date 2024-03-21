/*
 * app.h
 *
 * Created: 2024-02-26 10:52:19 PM
 *  Author: asus
 */ 


#ifndef APP_H_
#define APP_H_

/*		LIB		*/
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DELAY/DELAY_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXT_INT_0/EXT_INT_0_interface.h"
#include "../MCAL/EXT_INT_1/EXT_INT_1_interface.h"
#include "../MCAL/EXT_INT_2/EXT_INT_2_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIMER_2/TIMER_2_interface.h"
#include "../MCAL/EEPROM/EEPROM_interface.h"

/*		HAL		*/
#include "../HAL/RGB_LED/RGB_LED_interface.h"
#include "../HAL/SEV_SEG/SEV_SEG_interface.h"
#include "../HAL/HEATER/HEATER_interface.h"
#include "../HAL/COOLER/COOLER_interface.h"
#include "../HAL/LM35/LM35_interface.h"

/*		SERVICES		*/
#include "../SERVICES/SCHEDULER/SCHEDULER_interface.h"


/*		App States		*/
typedef enum{
	offState,
	onState,
	temperatureSetState
}STATE;

/*		MACROS		*/
#define MIN_TEMP 35						 //Minimum temperature then can be set
#define MAX_TEMP 75						 //Maximum temperature then can be set
#define STEP_TEMP 5						 //step temperature when press on UP pr Down Btn

#define SEV_SEG_UPDATE_MS 1				 //Periodicity of updating the 7-seg display
#define TEMP_SET_STATE_MAX_TIME 5000	 //The Time taken to exit from Temperature set mode
#define SENSOR_READ_TIME 100			 //Periodicity of sensing the heat sensor
#define SENSOR_NO_REPEAT_READ 10		 //The numbers of sensing the heat when calculate the average
#define INITIAL_DESIRED_TEMP 60			 //The initial set temp when first time run the system
#define TEMP_COMPARSION_ERROR 5			 //The allowed error when compare the desired temp with sensor read

#define SEV_SEG_BLINK_TIMER_HIGH_MS 700  //Time High of Blinking the 7-seg when in Temperature set mode
#define SEV_SEG_BLINK_TIMER_LOW_MS 300   //Time Low of Blinking the 7-seg when in Temperature set mode

#define LED_BLINK_TIMER_HIGH_MS 700		 //Time High of Blinking RGB led when the heater is on
#define LED_BLINK_TIMER_LOW_MS 300		 //Time Low of Blinking RGB led when the heater is on

/*		State Colors		*/
#define ON_STATE_COLOR COLOR_GREEN		 //the color of RGB LED when become in on state
#define TEMP_SET_STATE_COLOR COLOR_BLUE  //the color of RGB LED when become in temp set state

/*		EEPROM			*/
#define EEPROM_TEMP_SET_LOCATION 0x00    //location of desired temp data in the internal EEPROM

/*		State Management	*/
void APP_start(void);
void APP_update(void);
void APP_setState(STATE state);

/*		ISR		*/
void App_OnOffBtnOnCLick();
void App_UpBtnOnCLick();
void App_DownOffBtnOnCLick();

/*		TASKS		*/
void APP_blinkSevSegTask(void);
void APP_stateTimerTask(void);
void APP_readSensorTask(void);
void APP_blinkLedTask(void);


#endif /* APP_H_ */