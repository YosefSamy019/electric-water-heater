/*
 * STD_TYPES.h
 *
 * Created: 2024-01-26 3:56:10 PM
 *  Author: asus
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL ((void*)0)

typedef  unsigned char	u8;
typedef  signed char	s8;

typedef  unsigned short u16;
typedef signed short	s16;

typedef  unsigned long  u32;
typedef signed long		s32;

typedef  unsigned long long u64;
typedef signed long long	s64;

typedef float f32;
typedef double f64;

typedef enum{
	false = 0,
	true = 1
} boolean;

typedef void(*func_ptr)(void);

#endif /* STD_TYPES_H_ */