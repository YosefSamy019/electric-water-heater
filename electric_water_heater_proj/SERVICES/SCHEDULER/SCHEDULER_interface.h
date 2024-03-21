/*
 * SCHEDULER_interface.h
 *
 * Created: 2024-02-26 9:53:05 PM
 *  Author: asus
 */ 


#ifndef SCHEDULER_INTERFACE_H_
#define SCHEDULER_INTERFACE_H_

#define SCHEDULER_NULL_ID 0


/*		Prototypes		*/
void SCHEDULER_init(void);
void SCHEDULER_addTask(func_ptr function,u32 periodicity);
void SCHEDULER_removeTask(func_ptr function);
void SCHEDULER_clearAllTasks(void);
void SCHEDULER_enable(void);
void SCHEDULER_disable(void);

#endif /* SHEDULER_INTERFACE_H_ */