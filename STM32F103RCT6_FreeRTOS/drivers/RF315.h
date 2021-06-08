/*
 * RF315.h
 *
 *  Created on: Sep 22, 2020
 *      Author: quocl
 */

#ifndef RF315_H_
#define RF315_H_

#include "stm32f103xe.h"
#include "string.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define lo8(x) ((x)&0xff)
#define hi8(x) ((x)>>8)


typedef enum
{
	RHModeInitialising = 0, ///< Transport is initialising. Initial default value until init() is called..
	RHModeSleep,            ///< Transport hardware is in low power sleep mode (if supported)
	RHModeIdle,             ///< Transport is idle.
	RHModeTx,               ///< Transport is in the process of transmitting a message.
	RHModeRx,               ///< Transport is in the process of receiving a message.
	RHModeCad               ///< Transport is in the process of detecting channel activity (if supported)
} RHMode;

// Maximum message length (including the headers, byte count and FCS) we are willing to support
// This is pretty arbitrary
#define RH_ASK_MAX_PAYLOAD_LEN 67

// The length of the headers we add (To, From, Id, Flags)
// The headers are inside the payload and are therefore protected by the FCS
#define RH_ASK_HEADER_LEN 4

// This is the maximum message length that can be supported by this library.
// Can be pre-defined to a smaller size (to save SRAM) prior to including this header
// Here we allow for 1 byte message length, 4 bytes headers, user data and 2 bytes of FCS
#ifndef RH_ASK_MAX_MESSAGE_LEN
 #define RH_ASK_MAX_MESSAGE_LEN (RH_ASK_MAX_PAYLOAD_LEN - RH_ASK_HEADER_LEN - 3)
#endif

#if !defined(RH_ASK_RX_SAMPLES_PER_BIT)
/// Number of samples per bit
 #define RH_ASK_RX_SAMPLES_PER_BIT 8
#endif //RH_ASK_RX_SAMPLES_PER_BIT

/// The size of the receiver ramp. Ramp wraps modulo this number
#define RH_ASK_RX_RAMP_LEN 160

// Ramp adjustment parameters
// Standard is if a transition occurs before RH_ASK_RAMP_TRANSITION (80) in the ramp,
// the ramp is retarded by adding RH_ASK_RAMP_INC_RETARD (11)
// else by adding RH_ASK_RAMP_INC_ADVANCE (29)
// If there is no transition it is adjusted by RH_ASK_RAMP_INC (20)
/// Internal ramp adjustment parameter
#define RH_ASK_RAMP_INC (RH_ASK_RX_RAMP_LEN/RH_ASK_RX_SAMPLES_PER_BIT)
/// Internal ramp adjustment parameter
#define RH_ASK_RAMP_TRANSITION RH_ASK_RX_RAMP_LEN/2
/// Internal ramp adjustment parameter
#define RH_ASK_RAMP_ADJUST 9
/// Internal ramp adjustment parameter
#define RH_ASK_RAMP_INC_RETARD (RH_ASK_RAMP_INC-RH_ASK_RAMP_ADJUST)
/// Internal ramp adjustment parameter
#define RH_ASK_RAMP_INC_ADVANCE (RH_ASK_RAMP_INC+RH_ASK_RAMP_ADJUST)

/// Outgoing message bits grouped as 6-bit words
/// 36 alternating 1/0 bits, followed by 12 bits of start symbol (together called the preamble)
/// Followed immediately by the 4-6 bit encoded byte count,
/// message buffer and 2 byte FCS
/// Each byte from the byte count on is translated into 2x6-bit words
/// Caution, each symbol is transmitted LSBit first,
/// but each byte is transmitted high nybble first
/// This is the number of 6 bit nibbles in the preamble
#define RH_ASK_PREAMBLE_LEN 8

// This is the value of the start symbol after 6-bit conversion and nybble swapping
#define RH_ASK_START_SYMBOL 0xb38

// This is the address that indicates a broadcast
#define RH_BROADCAST_ADDRESS 0xff


class RF315 {
public:
	RF315();
	virtual ~RF315();
	RF315(uint16_t speed = 2000, uint8_t rxPin = 11, uint8_t txPin = 12, uint8_t pttPin = 10, bool pttInverted = false);
    virtual bool    init();
    virtual bool    available();
    virtual bool    recv(uint8_t* buf, uint8_t* len);
    virtual bool    send(const uint8_t* data, uint8_t len);
    virtual uint8_t maxMessageLength();
    void            setModeIdle();
    void            setModeRx();
    void            setModeTx();
    void            handleTimerInterrupt();

    void reg_digital_write(void (*write_fnc)(bool level));
    void reg_digital_read(bool (*read_fnc)(void));
    bool waitPacketSent(void);

protected:
    uint8_t         timerCalc(uint16_t speed, uint16_t max_ticks, uint16_t *nticks);
    void            timerSetup();
    bool            readRx();
    void            writeTx(bool value);
    void            writePtt(bool value);
    uint8_t         symbol_6to4(uint8_t symbol);
    void            receiveTimer();
    void            transmitTimer();
    void            validateRxBuf();
    uint16_t        _speed;
    uint8_t         _rxPin;
    uint8_t         _txPin;
    uint8_t         _pttPin;
    bool            _rxInverted;
    bool            _pttInverted;
    volatile bool   _rxBufFull;
    volatile bool   _rxBufValid;
    volatile bool   _rxLastSample;
    volatile uint8_t _rxIntegrator;
    volatile uint8_t _rxPllRamp;
    volatile uint8_t _rxActive;
    volatile uint16_t _rxBits;
    volatile uint8_t _rxBitCount;
    uint8_t _rxBuf[RH_ASK_MAX_PAYLOAD_LEN];
    volatile uint8_t _rxCount;
    volatile uint8_t _rxBufLen;
    uint8_t _txIndex;
    uint8_t _txBit;
    uint8_t _txSample;
    uint8_t _txBuf[(RH_ASK_MAX_PAYLOAD_LEN * 2) + RH_ASK_PREAMBLE_LEN];
    uint8_t _txBufLen;
    /// TO header to send in all messages
	uint8_t             _txHeaderTo;
	/// FROM header to send in all messages
	uint8_t             _txHeaderFrom;
	/// ID header to send in all messages
	uint8_t             _txHeaderId;
	/// FLAGS header to send in all messages
	uint8_t             _txHeaderFlags;
	/// Count of the number of bad messages (eg bad checksum etc) received
	volatile uint16_t   _rxBad;
	/// TO header in the last received mesasge
	volatile uint8_t    _rxHeaderTo;
	/// FROM header in the last received mesasge
	volatile uint8_t    _rxHeaderFrom;
	/// ID header in the last received mesasge
	volatile uint8_t    _rxHeaderId;
	/// FLAGS header in the last received mesasge
	volatile uint8_t    _rxHeaderFlags;
	/// This node id
	uint8_t             _thisAddress;
	/// Whether the transport is in promiscuous mode
	bool                _promiscuous;
	/// Count of the number of successfully transmitted messaged
	volatile uint16_t   _rxGood;

	volatile RHMode     _mode;
    void (*digitalWrite)(bool level);
    bool (*digitalRead)(void);
    uint16_t RHcrc_ccitt_update (uint16_t crc, uint8_t data);
};
#endif /* RF315_H_ */
