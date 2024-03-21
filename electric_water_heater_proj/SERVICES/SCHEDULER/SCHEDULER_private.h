/*
 * SCHEDULER_private.h
 *
 * Created: 2024-02-26 10:03:42 PM
 *  Author: asus
 */ 


#ifndef SCHEDULER_PRIVATE_H_
#define SCHEDULER_PRIVATE_H_


typedef struct {
	func_ptr function;
	u32 periodicity;
// 	boolean readyToExecute;
}Task;


#endif /* SCHEDULER_PRIVATE_H_ */