/*
 * ADC_Reg.h
 *
 * Created: 11/25/2026 1:21:24 PM
 *  Author: Zeinab
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#include "../../serv/STD_TYPE.h"

#define ADMUX    *((volatile uint8 *)0x27)
#define ADCSRA   *((volatile uint8 *)0x26)
#define ADCH     *((volatile uint8 *)0x25)
#define ADCL     *((volatile uint8 *)0x24)
#define SREG     *((volatile uint8 *)0x5F)

/*-------ADMUX_REG--------*/
#define MUX0    (uint8)0
#define MUX1    (uint8)1
#define MUX2    (uint8)2
#define MUX3    (uint8)3
#define MUX4    (uint8)4
#define ADLAR   (uint8)5
#define REFS0   (uint8)6
#define REFS1   (uint8)7


/*------ADCSRA-------*/
#define ADEN     (uint8)7
#define ADSC     (uint8)6
#define ADATE    (uint8)5
#define ADIF     (uint8)4
#define ADIE     (uint8)3
#define ADPS2    (uint8)2
#define ADPS1    (uint8)1
#define ADPS0    (uint8)0

/*-------SREG-------*/
#define I_BIT   (uint8)7



#endif /* ADC_REG_H_ */