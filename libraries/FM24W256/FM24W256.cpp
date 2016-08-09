#include "FM24W256.h"

#include "Arduino.h"
#include <Wire.h>

FM24W256::FM24W256(uint8_t deviceSelect) {
	// Combines slave ID and device select values to I2C address
	_i2cAddress = slaveID | deviceSelect;
}

void FM24W256::read(uint16_t address, uint8_t *buffer, uint16_t quantity) {
	// Moves the latch into position and esnds the write operation.
	latch(address, true);

	// Requests an amount of bytes. Closes the connection after last byte is received.
	Wire.requestFrom((int) _i2cAddress, quantity, true); 

	// Reads the given quantity of bytes
	for (int i = 0; i < quantity; ++i) {
		buffer[i] = Wire.read();
	}
}

void FM24W256::write(uint16_t address, uint8_t *data, uint16_t quantity) {
	// Moves latch into position. Does not end transmission for further write operations.
	latch(address, false);

	Wire.write(data, quantity);
	Wire.endTransmission(true);
}

// ----- Private --------------------------------------------------------------

void FM24W256::latch(uint16_t address, bool end) {
	union {
		uint16_t full;
		uint8_t split[2];
	} uniAddress;

	uniAddress.full = address;

	// Move latch into position
	Wire.beginTransmission(_i2cAddress);
	Wire.write(uniAddress.split, 2);
	
	if (end) {
		// Ends write operation. Required for following read operations.
		Wire.endTransmission(false); // Does not close SPI port for following operations
	}
}
