/*
 * ADC.c
 *
 * Created: 11/25/2026 1:20:58 PM
 *  Author: Zeinab
 */ 


#include "../../serv/STD_Macros.h"
#include "ADC_Reg.h"
#include "ADC_Config.h"
#include "ADC.h"


void Init_vADC(void){
	#if ADC_VOLT == AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif ADC_VOLT == AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif ADC_VOLT == INTERNAL
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#endif
	/*SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);*/
	ADCSRA &= 0xF8;
	ADCSRA |= ADC_PRESCALER;
	SET_BIT(ADCSRA,ADEN);
}
uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy){
	uint16 res;
	ADMUX &= 0xE0;
	ADMUX |= ChannelCopy;
	SET_BIT(ADCSRA,ADSC);
	while((GET_BIT(ADCSRA,ADIF)) == 0);
	SET_BIT(ADCSRA, ADIF);
	res = ADCL;
	res |= ((uint16)ADCH << 8);
	return res;
}

void ADC_vInterruptEnable(void){
	SET_BIT(ADCSRA, ADIE);
	SET_BIT(SREG, I_BIT); 
}
void ADC_vInterruptDisable(void) {
	CLR_BIT(ADCSRA, ADIE); 
}