#include<stm32f1xx.h>

/******************************************************************/
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0); /* Wait clock stable */
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3); /* I/O port B clock enabled */
	RCC->APB2ENR |= (1UL<<4U); /* I/O port C clock enabled */
}
/******************************************************************/

void GPIO_Init(void)
{
	 GPIOB->CRH = 0;
	 GPIOB->CRH |= (uint32_t)(2<<10); /* Input with pull-up / pull-down */
	 GPIOB->CRH |= (uint32_t)(2<<14); /* Input with pull-up / pull-down */
	 GPIOB->ODR |= 1UL<<10U; /* PULL UP */
	 GPIOB->ODR |= 1UL<<11U; /* PULL UP */
	 /******************************************************************/
	 GPIOC->CRL |= 3UL<<0U;



}
/******************************************************************/
void delay(uint32_t time)
{
	while(time--);
}
/******************************************************************/

int main(void)
{
	uint32_t i=0;
	uint8_t status;
	SystemClockInit();
	GPIO_Init();
	while(1)
	{
		if((GPIOB->IDR)&(1UL<<10) == 0) /* PB10 */
		{
			if(status == 1)status = 0; /* dao trang thai */
			else status = 1;
			if(status ==1)
			{
				GPIOC->ODR |= 1UL<<10U; /* ENABLE LED PC1 */
			}
			else
			{
				GPIOC->ODR &= ~(1UL<<10U); /* ENABLE LED PC1 */
			}

			while((GPIOB->IDR)&(1UL<<10U) == 0);
			//GPIOC->ODR |= 1UL<<0U; /* ENABLE LED PC0 */
		}
		if((GPIOB->IDR)&(1UL<<11U) == 0) /* PB11 */
		{
			delay(200);
			i++;
			while((GPIOB->IDR)&(1UL<<11U) == 0); /* wait PB11 = 0 */
			GPIOC->ODR |= 1UL<<2U; /* ENABLE LED PC1 */
		}
		else
		{
			GPIOC->ODR &= ~(1UL<<0U); /* DISABLE LED PC0 */
		}
//		GPIOC->ODR |= 1UL<<0U;
//		delay(72000);
//		GPIOC->ODR &= ~(1UL<<0U);
//		delay(72000);
	}
}

