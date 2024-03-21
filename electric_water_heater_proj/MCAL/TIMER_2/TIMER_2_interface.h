/*
 * TIMER_2_interface.h
 *
 * Created: 2024-02-26 9:29:27 PM
 *  Author: asus
 */ 

#ifndef TIMER_2_INTERFACE_H_
#define TIMER_2_INTERFACE_H_

void TIMER2_init(void);

#if TIMER2_MODE_SELECT == TIMER2_MODE_NORMAL || TIMER2_MODE_SELECT == TIMER2_MODE_CTC
void TIMER2_setCallback(func_ptr fptr);
#endif

#if TIMER2_MODE_SELECT == TIMER2_MODE_FAST_PWM || TIMER2_MODE_SELECT == TIMER2_MODE_PHASE_CORRECT
//dutyCycle range [0.0, 1.0]
void TIMER2_setDutyCucle(f32 dutyCycle);
#endif





#endif /* TIMER_2_INTERFACE_H_ */