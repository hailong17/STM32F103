#include "stm32f1xx.h"
uint8_t led_status = 0;

#define RCC_CR_HSION_Pos                   0U
#define LRCC_CR_HSION_Msk                   (0x1UL <<  LRCC_CR_HSION_Pos)
#define LRCC_CR_HSION                       LRCC_CR_HSION_Msk

#define LRCC_CR_HSIRDY_Pos                  1U
#define LRCC_CR_HSIRDY_Msk                  (0x1UL << LRCC_CR_HSIRDY_Pos)
#define LRCC_CR_HSIRDY                      LRCC_CR_HSIRDY_Msk

#define LRCC_APB2ENR_AFIOEN_Pos             0U
#define LRCC_APB2ENR_AFIOEN_Msk             (0x1UL << LRCC_APB2ENR_AFIOEN_Pos)
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

#define LGPIOC_CRL_MODE0_Pos                 0U
#define LGPIOC_CRL_MODE0_Msk                 (0x3UL << LGPIOC_CRL_MODE0_Pos)
#define LGPIOC_CRL_MODE0                     LGPIOC_CRL_MODE0_Msk

#define LGPIOC_CRL_CNF0_Pos                  2U
#define LGPIOC_CRL_CNF0_Msk                  (0x3UL << LGPIOC_CRL_CNF0_Pos)
#define LGPIOC_CRL_CNF0                      LGPIOC_CRL_CNF0_Msk

#define LGPIOB_CRH_MODE10_Pos                8U
#define LGPIOB_CRH_MODE10_Msk                (0x3UL << LGPIOB_CRL_MOD1E0_Pos)
#define LGPIOB_CRH_MODE10                    LGPIOB_CRL_MODE10_Msk

#define LGPIOB_CRL_CNF10_Pos                 10U
#define LGPIOB_CRH_CNF10_Msk                 (0x10UL << LGPIOB_CRL_CNF10_Pos)
#define LGPIOB_CRH_CNF10                     LGPIOB_CRH_CNF10_Msk

#define LGPIOB_ODR_ODR10_Pos                 10U
#define LGPIOB_ODR_ODR10_Msk                 (0x1Ul << LGPIOB_ODR_ODR10_Pos)
#define LGPIOB_ODR_ODR10                     LGPIOB_ODR_ODR10_Msk

#define LAFIO_EXTICR3_EXTI10_Pos              8U
#define LAFIO_EXTICR3_EXTI10_Msk              (0x01UL << LAFIO_EXTICR3_EXTI10_Pos)
#define LAFIO_EXTICR3_EXTI10                  LAFIO_EXTICR3_EXTI10_Msk

#define LEXTI_IMR_MR10_Pos                    10U
#define LEXTI_IMR_MR10_Msk                    (0x1UL << LEXTI_IMR_MR10_Pos)
#define LEXTI_IMR_MR10                        LEXTI_IMR_MR10_Msk

#define LEXTI_EMR_MR10_Pos                    10U
#define LEXTI_EMR_MR10_Msk                    (0x1UL << LEXTI_EMR_MR10_Pos)
#define LEXTI_EMR_MR10                        LEXTI_EMR_MR10_Msk

#define LEXTI_FTSR_MR10_Pos                  10U
#define LEXTI_FTSR_MR10_Msk                  (0x1UL << LEXTI_FTSR_MR10_Pos)
#define LEXTI_FTSR_MR10                      LEXTI_FTSR_MR10_Msk

#define LEXTI_PR_PR10_Pos                     10U
#define LEXTI_PR_PR10_Msk                     (0x1UL << LEXTI_PR_PR10_Pos)
#define LEXTI_PR_PR10                         LEXTI_PR_PR10_Msk

#define LGPIOC_BRR_BR0_Pos                    0U
#define LGPIOC_BRR_BR0_Msk                    (0x1U << LGPIOC_BRR_BR0_Pos)
#define LGPIOC_BRR_BR0                        LGPIOC_BRR_BR0_Msk

#define LGPIOC_BSRR_BS0_Pos                   0U
#define LGPIOC_BSRR_BS0_Msk                   (0x1U << LGPIOC_BSRR_BS0_Pos)
#define LGPIOC_BSRR_BS0                       LGPIOC_BSRR_BS0_Msk

void SystemClock_Init(void)
{
	RCC->CR |= LRCC_APB2ENR_AFIOEN;    /* enable HSI clock */
	while((RCC->CR & LRCC_CR_HSIRDY) ==0 );
	RCC->CR |= LRCC_APB2ENR_AFIOEN;    /* Alternate Function I/O clock enabled */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */
	RCC->CR |= LRCC_APB2ENR_IOPAEN;    /* Port A enable */

}

void GPIO_Init(void)
{
	GPIOC->CRL |= LGPIOC_CRL_MODE0;      /* Mode */
	GPIOC->CRL &= ~LGPIOC_CRL_CNF0;      /* CNF */

	GPIOB->CRH &= ~LGPIOB_CRH_CNF10;     /* Clear */
	GPIOB->CRH |= LGPIOB_CRH_CNF10; /* Input mode with pull-up/ pull-down */

	GPIOB->ODR |= LGPIOB_ODR_ODR10;      /* pull-up */
}

void EXTI_Init(void)
{

	AFIO->EXTICR[3] |= LAFIO_EXTICR3_EXTI10;
	EXTI->IMR |= LEXTI_IMR_MR10; /* Interrupt request from Line x is not masked */
	EXTI->EMR |= LEXTI_EMR_MR10; /* Event request from Line x is not masked */
	EXTI->FTSR |= LEXTI_FTSR_MR10; /* Falling trigger enabled (for Event and Interrupt) for input line. */
	__NVIC_SetPriority(EXTI15_10_IRQn, 0);
	__NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
	if(led_status)led_status=0;
		else led_status = 1;

//		if(led_status)
//		{
//			GPIOC->BSRR |= LGPIOC_BSRR_BS0; /* Set PC0 */
//		}
//		else
//		{
//			GPIOC->BRR |= LGPIOC_BRR_BR0; /* Reset PC0 */
//		}
		EXTI->PR |= EXTI_PR_PR10;
}

int main(void)
{
	SystemClock_Init();
	GPIO_Init();
	EXTI_Init();
	while(1)
	{
		/* No Action */
	}
}
