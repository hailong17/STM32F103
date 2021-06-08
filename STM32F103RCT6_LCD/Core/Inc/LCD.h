#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f1xx.h"

#define PIN_LOW(PORT,PIN)		HAL_GPIO_WritePin(PORT,PIN,GPIO_PIN_RESET)
#define PIN_HIGH(PORT,PIN)		HAL_GPIO_WritePin(PORT,PIN,GPIO_PIN_SET)
#define D4_PIN					GPIO_PIN_1
#define D4_PORT					GPIOA
#define D5_PIN					GPIO_PIN_2
#define D5_PORT				 	GPIOA
#define D6_PIN				 	GPIO_PIN_3
#define D6_PORT					GPIOA
#define D7_PIN		 			GPIO_PIN_4
#define D7_PORT		 			GPIOA
#define RS_PIN		 			GPIO_PIN_0
#define RS_PORT		 			GPIOB
#define EN_PIN		 			GPIO_PIN_1
#define EN_PORT		 			GPIOB

void LCD_Init(void);
void LCD_Write(uint8_t type, uint8_t data);
void LCD_Puts(uint8_t x, uint8_t y, int8_t *string);
void LCD_Clear(void);

#endif
