/*
 * DIO.c
 *
 * Created: 11/25/2026 11:15:42 AM
 *  Author: Zeinab
 */ 

#include "../../serv/STD_Macros.h"
#include "DIO.h"
#include "DIO_REG.h"

static volatile uint8 *DDR[4]  ={&DDRA,&DDRB,&DDRC,&DDRD};
static volatile uint8 *PORT[4] ={&PORTA,&PORTB,&PORTC,&PORTD};
static volatile uint8 *PIN[4]  ={&PINA,&PINB,&PINC,&PIND};

void DIO_vSetPinDir(uint8 u8CopyPin ,uint8 u8CopyDir){
	switch(u8CopyDir){
		case OUTPUT_PIN:
		SET_BIT(*DDR[u8CopyPin /8],(u8CopyPin %8));
		break;
		case INPUT_PIN:
		CLR_BIT(*DDR[u8CopyPin /8],(u8CopyPin %8));
		break;
	}
}
void DIO_vSetPinVal(uint8 u8CopyPin ,uint8 u8CopyVal){
	switch(u8CopyVal){
		case HIGH_PIN:
		SET_BIT(*PORT[u8CopyPin /8],(u8CopyPin %8));
		break;
		
		case LOW_PIN:
		CLR_BIT(*PORT[u8CopyPin /8],(u8CopyPin %8));
		break;
		
		case TOGGLE_PIN:
		TOG_BIT(*PORT[u8CopyPin /8],(u8CopyPin %8));
		break;
	}
}
uint8 DIO_u8GetPinVal(uint8 u8CopyPin){
	return (GET_BIT(*PIN[u8CopyPin /8],(u8CopyPin %8)));
}

void DIO_vSetPortDir(uint8 u8CopyPort ,uint8 u8CopyDir){
	*DDR[u8CopyPort] = u8CopyDir;
}
void DIO_vSetPortVal(uint8 u8CopyPort ,uint8 u8CopyVal){
	*PORT[u8CopyPort] = u8CopyVal;
}
uint8 DIO_u8GetPortVal(uint8 u8CopyPort){
	return *PIN[u8CopyPort];
}

void DIO_vSet_HIGHNIBBLE_Dir(uint8 u8CopyPort ,uint8 u8CopyDir){
	u8CopyDir &= 0x0F;
	u8CopyDir <<= 4 ;
	*DDR[u8CopyPort] &= 0x0F;
	*DDR[u8CopyPort] |= u8CopyDir;
	
}
void DIO_vSet_LOWNIBBLE_Dir(uint8 u8CopyPort ,uint8 u8CopyDir){
	u8CopyDir &= 0x0F ;
	*DDR[u8CopyPort] &= 0xF0;
	*DDR[u8CopyPort] |= u8CopyDir;
}
void DIO_vSet_HIGHNIBBLE_Val(uint8 u8CopyPort ,uint8 u8CopyVal){
	u8CopyVal &= 0x0F;
	u8CopyVal <<= 4 ;
	*PORT[u8CopyPort] &= 0x0F;
	*PORT[u8CopyPort] |= u8CopyVal;
}
void DIO_vSet_LOWNIBBLE_Val(uint8 u8CopyPort ,uint8 u8CopyVal){
	u8CopyVal &= 0x0F;
	*PORT[u8CopyPort] &= 0xF0;
	*PORT[u8CopyPort] |= u8CopyVal;
}
