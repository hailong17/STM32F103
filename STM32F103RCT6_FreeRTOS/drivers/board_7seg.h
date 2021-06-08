/*
 * board_7seg.h
 *
 *  Created on: Sep 19, 2020
 *      Author: quocl
 */

#ifndef BOARD_7SEG_H_
#define BOARD_7SEG_H_

#include "stm32f103xe.h"

#define HC595_DATA_PIN	(1UL<<5U)/* PB5 */
#define HC595_CLK_PIN	(1UL<<3U)/* PB3 */
#define HC595_LAT_PIN	(1UL<<2U)/* PD2 */

#define HC595_DATA_PORT GPIOB
#define HC595_CLK_PORT 	GPIOB
#define HC595_LAT_PORT 	GPIOD


void HC595_Init(void);
void Display(uint8_t index);


#endif /* BOARD_7SEG_H_ */
