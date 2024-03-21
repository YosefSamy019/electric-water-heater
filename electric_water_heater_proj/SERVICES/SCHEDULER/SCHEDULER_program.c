/*
 * SCHEDULER_program.c
 *
 * Created: 2024-02-26 9:53:14 PM
 *  Author: asus
 */ 

/*		LIB		*/
#include "../../LIB/STD_TYPES.h"

/*		MCAL		*/
#include "../../MCAL/TIMER_2/TIMER_2_interface.h"

/*		Driver		*/
#include "SCHEDULER_config.h"
#include "SCHEDULER_interface.h"
#include "SCHEDULER_private.h"


static Task tasks[SCHEDULER_MAX_TASKS_NO];
static u8 tasksCounter = 0;

static void SCHEDULER_ISR(void);

void SCHEDULER_init(void){
	TIMER2_setCallback(SCHEDULER_ISR);
}

void SCHEDULER_addTask(func_ptr function,u32 periodicity){	
	if(tasksCounter < SCHEDULER_MAX_TASKS_NO){
		//check if task is added before
		u32 i=0;
		for(;i<tasksCounter;i++){
			if(tasks[i].function == function){
				break;
			}
		}
		
		tasks[i].function = function;
		tasks[i].periodicity = periodicity;
		
		//increment the counter is the task is not repeated
		if(i == tasksCounter)tasksCounter++;
	}
}

void SCHEDULER_removeTask(func_ptr function){
	u32 i=0;
	
	if(tasksCounter > 0){
		for(;i<tasksCounter;i++){
			if(tasks[i].function  == function){
				//remove task
				//clone last task in the array instead of task at index i then decrease tasks counter by one
				tasks[i] = tasks[tasksCounter-1];
				tasksCounter = tasksCounter - 1;
				break;
			}
		}
	}
}

void SCHEDULER_clearAllTasks(void){
	tasksCounter = 0;
}


void SCHEDULER_enable(void){
		TIMER2_setCallback(SCHEDULER_ISR);
}

void SCHEDULER_disable(void){
	TIMER2_setCallback(NULL);
}

static void SCHEDULER_ISR(void){
	static u32 counter = 0;
	u8 i =0;
	
	for(;i<tasksCounter;i++){
		if(counter % tasks[i].periodicity == 0){
			tasks[i].function();		
		}
	}
	counter++;
}