#include "FM24W256.h"

#include <SPI.h>
#include "Arduino.h"

FM24W256::FM24W256(uint8_t chipSelect) {
    _chipSelect = chipSelect;
}

void FM24W256::init() {}

void FM24W256::read(uint16_t address, uint8_t *buffer, int quantity) {}

void FM24W256::write(uint16_t address, uint8_t *data, int quantity) {}
