/*
 * lcd.c
 *
 * Created: 11/25/2026 11:40:45 PM
 *  Author: Zeinab
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "lcd_Config.h"
#include "lcd.h"
#include <util/delay.h>

static void send_falling_edge(void){
	DIO_vSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vSetPinVal(E,LOW_PIN);
	_delay_ms(1);
}

void Init_vLCD4bit(void){
	#if LCD_NIBBLE == LCD_HIGHNIBBLE
	DIO_vSet_HIGHNIBBLE_Dir(LCD_PORT,OUTPUT_NIBBLE);
	#else
	DIO_vSet_LOWNIBBLE_Dir(LCD_PORT,OUTPUT_NIBBLE);
	#endif
	DIO_vSetPinDir(RS,OUTPUT_PIN);
	DIO_vSetPinDir(E,OUTPUT_PIN);
	_delay_ms(40);
	
	DIO_vSetPinVal(RS,LOW_PIN);
	#if LCD_NIBBLE == LCD_HIGHNIBBLE
	DIO_vSet_HIGHNIBBLE_Val(LCD_PORT, 0x02);
	#else
	DIO_vSet_LOWNIBBLE_Val(LCD_PORT, 0x02);
	#endif
	send_falling_edge();
	
	LCD_vWriteCMD(MODE_4BIT);
	_delay_ms(1);
	LCD_vWriteCMD(DISPLAY_ON);
	_delay_ms(1);
	LCD_vWriteCMD(CLEAR_DIS);
	_delay_ms(2);
	LCD_vWriteCMD(ENTRY_MODE_INC);
}
void LCD_vWriteChar(uint8 u8CopyChar){
	DIO_vSetPinVal(RS,HIGH_PIN);
	#if LCD_NIBBLE == LCD_HIGHNIBBLE
	DIO_vSet_HIGHNIBBLE_Val(LCD_PORT, u8CopyChar >> 4);
	send_falling_edge();
	DIO_vSet_HIGHNIBBLE_Val(LCD_PORT, u8CopyChar & 0x0F);
	send_falling_edge();
	#else
	DIO_vSet_LOWNIBBLE_Val(LCD_PORT, u8CopyChar >> 4);
	send_falling_edge();
	DIO_vSet_LOWNIBBLE_Val(LCD_PORT, u8CopyChar & 0x0F);
	send_falling_edge();
	#endif
}
void LCD_vWriteCMD(uint8 u8CopyCMD){
	DIO_vSetPinVal(RS,LOW_PIN);
	#if LCD_NIBBLE == LCD_HIGHNIBBLE
	DIO_vSet_HIGHNIBBLE_Val(LCD_PORT, u8CopyCMD >> 4);
	send_falling_edge();

	DIO_vSet_HIGHNIBBLE_Val(LCD_PORT, u8CopyCMD & 0x0F);
	send_falling_edge();
	
	#else
	DIO_vSet_LOWNIBBLE_Val(LCD_PORT, u8CopyCMD >> 4);
	send_falling_edge();

	DIO_vSet_LOWNIBBLE_Val(LCD_PORT, u8CopyCMD & 0x0F);
	send_falling_edge();
	#endif
}

void LCD_vMovecursor(uint8 u8CopyRow,uint8 u8CopyCol){
	if(u8CopyRow < 1 || u8CopyRow > 2 || u8CopyCol > 16 || u8CopyCol < 1){
		LCD_vWriteCMD(0x80);
	}
	else{
		if (u8CopyRow == 1)
		LCD_vWriteCMD(0x80 + u8CopyCol-1);
		else
		LCD_vWriteCMD(0xC0 + u8CopyCol-1);
	}
}
void LCD_vWriteString(const uint8 *u8CopyStr){
	uint8 i = 0;
	for(i = 0 ; u8CopyStr[i] != '\0' ; i++){
		LCD_vWriteChar(u8CopyStr[i]);
	}
}
void LCD_vWriteInt(sint32 s32CopyInt){
	uint8 arr[10];
	sint8 i = 0;
	if(s32CopyInt == 0){
		LCD_vWriteChar('0');
		return;
	}
	if(s32CopyInt < 0){
		LCD_vWriteChar('-');
		s32CopyInt = -s32CopyInt;
	}
	while (s32CopyInt > 0) {
		arr[i] = (s32CopyInt % 10) + '0';
		s32CopyInt /= 10;
		i++;
	}
	for (i = i - 1; i >= 0; i--) {
		LCD_vWriteChar(arr[i]);
	}
}