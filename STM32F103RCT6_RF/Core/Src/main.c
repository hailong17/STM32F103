#include "stm32f1xx.h"
//_____________________________________________________________________________________________________________________________
void maHoaBit(uint8_t bit);
void SystemClock_Init(void);
void GPIO_Init(void);
void maHoaByte(char byte);
void RF314_SendString(char *data);
void RF314_Start(void);
void RF314_Stop(void);
#define msg "Hello wordl!"
void delay(uint32_t time);
//_______________________________________________________________________________________________________________________________
int main(void)
{
	SystemClock_Init();
	GPIO_Init();
	while(1)
	{
		//maHoaByte(0x41);
		RF314_SendString((char*)msg);
	}
	return 0;
}
//__________________________________________________________________________________________________________________________________
void SystemClock_Init(void)
{
	RCC->CR|=(1UL<<0U);						/* EN internal clock */
	while((RCC->CR &~(1UL<<1U))==0);
	RCC->APB2ENR |= (1UL<<4U);				/* EN clock for GPIO C*/
}
void GPIO_Init(void)
{
	GPIOC->CRL |=(3UL<<0U);					/* PC0 mode output with speed max */
	GPIOC->CRL &= ~(3UL<<2U);				/* CNF output push-pull */
}
void maHoaBit(uint8_t bit)
{
	if(bit)
	{
		GPIOC->BSRR|=1ul<<0u;
		delay(500000);
		GPIOC->BRR|=1ul<<0u;
		delay(500000);
	}
	else
	{
		GPIOC->BRR|=1ul<<0u;
		delay(500000);
		GPIOC->BSRR|=1ul<<0u;;
		delay(500000);
	}
}
void maHoaByte(char byte)
{
	for(int i=0;i<8;i++)
	{
		maHoaBit((byte>>i)&(0x01));
	}
}
void RF314_SendString(char *data)
{
	while(*data)
	{
		RF314_Start();
		maHoaByte(*data++);
		RF314_Stop();
	}
}
void RF314_Start(void)
{
	maHoaBit(1);
	maHoaBit(1);
	maHoaBit(1);
}
void RF314_Stop(void)
{
	maHoaBit(1);
	maHoaBit(1);
	maHoaBit(0);
	maHoaBit(0);
}
void delay(uint32_t time)
{
	while(time--);
}
