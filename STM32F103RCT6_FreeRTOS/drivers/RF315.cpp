/*
 * RF315.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: quocl
 */

#include "RF315.h"

RF315::RF315() {
	// TODO Auto-generated constructor stub

}

RF315::~RF315() {
	// TODO Auto-generated destructor stub
}
/******************************************************************************/

// Interrupt handler uses this to find the most recently initialised instance of this driver
static RF315* thisASKDriver;
/******************************************************************************/
static uint8_t symbols[] =
{
    0xd,  0xe,  0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c,
    0x23, 0x25, 0x26, 0x29, 0x2a, 0x2c, 0x32, 0x34
};

/******************************************************************************/
RF315::RF315(uint16_t speed, uint8_t rxPin, uint8_t txPin, uint8_t pttPin, bool pttInverted)
    :
    _speed(speed),
    _rxPin(rxPin),
    _txPin(txPin),
    _pttPin(pttPin),
    _pttInverted(pttInverted),
	_rxBad(0)
{
    uint8_t preamble[RH_ASK_PREAMBLE_LEN] = {0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x38, 0x2c};
    memcpy(_txBuf, preamble, sizeof(preamble));
}

/******************************************************************************/
bool RF315::init()
{
    thisASKDriver = this;
//    RH_ASK_TX_DDR   |=  (1<<RH_ASK_TX_PIN);
//    RH_ASK_RX_DDR   &= ~(1<<RH_ASK_RX_PIN);
    // Ready to go
    setModeIdle();
    //timerSetup();
    return true;
}

/******************************************************************************/
void RF315::setModeIdle()
{
	if (_mode != RHModeIdle)
	{
		// Disable the transmitter hardware
		writePtt(LOW);
		writeTx(LOW);
		_mode = RHModeIdle;
	}
}

/******************************************************************************/
void RF315::setModeRx()
{
	if (_mode != RHModeRx)
	{
		// Disable the transmitter hardware
		writePtt(LOW);
		writeTx(LOW);
		_mode = RHModeRx;
	}
}
/******************************************************************************/
void RF315::setModeTx()
{
	if (_mode != RHModeTx)
	{
		// PRepare state varibles for a new transmission
		_txIndex = 0;
		_txBit = 0;
		_txSample = 0;
		// Enable the transmitter hardware
		writePtt(HIGH);
		_mode = RHModeTx;
	}
}
/******************************************************************************/
bool RF315::available()
{
	if (_mode == RHModeTx)return false;
	setModeRx();
	if (_rxBufFull)
	{
		validateRxBuf();
		_rxBufFull= false;
	}
	return _rxBufValid;
}
/******************************************************************************/
bool RF315::recv(uint8_t* buf, uint8_t* len)
{
	if (!available())return false;
	if (buf && len)
	{
		// Skip the length and 4 headers that are at the beginning of the rxBuf
		// and drop the trailing 2 bytes of FCS
		uint8_t message_len = _rxBufLen-RH_ASK_HEADER_LEN - 3;
		if (*len > message_len)
			*len = message_len;
		memcpy(buf, _rxBuf+RH_ASK_HEADER_LEN+1, *len);
	}
	_rxBufValid = false; // Got the most recent message, delete it
	//    printBuffer("recv:", buf, *len);
	return true;
}
/******************************************************************************/
bool RF315::send(const uint8_t* data, uint8_t len)
{
    uint8_t i;
    uint16_t index = 0;
    uint16_t crc = 0xffff;
    uint8_t *p = _txBuf + RH_ASK_PREAMBLE_LEN; // start of the message area
    uint8_t count = len + 3 + RH_ASK_HEADER_LEN; // Added byte count and FCS and headers to get total number of bytes

    if (len > RH_ASK_MAX_MESSAGE_LEN)return false;

    // Wait for transmitter to become available
    //this->waitPacketSent();

    // Encode the message length
    crc = RHcrc_ccitt_update(crc, count);
    p[index++] = symbols[count >> 4];
    p[index++] = symbols[count & 0xf];

    // Encode the headers
    crc = RHcrc_ccitt_update(crc, _txHeaderTo);
    p[index++] = symbols[_txHeaderTo >> 4];
    p[index++] = symbols[_txHeaderTo & 0xf];
    crc = RHcrc_ccitt_update(crc, _txHeaderFrom);
    p[index++] = symbols[_txHeaderFrom >> 4];
    p[index++] = symbols[_txHeaderFrom & 0xf];
    crc = RHcrc_ccitt_update(crc, _txHeaderId);
    p[index++] = symbols[_txHeaderId >> 4];
    p[index++] = symbols[_txHeaderId & 0xf];
    crc = RHcrc_ccitt_update(crc, _txHeaderFlags);
    p[index++] = symbols[_txHeaderFlags >> 4];
    p[index++] = symbols[_txHeaderFlags & 0xf];

    // Encode the message into 6 bit symbols. Each byte is converted into
    // 2 6-bit symbols, high nybble first, low nybble second
    for (i = 0; i < len; i++)
    {
		crc = RHcrc_ccitt_update(crc, data[i]);
		p[index++] = symbols[data[i] >> 4];
		p[index++] = symbols[data[i] & 0xf];
    }

    // Append the fcs, 16 bits before encoding (4 6-bit symbols after encoding)
    // Caution: VW expects the _ones_complement_ of the CCITT CRC-16 as the FCS
    // VW sends FCS as low byte then hi byte
    crc = ~crc;
    p[index++] = symbols[(crc >> 4)  & 0xf];
    p[index++] = symbols[crc & 0xf];
    p[index++] = symbols[(crc >> 12) & 0xf];
    p[index++] = symbols[(crc >> 8)  & 0xf];

    // Total number of 6-bit symbols to send
    _txBufLen = index + RH_ASK_PREAMBLE_LEN;

    // Start the low level interrupt handler sending symbols
    setModeTx();

    // FIXME
    thisASKDriver = this;

    return true;
}
/******************************************************************************/
bool RF315::readRx()
{
    //return (_rxInverted ^ digitalRead(_rxPin));
	return (_rxInverted ^ digitalRead());
}
/******************************************************************************/
void RF315::writeTx(bool value)
{
	//digitalWrite(_txPin, value);
	this->digitalWrite(value);
}
/******************************************************************************/
void RF315::writePtt(bool value)
{
//#if (RH_PLATFORM == RH_PLATFORM_GENERIC_AVR8)
// #if RH_ASK_PTT_PIN
//    ((value) ? (RH_ASK_PTT_PORT |= (1<<RH_ASK_PTT_PIN)) : (RH_ASK_PTT_PORT &= ~(1<<RH_ASK_PTT_PIN)));
// #else
//    ((value) ? (RH_ASK_TX_PORT |= (1<<RH_ASK_TX_PIN)) : (RH_ASK_TX_PORT &= ~(1<<RH_ASK_TX_PIN)));
// #endif
//#else
//    digitalWrite(_pttPin, value ^ _pttInverted);
//#endif
}
/******************************************************************************/
uint8_t RF315::maxMessageLength()
{
    return RH_ASK_MAX_MESSAGE_LEN;
}
/******************************************************************************/
bool RF315::waitPacketSent(void)
{
    while (_mode == RHModeTx);
    return true;
}

