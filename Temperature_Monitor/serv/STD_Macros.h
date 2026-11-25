/*
 * STD_Macros.h
 *
 * Created: 9/24/2026 10:50:24 PM
 *  Author: Zeinab
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REG_SIZE 8
#define SET_BIT(reg,bit)	reg |= (1<<bit)
#define CLR_BIT(reg,bit)	reg &= (~(1<<bit))
#define TOG_BIT(reg,bit)	reg ^= (1<<bit)
#define GET_BIT(reg,bit)	(reg>>bit) &1

#endif /* STD_MACROS_H_ */