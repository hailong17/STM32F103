#include<STM32F1xx.h>

#define PIN_WRITE(PORT,PIN)              HAL_GPIO_WritePin(PORT,PIN,GPIO_PIN_SET)
#define GPIOA_CRL_MODE0_Pos              0U
#define GPIOA_CRL_MODE0_Msk              (0x3UL << GPIOA_CRL_MODE0_Pos)
#define GPIOA_CRL_MODE0                  GPIOA_CRL_MODE0_Msk

#define GPIOA_CRL_CNF0_Pos                2U
#define GPIOA_CRL_CNF0_Msk                 (0x3UL << GPIOA_CRL_CNF0_Pos)
#define GPIOA_CRL_CNF0                    GPIOA_CRL_CNF0_Msk

#define GPIOA_CRL_MODE2_Pos              4U
#define GPIOA_CRL_MODE2_Msk              (0x3UL << GPIOA_CRL_MODE2_Pos)
#define GPIOA_CRL_MODE2                  GPIOA_CRL_MODE2_Msk

#define GPIOA_CRL_CNF2_Pos                6U
#define GPIOA_CRL_CNF2_Msk                 (0x3UL << GPIOA_CRL_CNF2_Pos)
#define GPIOA_CRL_CNF2                    GPIOA_CRL_CNF2_Msk

#define GPIOA_CRL_MODE1_Pos              4U
#define GPIOA_CRL_MODE1_Msk              (0x3UL << GPIOA_CRL_MODE1_Pos)
#define GPIOA_CRL_MODE1                  GPIOA_CRL_MODE1_Msk

#define GPIOA_CRL_CNF1_Pos                6U
#define GPIOA_CRL_CNF1_Msk                (0x3UL << GPIOA_CRL_CNF1_Pos)
#define GPIOA_CRL_CNF1                   GPIOA_CRL_CNF1_Msk

#define GPIOC_CRL_MODE2_Pos              8U
#define GPIOC_CRL_MODE2_Msk              (0x3UL << GPIOC_CRL_MODE2_Pos)
#define GPIOC_CRL_MODE2                  GPIOC_CRL_MODE2_Msk

#define GPIOC_CRL_CNF2_Pos              10U
#define GPIOC_CRL_CNF2_Msk              (0x3UL << GPIOC_CRL_CNF2_Pos)
#define GPIOC_CRL_CNF2                  GPIOC_CRL_CNF2_Msk

#define GPIOC_CRL_MODE3_Pos              12U
#define GPIOC_CRL_MODE3_Msk              (0x3UL << GPIOC_CRL_MODE3_Pos)
#define GPIOC_CRL_MODE3                  GPIOC_CRL_MODE3_Msk

#define GPIOC_CRL_CNF3Pos              14U
#define GPIOC_CRL_CNF3Msk              (0x3UL << GPIOC_CRL_CNF2_Pos)
#define GPIOC_CRL_CNF3                 GPIOC_CRL_CNF2_Msk

#define GPIOC_CRL_MODE4_Pos              16U
#define GPIOC_CRL_MODE4_Msk              (0x3UL << GPIOC_CRL_MODE4_Pos)
#define GPIOC_CRL_MODE4                  GPIOC_CRL_MODE4_Msk

#define GPIOC_CRL_CNF4_Pos              18U
#define GPIOC_CRL_CNF4_Msk              (0x3UL << GPIOC_CRL_CNF4_Pos)
#define GPIOC_CRL_CNF4                 GPIOC_CRL_CNF4_Msk

#define GPIOC_CRL_MODE5_Pos              20U
#define GPIOC_CRL_MODE5_Msk              (0x3UL << GPIOC_CRL_MODE5_Pos)
#define GPIOC_CRL_MODE5                  GPIOC_CRL_MODE5_Msk

#define GPIOC_CRL_CNF5_Pos              22U
#define GPIOC_CRL_CNF5_Msk              (0x3UL << GPIOC_CRL_CNF5_Pos)
#define GPIOC_CRL_CNF5                 GPIOC_CRL_CNF5_Msk

#define GPIOC_CRL_MODE6_Pos              24U
#define GPIOC_CRL_MODE6_Msk              (0x3UL << GPIOC_CRL_MODE6_Pos)
#define GPIOC_CRL_MODE6                  GPIOC_CRL_MODE6_Msk

