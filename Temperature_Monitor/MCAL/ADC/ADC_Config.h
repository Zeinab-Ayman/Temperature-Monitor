/*
 * ADC_Config.h
 *
 * Created: 11/25/2026 2:51:33 PM
 *  Author: Zeinab
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define AREF       0
#define AVCC       1
#define	INTERNAL   2
#define ADC_VOLT   INTERNAL


#define DIV_FACTOR_2        (uint8)0x01
#define DIV_FACTOR_4        (uint8)0x02
#define DIV_FACTOR_8        (uint8)0x03
#define DIV_FACTOR_16       (uint8)0x04
#define DIV_FACTOR_32       (uint8)0x05
#define DIV_FACTOR_64       (uint8)0x06
#define DIV_FACTOR_128      (uint8)0x07

#define ADC_PRESCALER   DIV_FACTOR_64



#endif /* ADC_CONFIG_H_ */