#include "stm32f1xx.h"

#define HC595_DATA_PORT		GPIOB
#define HC595_DATA_PIN		(1ul<<5u)
#define HC595_CLK_PORT		GPIOB
#define HC595_CLK_PIN		(1ul<<3u)
#define HC595_LAT_PORT		GPIOB
#define HC595_LAT_PIN		(1ul<<2u)


unsigned char Data[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint8_t count=0;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void TIM6_Init(void);
void HC595_Write(uint8_t data);
void HC595_Out(void);

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	TIM6_Init();
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; AFIO->MAPR = AFIO_MAPR_SWJ_CFG_1;
	while (1)
	{
		HC595_Write(Data[count/1000]);
		HC595_Write(0x10);
		HC595_Out();

		HC595_Write(Data[(count/100)%10]);
		HC595_Write(0x20);
		HC595_Out();

		HC595_Write(Data[(count/10)%100]);
		HC595_Write(0x40);
		HC595_Out();

		HC595_Write(Data[count%1000]);
		HC595_Write(0x80);
		HC595_Out();
	}

}

void SystemClock_Config(void)
{
	RCC->CR|=(1ul<<0u);											// EN HSI
	while((RCC->CR & (1ul<<1u))==0);
	RCC->APB2ENR |=(1ul<<3u)|(1ul<<0u);							// EN PB & AFIO
	RCC->APB1ENR |=(1ul<<4u);									// EN TIM6
}

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIOB->CRL =0;
  GPIOB->CRL |= (3ul<<20u)|(3ul<<12u)|(3ul<<8u);				// OUTPUT with max speed

}

void TIM6_Init(void)
{
	TIM6->CR1 |=(1ul<<7u)|(1ul<<0u);							// buffered & EN CNT
	TIM6->DIER|=(1ul<<0u);										// EN Interrupt
	TIM6->EGR|=(1ul<<0u);										// Re-initializes the timer counter
	TIM6->PSC=7999;
	TIM6->ARR=999;

	__NVIC_EnableIRQ(TIM6_IRQn);

}

void TIM6_IRQHandler(void)
{
	count++;
	if(count>9999)
	{
		count=0;
	}
}
void HC595_Write(uint8_t data)
{
	for (int i=0;i<8;i++)
	{
		if(((data<<i) & 0x80) == 0x80)
		{
			HC595_CLK_PORT->BSRR|=HC595_DATA_PIN;
		}
		else
		{
			HC595_CLK_PORT->BRR|=HC595_DATA_PIN;
		}
		HC595_CLK_PORT->BSRR|=HC595_CLK_PIN;
		HC595_CLK_PORT->BRR|=HC595_CLK_PIN;

	}

}

void HC595_Out(void)
{
	HC595_LAT_PORT->BSRR|=HC595_LAT_PIN;
	HC595_LAT_PORT->BRR|=HC595_LAT_PIN;
}



void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
