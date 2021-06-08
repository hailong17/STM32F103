/*
 * LED7seg.h
 *
 *  Created on: Sep 22, 2020
 *      Author: quocl
 */

#ifndef _LED7SEG_H_
#define _LED7SEG_H_

#include "stm32f103xe.h"

#define HC595_DATA_PIN	(1UL<<5U)/* PB5 */
#define HC595_CLK_PIN	(1UL<<3U)/* PB3 */
#define HC595_LAT_PIN	(1UL<<2U)/* PD2 */

#define HC595_DATA_PORT GPIOB
#define HC595_CLK_PORT 	GPIOB
#define HC595_LAT_PORT 	GPIOD

class LED7seg {
public:
	uint32_t num;
	LED7seg();
	virtual ~LED7seg();
	void HC595_Init(void);
	void Display(uint8_t index);
private:
	uint8_t LED[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	void HC595_Write(uint8_t data);
	void OutLed(void);
};

#endif /* _LED7SEG_H_ */
