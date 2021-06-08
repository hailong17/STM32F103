/*
 * Author: Pham Van Lap
 * Company: FPT Software
 * Create Date: 19/09/2020
 * Project: STM32F103RCT6 FreeRTOS
 * */
#include "stm32f103xe.h"
#include "cmsis_os.h"
#include "LED7seg.h"
#include "RF315.h"



#define msg "Hello World!\r\n"

LED7seg Led7;

RF315 rfDriver(2000, 0, 0 , 0);

uint8_t sync = 0;
uint32_t num = 0;

osThreadAttr_t myTask01_attributes;
osThreadAttr_t myTask02_attributes;
osThreadAttr_t myTask03_attributes;
/************************************************************************************/
void TM_SystemInit(void)
{
//	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; /* Alternate Function I/O clock enabled */
//	RCC->APB1ENR |= RCC_APB1ENR_PWREN; /* Power interface clock enable */
	//__HAL_AFIO_REMAP_SWJ_NOJTAG();
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<3);/* I/O port B clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<4);/* I/O port C clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<5);/* I/O port D clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<11);/* TIM1 */
	RCC->APB2ENR |= (uint32_t) (1 << 14); /*Enabled clock USART1*/
}


void UART_Init(void)
{
	USART1->CR1 |= (uint32_t) (1 << 2); /* Receiver is enabled and begins searching for a start bit (bộ thu)*/
	USART1->CR1 |= (uint32_t) (1 << 3); /*Transmitter is enabled (bộ phát)*/
	USART1->CR1 |= (uint32_t) (1 << 13); /*USART enabled*/
	USART1->BRR |= (uint32_t) (4 << 4); /*Mantissa*/
	USART1->BRR |= (uint32_t) (5 << 0); /*Fraction*/
}

void GPIO_Init(void)
{
	GPIOA->CRH |= (uint32_t) (2 << 6); /*10: Alternate function output Push-pull (10: Đầu ra chức năng thay thế Đẩy-kéo)*/
	GPIOA->CRH |= (uint32_t) (3 << 4); /*11: Output mode, max speed 50 MHz. (11: Chế độ đầu ra, tốc độ tối đa 50 MHz.)*/
}

void UART1_TxMsg(uint8_t *data, uint8_t size)
{
	for(uint8_t i  = 0; i < size; i++)
	{
		USART1->DR |= *(data + i); //thanh ghi data;
		while((USART1->SR & (uint32_t)(1 << 6)) == 0); /*Transmission is complete*/
	}
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

	GPIOD->CRH &= ~(3UL<<0U);
	GPIOD->CRH |= (2UL<<0U); /* Input mode with pull-up/ pull-down */
	GPIOD->ODR |= (1UL<<0U); /* pull-up */

	GPIOD->CRL |= 1UL<<4U;/* MODE */
	GPIOD->CRL &= ~(1UL<<6U); /*CNF*/
}
/************************************************************************************/

void StartTask01(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);
/************************************************************************************/

void rf315_tx_pin(bool level)
{
	if(level == 1)GPIOD->BSRR |= 1UL<<1U;
	else GPIOD->BRR |= 1UL<<1U;
}



int main(void)
{
	rfDriver.reg_digital_write(rf315_tx_pin);
	myTask01_attributes.name = "myTask01";
	myTask01_attributes.priority = osPriorityNormal;
	myTask01_attributes.stack_size = 128 * 4;
	myTask02_attributes.name = "myTask02";
	myTask02_attributes.priority = osPriorityNormal;
	myTask02_attributes.stack_size = 128 * 4;
	myTask03_attributes.name = "myTask02";
	myTask03_attributes.priority = osPriorityNormal;
	myTask03_attributes.stack_size = 128 * 4;
	TM_SystemInit();
	TM_GPIO_Init();
	Led7.HC595_Init();
//	UART_Init();
//	GPIO_Init();
	osKernelInitialize();
	osThreadNew(StartTask01, NULL, &myTask01_attributes);
	osThreadNew(StartTask02, NULL, &myTask02_attributes);
	osThreadNew(StartTask03, NULL, &myTask02_attributes);
	osKernelStart();
	while (1)
	{
		//UART1_TxMsg((uint8_t*)msg, sizeof(msg));
		/* nothing */
	}
}
/************************************************************************************/

void StartTask01(void *argument)
{
	for(;;)
	{
//		Led7.Display(sync);
//		sync++; if(sync>3)sync=0;
		rfDriver.send((uint8_t *)msg, strlen(msg));
		//rfDriver.waitPacketSent();
		osDelay(200);
	}
}

void StartTask02(void *argument)
{
	for(;;)
	{
		Led7.num++;if(Led7.num>9999)Led7.num=0;
		//UART1_TxMsg((uint8_t*)msg, sizeof(msg));
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