#define GPIOC_CRL_CNF6_Pos              26U
#define GPIOC_CRL_CNF6_Msk              (0x3UL << GPIOC_CRL_CNF6_Pos)
#define GPIOC_CRL_CNF6                  GPIOC_CRL_CNF5_Msk

#define GPIOC_CRL_MODE7_Pos              28U
#define GPIOC_CRL_MODE7_Msk              (0x3UL << GPIOC_CRL_MODE7_Pos)
#define GPIOC_CRL_MODE7                  GPIOC_CRL_MODE7_Msk

#define GPIOC_CRL_CNF7_Pos              30U
#define GPIOC_CRL_CNF7_Msk              (0x3UL << GPIOC_CRL_CNF7_Pos)
#define GPIOC_CRL_CNF7                 GPIOC_CRL_CNF7_Msk

#define GPIOC_CRH_MODE8_Pos              0U
#define GPIOC_CRH_MODE8_Msk              (0x3UL << GPIOC_CRH_MODE8_Pos)
#define GPIOC_CRH_MODE8                  GPIOC_CRH_MODE8_Msk

#define GPIOC_CRH_CNF8_Pos                2U
#define GPIOC_CRH_CNF8_Msk              (0x3UL << GPIOC_CRH_CNF8_Pos)
#define GPIOC_CRH_CNF8                 GPIOC_CRH_CNF8_Msk

#define GPIOC_CRH_MODE9_Pos              4U
#define GPIOC_CRH_MODE9_Msk              (0x3UL << GPIOC_CRH_MODE9_Pos)
#define GPIOC_CRH_MODE9                  GPIOC_CRH_MODE9_Msk

#define GPIOC_CRH_CNF9_Pos              6U
#define GPIOC_CRH_CNF9_Msk              (0x3UL << GPIOC_CRH_CNF9_Pos)
#define GPIOC_CRH_CNF9                 GPIOC_CRH_CNF9_Msk

#define LCD_DATA_PORT             GPIOC
#define LCD_RS_PIN                GPIO_PIN_0
#define LCD_RS_PORT               GPIOA
#define LCD_EN_PIN                GPIO_PIN_1
#define LCD_EN_PORT               GPIOA
#define LCD_RW_PIN                GPIO_PIN_2
#define LCD_RW_PORT               GPIOA
#define LCD_D0_PIN                GPIO_PIN_2
#define LCD_D0_PORT               GPIOC
#define LCD_D1_PIN                GPIO_PIN_3
#define LCD_D1_PORT               GPIOC
#define LCD_D2_PIN                GPIO_PIN_4
#define LCD_D2_PORT               GPIOC
#define LCD_D3_PIN                GPIO_PIN_5
#define LCD_D3_PORT               GPIOC
#define LCD_D4_PIN                GPIO_PIN_6
#define LCD_D4_PORT               GPIOC
#define LCD_D5_PIN                GPIO_PIN_7
#define LCD_D5_PORT               GPIOC
#define LCD_D6_PIN                GPIO_PIN_8
#define LCD_D6_PORT               GPIOC
#define LCD_D7_PIN                GPIO_PIN_9
#define LCD_D7_PORT               GPIOC

void SytemClock_Init(void)
{
	RCC->CR |= RCC_CR_HSION; /* enable HSI clock */
	while((RCC->CR & RCC_CR_HSIRDY) == 0);
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;/* I/O port A clock enable */
	//RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;/* I/O port B clock enable */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;/* I/O port C clock enable */

}

void GPIO_Init(void)
{
	GPIOA->CRL |= GPIOA_CRL_MODE0;/* MODE */
	GPIOA->CRL |= GPIOA_CRL_CNF0; /*CNF*/

	GPIOA->CRL |= GPIOA_CRL_MODE1;/* MODE */
	GPIOA->CRL |= GPIOA_CRL_CNF1; /*CNF*/

	GPIOA->CRL |= GPIOA_CRL_MODE2;/* MODE */
	GPIOA->CRL |= GPIOA_CRL_CNF2; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE2;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF2; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE3;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF3; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE4;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF4; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE5;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF5; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE6;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF6; /*CNF*/

	GPIOC->CRL |= GPIOC_CRL_MODE7;/* MODE */
	GPIOC->CRL |= GPIOC_CRL_CNF7; /*CNF*/

	GPIOC->CRH |= GPIOC_CRH_MODE8;/* MODE */
	GPIOC->CRH |= GPIOC_CRH_CNF8; /*CNF*/

	GPIOC->CRH |= GPIOC_CRH_MODE9;/* MODE */
	GPIOC->CRH |= GPIOC_CRH_CNF9; /*CNF*/

}


