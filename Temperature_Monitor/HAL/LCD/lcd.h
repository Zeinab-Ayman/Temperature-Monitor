/*
 * lcd.h
 *
 * Created: 11/25/2026 11:40:56 PM
 *  Author: Zeinab
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../../serv/STD_TYPE.h"

#define CLEAR_DIS	0x01
#define RETURN_HOME	0x02
#define MODE_8BIT	0x38
#define MODE_4BIT	0x28
#define SET_DDRAM	0x80
#define SET_CGRAM	0x40
#define SHIFT_DIS_RIGHT	0x1C
#define SHIFT_DIS_LEFT	0x18
#define ENTRY_MODE_INC	0x06
#define ENTRY_MODE_DEC	0x04
#define DISPLAY_ON	0x0C
#define DISPLAY_OFF	0x08
#define CURSOR_ONBLINK	0x0F
#define CURSOR_OFFBLINK	0x0E

void Init_vLCD4bit(void);
void LCD_vMovecursor(uint8 u8CopyRow,uint8 u8CopyCol);
void LCD_vWriteChar(uint8 u8CopyChar);
void LCD_vWriteString(const uint8 *u8CopyStr);
void LCD_vWriteCMD(uint8 u8CopyCMD);
void LCD_vWriteInt(sint32 s32CopyInt);

#endif /* LCD_H_ */