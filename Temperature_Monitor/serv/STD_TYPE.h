/*
 * STD_TYPE.h
 *
 * Created: 10/1/2026 3:26:13 PM
 *  Author: Zeinab
 */ 


#ifndef STD_TYPE_H_
#define STD_TYPE_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef signed long long int sint64;

typedef float f32;
typedef double f64;

#endif /* STD_TYPE_H_ */