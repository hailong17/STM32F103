#include "stm32f1xx.h"
/*****************************************************/
#define msg "Hello World!\n\r"
/*****************************************************/
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<14);/* USART1 clock enabled */
}
/*****************************************************/
void UART_Init(void)
{
	USART1->CR1 |= (uint32_t)(1<<2); /* Receiver is enabled and begins searching for a start bit */
	USART1->CR1 |= (uint32_t)(1<<3); /* Transmitter is enabled */
	USART1->CR1 |= (uint32_t)(1<<13); /* USART enabled */
	USART1->BRR |= (uint32_t)(4<<4); /* Mantissa */
	USART1->BRR |= (uint32_t)(5<<0); /* Fraction */

}
/*****************************************************/
void GPIO_Init(void)
{
	GPIOA->CRH |= (uint32_t)(2<<6); /* PA9 is Alternate function output Push-pull */
	GPIOA->CRH |= (uint32_t)(3<<4); /* PA9 max speed */
}
/*****************************************************/
void UartTxMsg(uint8_t *data, uint8_t size)
{
	for(uint8_t i=0; i<size; i++)
	{
		USART1->DR = *(data+i);
		while((USART1->SR & (uint32_t)(1<<6))==0); /* Wait TC ==1 */
	}
}
/*****************************************************/
void delay(uint32_t time)
{
	while(time--);
}
int main(void)
{
	SystemClockInit();
	UART_Init();
	GPIO_Init();
	while(1)
	{
		UartTxMsg((uint8_t*)msg, sizeof(msg));
		delay(72000);
	}
}
/*****************************************************/