void interrupt()
{
    thisASKDriver->handleTimerInterrupt();
}

// Convert a 6 bit encoded symbol into its 4 bit decoded equivalent
//uint8_t RH_INTERRUPT_ATTR RF315::symbol_6to4(uint8_t symbol)
//{
//    uint8_t i;
//    uint8_t count;
//
//    // Linear search :-( Could have a 64 byte reverse lookup table?
//    // There is a little speedup here courtesy Ralph Doncaster:
//    // The shortcut works because bit 5 of the symbol is 1 for the last 8
//    // symbols, and it is 0 for the first 8.
//    // So we only have to search half the table
//    for (i = (symbol>>2) & 8, count=8; count-- ; i++)
//	if (symbol == symbols[i]) return i;
//
//    return 0; // Not found
//}
/******************************************************************************/

void RF315::validateRxBuf()
{
    uint16_t crc = 0xffff;
    // The CRC covers the byte count, headers and user data
    for (uint8_t i = 0; i < _rxBufLen; i++)
	crc = RHcrc_ccitt_update(crc, _rxBuf[i]);
    if (crc != 0xf0b8) // CRC when buffer and expected CRC are CRC'd
    {
		// Reject and drop the message
		_rxBad++;
		_rxBufValid = false;
		return;
    }

    // Extract the 4 headers that follow the message length
    _rxHeaderTo    = _rxBuf[1];
    _rxHeaderFrom  = _rxBuf[2];
    _rxHeaderId    = _rxBuf[3];
    _rxHeaderFlags = _rxBuf[4];
    if (_promiscuous || (_rxHeaderTo == _thisAddress) || (_rxHeaderTo == RH_BROADCAST_ADDRESS))
    {
		_rxGood++;
		_rxBufValid = true;
    }
}
uint16_t RF315::RHcrc_ccitt_update (uint16_t crc, uint8_t data)
{
    data ^= lo8 (crc);
    data ^= data << 4;
    return ((((uint16_t)data << 8) | hi8 (crc)) ^ (uint8_t)(data >> 4) ^ ((uint16_t)data << 3));
}

/******************************************************************************/
void RF315::reg_digital_write(void (*write_fnc)(bool level))
{
	this->digitalWrite = write_fnc;
}

/******************************************************************************/
void RF315::reg_digital_read(bool (*read_fnc)(void))
{
	this->digitalRead = read_fnc;
}
