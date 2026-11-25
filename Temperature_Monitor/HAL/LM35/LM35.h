/*
 * LM35.h
 *
 * Created: 11/25/2026 4:29:19 PM
 *  Author: Zeinab
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "../../serv/STD_TYPE.h"

void   LM35_vInit(void);
sint16 LM35_u16ReadTemp(void);



#endif /* LM35_H_ */