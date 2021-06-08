
#include "main.h"

#include "stm32f1xx_it.h"
#include "RF315.h"

RF315 rf;

#define msg "Transmit from STM32F103RCT6 to RF315/433MHz successes\r\n"

TIM_HandleTypeDef htim6;

void TIM6_IRQHandler(void)
{
	rf.vw_int_handler();
	HAL_TIM_IRQHandler(&htim6);
}

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);

/* Configuration GPIO_PIN_0 as RF output */
void rf_tx_pin(bool level)
{
	if(level)HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
}

/* Configuration GPIO_PIN_1 as RF input */
bool rf_rx_pin(void)
{
	if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1) == GPIO_PIN_SET)return true;
	else return false;
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_TIM6_Init();
	HAL_TIM_Base_Start_IT(&htim6);
	rf.reg_rf_tx_func(rf_tx_pin);
	rf.reg_rf_rx_func(rf_rx_pin);
	while (1)
	{
		rf.vw_send((uint8_t*)msg, sizeof(msg));
		rf.vw_wait_tx();
		HAL_Delay(200);
	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}

static void MX_TIM6_Init(void)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	htim6.Instance = TIM6;
	htim6.Init.Prescaler = 0;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.Period = 499;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&htim6);
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig);
}

static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	__HAL_AFIO_REMAP_PD01_ENABLE();
}

void Error_Handler(void)
{

}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
