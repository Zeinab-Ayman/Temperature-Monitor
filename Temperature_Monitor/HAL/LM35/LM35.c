/*
 * LM35.c
 *
 * Created: 11/25/2026 4:29:38 PM
 *  Author: Zeinab
 */ 


#include "LM35.h"
#include "../../MCAL/ADC/ADC.h"
#include "LM35_Config.h"

void LM35_vInit(void){
	Init_vADC();
}
sint16 LM35_u16ReadTemp(void){
	uint16 x  = ADC_u16ReadDigitalVal(LM35_CHANNEL);
	sint32  mv = ((sint32)x * LM35_VREF_MV) / LM35_ADC_STEPS;
	return (sint16)((mv - LM35_OFFSET_MV) / LM35_MV_PER_C);
}