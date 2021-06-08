/*
 * RF315.h
 *
 *  Created on: Oct 1, 2020
 *      Author: quocl
 */

#ifndef _RF315_H_
#define _RF315_H_

#include <stdlib.h>
#include "stm32f1xx.h"

#define VW_MAX_MESSAGE_LEN 100
#define VW_MAX_PAYLOAD VW_MAX_MESSAGE_LEN-3
#define VW_RX_RAMP_LEN 160
#define VW_RX_SAMPLES_PER_BIT 8
#define VW_RAMP_INC (VW_RX_RAMP_LEN/VW_RX_SAMPLES_PER_BIT)
#define VW_RAMP_TRANSITION VW_RX_RAMP_LEN/2
#define VW_RAMP_ADJUST 9
#define VW_RAMP_INC_RETARD (VW_RAMP_INC-VW_RAMP_ADJUST)
#define VW_RAMP_INC_ADVANCE (VW_RAMP_INC+VW_RAMP_ADJUST)
#define VW_HEADER_LEN 8

typedef struct RF315_Wire
{
	void (*tx_pin)(bool level);
	bool (*rx_pin)();
}RF315_Wire_t;

class RF315 {
public:
	RF315();
	virtual ~RF315();
	void vw_set_tx_pin(uint8_t pin);
	void vw_set_rx_pin(uint8_t pin);
	void vw_set_ptt_pin(uint8_t pin);
	void vw_set_ptt_inverted(uint8_t inverted);
	void vw_setup(uint16_t speed);
	void vw_rx_start();
	void vw_rx_stop();
	uint8_t vx_tx_active();
	void vw_wait_tx();
	void vw_wait_rx();
	uint8_t vw_wait_rx_max(unsigned long milliseconds);
	uint8_t vw_send(uint8_t* buf, uint8_t len);
	uint8_t vw_have_message();
	uint8_t vw_get_message(uint8_t* buf, uint8_t* len);
	void vw_int_handler();
	void vw_tx_start();
	void vw_tx_stop();
	void reg_rf_tx_func(void (*tx_func)(bool level));
	void reg_rf_rx_func(bool (*rx_func)());
	RF315_Wire_t Wire;

private:
	uint8_t vw_tx_buf[(VW_MAX_MESSAGE_LEN * 2) + VW_HEADER_LEN] = {0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x38, 0x2c};
	uint8_t vw_tx_len = 0;
	uint8_t vw_tx_index = 0;
	uint8_t vw_tx_bit = 0;
	uint8_t vw_tx_sample = 0;
	volatile uint8_t vw_tx_enabled = 0;
	uint16_t vw_tx_msg_count = 0;
	uint8_t vw_ptt_inverted = 0;
	uint8_t vw_tx_pin = 12;
	uint8_t vw_rx_sample = 0;
	uint8_t vw_rx_last_sample = 0;
	uint8_t vw_rx_pll_ramp = 0;
	uint8_t vw_rx_integrator = 0;
	uint8_t vw_rx_active = 0;
	volatile uint8_t vw_rx_done = 0;
	uint8_t vw_rx_enabled = 0;
	uint16_t vw_rx_bits = 0;
	uint8_t vw_rx_bit_count = 0;
	uint8_t vw_rx_buf[VW_MAX_MESSAGE_LEN];
	uint8_t vw_rx_count = 0;
	volatile uint8_t vw_rx_len = 0;
	uint8_t vw_rx_bad = 0;
	uint8_t vw_rx_good = 0;
	uint8_t symbols[16] = { 0xd,  0xe,  0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c, 0x23, 0x25, 0x26, 0x29, 0x2a, 0x2c, 0x32, 0x34};
	uint16_t vw_crc(uint8_t *ptr, uint8_t count);
	uint8_t vw_symbol_6to4(uint8_t symbol);
	void vw_pll();
	uint8_t _timer_calc(uint16_t speed, uint16_t max_ticks, uint16_t *nticks);
};

#endif /* _RF315_H_ */
