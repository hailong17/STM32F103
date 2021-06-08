/*
 * board_7seg.c
 *
 *  Created on: Sep 19, 2020
 *      Author: quocl
 */
#include "board_7seg.h"

extern uint32_t num;
uint8_t LED[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void HC595_Init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->MAPR = AFIO_MAPR_SWJ_CFG_1;
}

void HC595_Write(uint8_t data)
{
	for(int i=0; i<8; i++)
	{
		if(((data<<i)&0x80) == 0x80)
		{
			HC595_DATA_PORT->BSRR |= HC595_DATA_PIN; /* 1 */
		}
		else
		{
			HC595_DATA_PORT->BRR |= HC595_DATA_PIN; /* 0 */
		}
		HC595_CLK_PORT->BSRR |= HC595_CLK_PIN; /* 1 */
		HC595_CLK_PORT->BRR |= HC595_CLK_PIN; /* 0 */
	}
}

void OutLed(void)
{
	HC595_LAT_PORT->BSRR |= HC595_LAT_PIN; /* 1 */
	HC595_LAT_PORT->BRR |= HC595_LAT_PIN; /* 0 */
}

void Display(uint8_t index)
{
	switch(index)
	{
		case 0:
			HC595_Write(LED[num/1000]);
			HC595_Write(0x10);
			OutLed();
			break;
		case 1:
			HC595_Write(LED[(num%1000)/100]);
			HC595_Write(0x20);
			OutLed();
			break;
		case 2:
			HC595_Write(LED[((num%1000)%100)/10]);
			HC595_Write(0x40);
			OutLed();
			break;
		case 3:
			HC595_Write(LED[((num%1000)%100)%10]);
			HC595_Write(0x80);
			OutLed();
			break;
	}
}
