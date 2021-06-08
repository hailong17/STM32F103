/*
 * Author: Pham Van Lap
 * Company: FPT Software
 * Create Date: 19/09/2020
 * Project: STM32F103RCT6 FreeRTOS
 * */
#include "stm32f103xe.h"
#include "cmsis_os.h"
#include "board_7seg.h"

uint8_t sync = 0;
uint32_t num = 0;
/************************************************************************************/
const osThreadAttr_t myTask01_attributes = {
	.name = "myTask01",
	.priority = (osPriority_t) osPriorityNormal,
	.stack_size = 128 * 4
};

const osThreadAttr_t myTask02_attributes = {
	.name = "myTask02",
	.priority = (osPriority_t) osPriorityLow,
	.stack_size = 128 * 4
};


const osThreadAttr_t myTask03_attributes = {
	.name = "myTask03",
	.priority = (osPriority_t) osPriorityLow,
	.stack_size = 128 * 4
};
/************************************************************************************/
void TM_SystemInit(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; /* Alternate Function I/O clock enabled */
	RCC->APB1ENR |= RCC_APB1ENR_PWREN; /* Power interface clock enable */
	//__HAL_AFIO_REMAP_SWJ_NOJTAG();
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3);/* I/O port B clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<4);/* I/O port C clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<5);/* I/O port C clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<11);/* TIM1 */
}

void TM_GPIO_Init(void)
{
	GPIOC->CRL |= 3UL<<0U;/* MODE */
	GPIOC->CRL &= ~(3UL<<2U); /*CNF*/
	GPIOC->CRL |= 3UL<<4U;/* MODE */
	GPIOC->CRL &= ~(3UL<<6U); /*CNF*/

	/*PB5*/
	GPIOB->CRL |= 3UL<<20U;/* MODE */
	GPIOB->CRL &= ~(3UL<<22U); /*CNF*/

	/*PB3*/
	GPIOB->CRL |= 3UL<<12U;/* MODE */
	GPIOB->CRL &= ~(3UL<<14U); /*CNF*/

	/*PD2*/
	GPIOD->CRL |= 3UL<<8U;/* MODE */
	GPIOD->CRL &= ~(3UL<<10U); /*CNF*/


	GPIOB->CRH &= ~(3UL<<10U);
	GPIOB->CRH |= (2UL<<10U); /* Input mode with pull-up/ pull-down */
	GPIOB->ODR |= (1UL<<10U); /* pull-up */
}
/************************************************************************************/

void StartTask01(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);
/************************************************************************************/

int main(void)
{
	TM_SystemInit();
	TM_GPIO_Init();
	HC595_Init();
	osKernelInitialize();
	osThreadNew(StartTask01, NULL, &myTask01_attributes);
	osThreadNew(StartTask02, NULL, &myTask02_attributes);
	osThreadNew(StartTask03, NULL, &myTask02_attributes);
	osKernelStart();
	while (1)
	{
		/* nothing */
	}
}
/************************************************************************************/

void StartTask01(void *argument)
{
	for(;;)
	{
		Display(sync);
		sync++; if(sync>3)sync=0;
		osDelay(1);
	}
}

void StartTask02(void *argument)
{
	for(;;)
	{
		num++;if(num>9999)num=0;
		osDelay(200);
	}
}

void StartTask03(void *argument)
{
	for(;;)
	{
		GPIOC->BSRR |= 3UL<<0U;
		osDelay(200);
		GPIOC->BRR |= 3UL<<0U;
		osDelay(200);
	}
}
/************************************************************************************/
