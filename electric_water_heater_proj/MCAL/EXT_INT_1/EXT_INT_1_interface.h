/*
 * EXT_INT_1_interface.h
 *
 * Created: 2024-02-26 7:16:08 PM
 *  Author: asus
 */ 


#ifndef EXT_INT_1_INTERFACE_H_
#define EXT_INT_1_INTERFACE_H_

/*		Prototypes		*/
void INT1_init(void);
void INT1_enable();
void INT1_disable();
void INT1_setCallBack(func_ptr fptr);





#endif /* EXT_INT_1_INTERFACE_H_ */