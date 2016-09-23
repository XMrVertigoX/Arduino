#include "MAX7219_LEDMatrix.h"

#include <SPI.h>
#include "Arduino.h"

MAX7219_LEDMatrix::MAX7219_LEDMatrix(uint8_t spiAddress) {
    _spiAddress = spiAddress;
}

void MAX7219_LEDMatrix::begin() {
    pinMode(_spiAddress, OUTPUT);
    digitalWrite(_spiAddress, HIGH);

    for (int i = 0; i < _stateSize; i++) {
        writeByte(i, 0x00);
    }

    setBrightness();
    setDecodeMode();
    setScanLimit();
    show();
}

void MAX7219_LEDMatrix::clearMatrix() {
    for (int i = 0; i < 8; i++) {
        writeByte(i + 1, 0);
    }
}

void MAX7219_LEDMatrix::drawPixel(uint8_t x, uint8_t y, bool value) {
    y++;  // Digit 0 has address 0x01

    if (x < 8 && y < 8) {
        if (value) {
            _state[y] = _state[y] | byte(pow(2, 7 - x));
        } else {
            _state[y] = _state[y] & ~byte(pow(2, 7 - x));
        }
    }

    writeByte(y, _state[y]);
}

void MAX7219_LEDMatrix::hide() {
    writeByte(SHUTDOWN, 0x01);
}

void MAX7219_LEDMatrix::displayTest(bool b) {
    if (b) {
        writeByte(DISPLAYTEST, 1);
    } else {
        writeByte(DISPLAYTEST, 0);
    }
}

void MAX7219_LEDMatrix::setBrightness(uint8_t brightness) {
    if (brightness > 15) {
        brightness = 15;
    }

    writeByte(INTENSITY, brightness);
}

void MAX7219_LEDMatrix::setDecodeMode(uint8_t decodeMode) {
    if (decodeMode > 255) {
        decodeMode = 255;
    }

    writeByte(DECODEMODE, decodeMode);
}

void MAX7219_LEDMatrix::setScanLimit(uint8_t scanLimit) {
    if (scanLimit > 7) {
        scanLimit = 7;
    }

    writeByte(SCANLIMIT, scanLimit);
}

void MAX7219_LEDMatrix::show() {
    writeByte(SHUTDOWN, 1);
}

void MAX7219_LEDMatrix::writeByte(uint8_t address, uint8_t value) {
    _state[address] = value;

    digitalWrite(_spiAddress, LOW);
    SPI.transfer(address);
    SPI.transfer(_state[address]);
    digitalWrite(_spiAddress, HIGH);
}
