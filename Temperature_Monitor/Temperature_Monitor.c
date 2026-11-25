/*
 * Temperature_Monitor.c
 *
 * Created: 11/25/2026 4:17:23 PM
 *  Author: Zeinab
 */ 


#include "HAL/LCD/lcd.h"
#include "HAL/LM35/LM35.h"

int main(void)
{
	sint16 temp;

	Init_vLCD4bit();
	LM35_vInit();
	LCD_vWriteString("Temp = ");

	while (1)
	{
		temp = LM35_u16ReadTemp();

		LCD_vMovecursor(1, 8);
		LCD_vWriteInt(temp);          
		LCD_vWriteChar(0xDF);         
		LCD_vWriteChar('C');
		LCD_vWriteString((const uint8*)"   ");      
	}
}