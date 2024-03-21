/*
 * EXT_INT_0_interface.h
 *
 * Created: 2024-02-26 7:15:31 PM
 *  Author: asus
 */ 


#ifndef EXT_INT_0_INTERFACE_H_
#define EXT_INT_0_INTERFACE_H_


/*		prototypes		*/
void EXT_INT_0_init(void);
void EXT_INT_0_enable();
void EXT_INT_0_disable();
void EXT_INT_0_setCallBack(func_ptr fptr);




#endif /* EXT_INT_0_INTERFACE_H_ */