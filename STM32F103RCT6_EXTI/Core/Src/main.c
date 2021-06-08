#include "stm32f1xx.h"
/*****************************************************/
uint8_t led_status =0;
/*****************************************************/
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3);/* I/O port B clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<4);/* I/O port C clock enable */
}

void GPIO_Init(void)
{
	GPIOC->CRL |= 3UL<<0U;/* MODE */
	GPIOC->CRL &= ~(3UL<<2U); /*CNF*/


	GPIOB->CRH &= ~(3UL<<10U);
	GPIOB->CRH |= (2UL<<10U); /* Input mode with pull-up/ pull-down */
	GPIOB->ODR |= (1UL<<10U); /* pull-up */
}


void EXTI_Init(void)
{
	AFIO->EXTICR[2] |= 1UL<<8U;
	EXTI->IMR |= 1UL<<10U; /* Interrupt request from Line x is not masked */
	EXTI->EMR |= 1UL<<10U; /* Event request from Line x is not masked */
	EXTI->FTSR |= 1UL<<10U; /* Falling trigger enabled (for Event and Interrupt) for input line. */
	__NVIC_SetPriority(EXTI15_10_IRQn, 0);
	__NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
	if(led_status)led_status=0;
	else led_status = 1;

	if(led_status)
	{
		GPIOC->BSRR |= 1UL<<0U; /* Set PC0 */
	}
	else
	{
		GPIOC->BRR |= 1UL<<0U; /* Reset PC0 */
	}
	EXTI->PR |= 1UL<<10U;
}

int main(void)
{
	SystemClockInit();
	GPIO_Init();
	EXTI_Init();
	while(1)
	{

	}
}
