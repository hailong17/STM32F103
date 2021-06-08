#include "stm32f1xx.h"

#define LRCC_CR_HSION_Pos                   0U
#define LRCC_CR_HSION_Msk                   (0x1UL <<  LRCC_CR_HSION_Pos)
#define LRCC_CR_HSION                       LRCC_CR_HSION_Msk

#define LRCC_CR_HSIRDY_Pos                  1U
#define LRCC_CR_HSIRDY_Msk                  (0x1UL << LRCC_CR_HSIRDY_Pos)
#define LRCC_CR_HSIRDY                      LRCC_CR_HSIRDY_Msk

#define LRCC_APB2ENR_AFIOEN_Pos             0U
#define LRCC_APB2ENR_AFIOEN_Msk             (0x1UL << RCC_APB2ENR_AFIOEN_Pos)
#define LRCC_APB2ENR_AFIOEN                 LRCC_APB2ENR_AFIOEN_Msk

#define LRCC_APB2ENR_IOPAEN_Pos             2U
#define LRCC_APB2ENR_IOPAEN_Msk             (0x1UL << LRCC_APB2ENR_IOPAEN_Pos)
#define LRCC_APB2ENR_IOPAEN                 LRCC_APB2ENR_IOPAEN_Msk

#define LRCC_APB2ENR_IOPBEN_Pos             3U
#define LRCC_APB2ENR_IOPBEN_Msk             (0x1UL << LRCC_APB2ENR_IOPBEN_Pos)
#define LRCC_APB2ENR_IOPBEN                 LRCC_APB2ENR_IOPBEN_Msk

#define LRCC_APB2ENR_IOPCEN_Pos             4U
#define LRCC_APB2ENR_IOPCEN_Msk             (0x1UL << LRCC_APB2ENR_IOPCEN_Pos)
#define LRCC_APB2ENR_IOPCEN                 LRCC_APB2ENR_IOPCEN_Msk

#define LRCC_APB2ENR_TIM1EN_Pos             11U
#define LRCC_APB2ENR_TIM1EN_Msk             (0x1UL << LRCC_APB2ENR_TIM1EN_Pos)
#define LRCC_APB2ENR_TIM1EN                 LRCC_APB2ENR_TIM1EN_Msk

void SystemClock_Init(void)
{
	RCC->CR |= LRCC_APB2ENR_AFIOEN;    /* enable HSI clock */
	while((RCC->CR & LRCC_CR_HSIRDY) ==0 );
	RCC->CR |= LRCC_APB2ENR_AFIOEN;    /* Alternate Function I/O clock enabled */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */
	RCC->CR |= LRCC_APB2ENR_TIM1EN;    /* TIM1 clock */
}

void GPIO_Inint(void)
{

}

void EXTI_Init(void)
{

}

void TIM_Init(void)
{

}

int main(void)
{

	while(1)
	{

	}
}
