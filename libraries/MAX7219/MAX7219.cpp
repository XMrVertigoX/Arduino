#include "MAX7219.h"

#include "Arduino.h"
#include <SPI.h>

MAX7219::MAX7219(uint8_t spiAddress) {
	_spiAddress = spiAddress;
}

void MAX7219::init() {
	pinMode(_spiAddress, OUTPUT);
	digitalWrite(_spiAddress, HIGH);
}

void MAX7219::write(uint8_t address, uint8_t data) {
	digitalWrite(_spiAddress, LOW);
	SPI.transfer(address);
	SPI.transfer(data);
	digitalWrite(_spiAddress, HIGH);
}
