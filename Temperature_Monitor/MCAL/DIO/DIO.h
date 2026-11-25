/*
 * DIO.h
 *
 * Created: 11/25/2026 11:15:29 AM
 *  Author: Zeinab
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../serv/STD_TYPE.h"

#define _PORTA    (uint8)0
#define _PORTB    (uint8)1
#define _PORTC    (uint8)2
#define _PORTD    (uint8)3

#define OUTPUT_PIN    (uint8)1
#define INPUT_PIN     (uint8)0

#define LOW_PIN     (uint8)0
#define HIGH_PIN    (uint8)1
#define TOGGLE_PIN  (uint8)2

#define OUTPUT_PORT  (uint8)0xFF
#define INPUT_PORT   (uint8)0x00

#define HIGH_PORT  (uint8)0xFF
#define LOW_PORT   (uint8)0x00

#define OUTPUT_NIBBLE  (uint8)0x0F
#define INPUT_NIBBLE   (uint8)0x00

#define HIGH_NIBBLE  (uint8)0x0F
#define LOW_NIBBLE   (uint8)0x00

typedef enum{
	PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
	PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
	PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
	PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7
}PIN_NUM;

void DIO_vSetPinDir(uint8 u8CopyPin ,uint8 u8CopyDir);
void DIO_vSetPinVal(uint8 u8CopyPin ,uint8 u8CopyVal);
uint8 DIO_u8GetPinVal(uint8 u8CopyPin);

void DIO_vSetPortDir(uint8 u8CopyPin ,uint8 u8CopyDir);
void DIO_vSetPortVal(uint8 u8CopyPin ,uint8 u8CopyVal);
uint8 DIO_u8GetPortVal(uint8 u8CopyPin);

void DIO_vSet_HIGHNIBBLE_Dir(uint8 u8CopyPort ,uint8 u8CopyDir);
void DIO_vSet_LOWNIBBLE_Dir(uint8 u8CopyPort ,uint8 u8CopyDir);
void DIO_vSet_HIGHNIBBLE_Val(uint8 u8CopyPort ,uint8 u8CopyVal);
void DIO_vSet_LOWNIBBLE_Val(uint8 u8CopyPort ,uint8 u8CopyVal);

#endif /* DIO_H_ */