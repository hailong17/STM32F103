#include<stm32f1xx.h>
/******************************************************/
#define msg "Hallo Wold!\n\r"
/******************************************************/
void SytemClockInit(void)
{
	RCC->CR |= 1<<0; /* HSI enable */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate function I/O clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<2); /* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<14); /* USART1 clock enable */
}
/******************************************************/
void UART_Init(void)
{
	USART1->CR1 |= (uint32_t)(1<<2); /* Receiver enable */
	USART1->CR1 |= (uint32_t)(1<<3); /* Transmit enable */
	USART1->CR1 |= (uint32_t)(1<<13); /* USART enable */
	USART1->BRR |= (uint32_t)(4<<4); /* mantissa of USARTDIV */
	USART1->BRR |= (uint32_t)(4<<0); /* fraction of USARTDIV */
}
/******************************************************/
void GPIO_Init(void)
{
	GPIOA->CRH |= (uint32_t)(2<<6); /* PA9 Alternate function output Push-pul */
	GPIOA->CRH |= (uint32_t)(3<<4); /* PA9 Max speed */
}
/******************************************************/
void UartTxMsg(uint8_t *data, uint8_t size)
{
	for(uint8_t i=0; i<size; i++) /* byte to byte */
	{
		USART1->DR = *(data+i);
		while((USART1->SR & (uint32_t)(1<<6)) == 0); /* Wait TC ==1 */
	}
}
/******************************************************/
void delay(uint32_t time)
{
	while(time--);
}
int main(void)
{
	SytemClockInit();
	UART_Init();
	GPIO_Init();
	while(1)
	{
		UartTxMsg((uint8_t*)msg, sizeof(msg));
		delay(72000);
	}
}
/******************************************************/
