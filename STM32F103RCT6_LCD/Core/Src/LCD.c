#include "LCD.h"
void LCD_Init(void)
{
	HAL_Delay(30);

	LCD_Write(0,0x02);			// 4bit mode
	LCD_Write(0,0x28);			// Init of 16x2 LCD in 4bit mode
	LCD_Write(0,0x0C);			// Display ON cursor OFF
	LCD_Write(0,0x06);			// Auto Increment cursor
	LCD_Write(0,0x01);			// Clear display
	LCD_Write(0,0x80);			// Cursor at home position
}

void LCD_Write(uint8_t type, uint8_t data)
{
	HAL_Delay(2);
	if(type)
	{
		PIN_HIGH(RS_PORT,RS_PIN);								// Write data
	}
	else
		PIN_LOW(RS_PORT,RS_PIN);								// Write data

/* ____________________________Write 4bit high_____________________________________________ */

	if(data & 0x80)
	{
		PIN_HIGH(D7_PORT,D7_PIN);
	} else
	{
		PIN_LOW(D7_PORT,D7_PIN);
	}

	if(data & 0x40)
	{
		PIN_HIGH(D6_PORT,D6_PIN);
	} else
	{
		PIN_LOW(D6_PORT,D6_PIN);
	}

	if(data & 0x20)
	{
		PIN_HIGH(D5_PORT,D5_PIN);
	} else
	{
		PIN_LOW(D5_PORT,D5_PIN);
	}

	if(data & 0x10)
	{
		PIN_HIGH(D4_PORT,D4_PIN);
	} else
	{
		PIN_LOW(D4_PORT,D4_PIN);
	}

	PIN_HIGH(EN_PORT,EN_PIN);
	PIN_LOW(EN_PORT,EN_PIN);

/* ____________________________Write 4bit low_____________________________________________ */

	if(data & 0x08)
	{
		PIN_HIGH(D7_PORT,D7_PIN);
	} else
	{
		PIN_LOW(D7_PORT,D7_PIN);
	}

	if(data & 0x04)
	{
		PIN_HIGH(D6_PORT,D6_PIN);
	} else
	{
		PIN_LOW(D6_PORT,D6_PIN);
	}

	if(data & 0x02)
	{
		PIN_HIGH(D5_PORT,D5_PIN);
	} else
	{
		PIN_LOW(D5_PORT,D5_PIN);
	}

	if(data & 0x01)
	{
		PIN_HIGH(D4_PORT,D4_PIN);
	} else
	{
		PIN_LOW(D4_PORT,D4_PIN);
	}

	PIN_HIGH(EN_PORT,EN_PIN);
	PIN_LOW(EN_PORT,EN_PIN);
}

void LCD_Puts(uint8_t x, uint8_t y, int8_t *string)
{
	switch (x)
	{
	case 1:
		LCD_Write(0, 0x80+y);
		break;
	case 2:
		LCD_Write(0, 0xC0+y);
		break;
	}

	while(*string)
	{
		LCD_Write(1, *string);
		string++;
	}
}

void LCD_Clear(void)
{
	LCD_Write(0, 0x01);
}
