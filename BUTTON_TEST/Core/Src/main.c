#include<stm32f1xx.h>

void SytemClockInit(void)
{
	RCC->CR |= 1<<0; /* HSI enable */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate function I/O clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<2); /* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3);
	RCC->APB2ENR |= (uint32_t)(1<<4);
}

void GPIO_Init(void)
{
	GPIOB->CRH = 0; /* clear register */
	GPIOB->CRH |= (uint32_t)(2<<10);/* set input mode with the push-pull*/
	GPIOB->ODR |= (uint32_t)(1<<10);/* pull up */

	GPIOC->CRL |= (uint32_t)(3<<0); /* set output 50MHz*/
	GPIOC->CRL &= ~(uint32_t)(3<<2); /* set value = 0 */

//	GPIOB->CRH |= (uint32_t)(2<<14);
//	GPIOB->ODR |= (uint32_t)(1<<11);


}

void delay(uint8_t time)
{
	while(time--);
}
int main(void)
{
	uint8_t led_status = 0;
	SytemClockInit();
	GPIO_Init();
	while(1)
	{
		if((GPIOB->IDR) & (1UL<<10U) == 0) /* check BT status */
		{
			if(led_status)led_status = 0;
			else led_status = 1;

			if(led_status)
			{

				GPIOC->BSRR |= (1UL<<0U); /* set PC0 */
				while((GPIOB->IDR) & (1UL<<10U) == 0);
			}
			else
			{
				GPIOC->BRR |= (1UL<<0U); /* reset PC0 */
				while((GPIOB->IDR) & (1UL<<10U) == 0);
			}

		}
	}
}