void LCD_Clear(void)
{
	LCD_RW_PORT->BRR &= ~(1<<LCD_RW_PIN); /* RW = 0 */

	LCD_RS_PORT->BRR &= ~(1<<LCD_RS_PIN); /* RS = 0, ghi lenh */

    LCD_D0_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D1_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D2_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D3_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D4_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D5_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D6_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D7_PORT->BRR |= (1<<LCD_D0_PIN); /* D0 = 0*/


	LCD_EN_PORT ->BRR |= (1<<LCD_EN_PIN); /* tao xung len EN */
	delay();
	LCD_EN_PORT ->BRR &= ~(1<<LCD_EN_PIN); /* tao xung xuong EN */
	delay();

}

void LCD_Cmd(void)
{
	LCD_RW_PORT->BRR &= ~(1<<LCD_RW_PIN); /* RW = 0 */

	LCD_RS_PORT->BRR &= ~(1<<LCD_RS_PIN); /* RS = 0, ghi lenh */

    LCD_D0_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D1_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D2_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D3_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D4_PORT->BRR |= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D5_PORT->BRR |= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D6_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/
    LCD_D7_PORT->BRR &= ~(1<<LCD_D0_PIN); /* D0 = 0*/


	LCD_EN_PORT ->BRR |= (1<<LCD_EN_PIN); /* tao xung len EN */
	delay();
	LCD_EN_PORT ->BRR &= ~(1<<LCD_EN_PIN); /* tao xung xuong EN */
	delay();

}

void LCD_Chr_Cp(char data)		// Current Position
{
	LCD_RW_PORT->BRR &= ~(1<<LCD_RW_PIN); /* RW = 0 */

	LCD_RS_PORT->BRR |= (1<<LCD_RW_PIN); /* RW = 1 */

	if(data & 0x80)
		{
			PIN_WRITE(LCD_D7_PORT,LCD_D7_PIN);
		}

	if(data & 0x40)
		{
			PIN_WRITE(LCD_D6_PORT,LCD_D6_PIN);
		}

	if(data & 0x20)
		{
			PIN_WRITE(LCD_D5_PORT,LCD_D5_PIN);
		}

	if(data & 0x10)
		{
			PIN_WRITE(LCD_D4_PORT,LCD_D4_PIN);
		}

	/* ___________________________Write 4bit low____________________________________________ */
	if(data & 0x08)
		{
			PIN_WRITE(LCD_D3_PORT,LCD_D3_PIN);
		}

	if(data & 0x04)
		{
			PIN_WRITE(LCD_D2_PORT,LCD_D2_PIN);
		}

	if(data & 0x02)
		{
			PIN_WRITE(LCD_D1_PORT,LCD_D1_PIN);

		}
	if(data & 0x01)
		{
			PIN_WRITE(LCD_D0_PORT,LCD_D0_PIN);
		}

	LCD_EN_PORT ->BRR |= (1<<LCD_EN_PIN); /* tao xung len EN */
	delay();
	LCD_EN_PORT ->BRR &= ~(1<<LCD_EN_PIN); /* tao xung xuong EN */
	delay();
}

void LCD_Out_Cp(char *str)
{
 	unsigned char i = 0;
	while(str[i]!=0)
	{
	 	LCD_Chr_Cp(str[i]);
		i++;
	}
}

void delay(uint8_t time)
{
	while(time--);
}

int main(void)
{
	LCD_Clear();  /* Clear LCD */
	LCD_Cmd();  /* xoa con tro va hien thi*/
	LCD_Chr_Cp('A');
	LCD_Out_Cp("Hello World");
	while(1)
	{


	}
}
