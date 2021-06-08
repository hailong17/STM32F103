#include<stm32f1xx.h>
uint8_t led_status = 0;
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0); /* Wait clock stable */
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3); /* I/O port B clock enabled */
	RCC->APB2ENR |= (1UL<<4U); /* I/O port C clock enabled */
}

void GPIO_Init(void)
{
		GPIOB->CRH &= ~(uint32_t)(3<<10);
		GPIOB->CRH |= (uint32_t)(2<<10);/* set input mode with the push-pull*/
		GPIOB->ODR |= (uint32_t)(1<<10);/* pull up */

		GPIOC->CRL |= (uint32_t)(3<<0); /* set output 50MHz*/
		GPIOC->CRL &= ~(uint32_t)(3<<2); /* CNF */
}

void EXTI15_10_IRQHandler(void)
{
	if(led_status)led_status = 0;
		else led_status = 1;

		if(led_status)
		{

			GPIOC->BSRR |= (1UL<<0U); /* set PC0 */
			//while((GPIOB->IDR) & (1UL<<10U) == 0);
		}
		else
		{
			GPIOC->BRR |= (1UL<<0U); /* reset PC0 */
			//while((GPIOB->IDR) & (1UL<<10U) == 0);
		}
		EXTI->PR |= 1UL<<10; /* selected trigger request occurred */
}

void EXTI_Init(void)
{
	AFIO->EXTICR[2] |= 1UL<<8U;

	EXTI->IMR |= 1UL<<10U;
	EXTI->EMR |= 1UL<<10U;
	EXTI->FTSR |= 1UL<<10U;
	__NVIC_SetPriority(EXTI15_10_IRQn, 0);
	__NVIC_EnableIRQ(EXTI15_10_IRQn);
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
