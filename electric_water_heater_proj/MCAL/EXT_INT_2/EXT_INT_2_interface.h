/*
 * EXT_INT_2_interface.h
 *
 * Created: 2024-02-26 7:17:40 PM
 *  Author: asus
 */ 


#ifndef EXT_INT_2_INTERFACE_H_
#define EXT_INT_2_INTERFACE_H_

/*		Prototypes		*/
void EXT_INT_2_init(void);
void EXT_INT_2_enable();
void EXT_INT_2_disable();
void EXT_INT_2_setCallBack(func_ptr fptr);


#endif /* EXT_INT_2_INTERFACE_H_ */