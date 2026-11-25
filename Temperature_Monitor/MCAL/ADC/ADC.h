/*
 * ADC.h
 *
 * Created: 11/25/2026 1:21:35 PM
 *  Author: Zeinab
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../serv/STD_TYPE.h"

typedef enum{
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7,
	CHANNEL8
}ADC_CHANNEL;


void Init_vADC(void);
uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy);


void ADC_vInterruptEnable(void);
void ADC_vInterruptDisable(void);



#endif /* ADC_H_ */