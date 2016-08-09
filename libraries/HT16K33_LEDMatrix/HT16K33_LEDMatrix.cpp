#include "HT16K33_LEDMatrix.h"

#include "Arduino.h"
#include <Wire.h>

HT16K33_LEDMatrix::HT16K33_LEDMatrix(uint8_t addr): _i2cAddress(addr) {}

HT16K33_LEDMatrix::HT16K33_LEDMatrix(int addr): _i2cAddress((uint8_t)addr) {}

void HT16K33_LEDMatrix::begin() {
	write(0x21);
	write(0xA0);
	write(0xE0);
	write(0x81);
}

void HT16K33_LEDMatrix::clear() {
	for (int i = 0; i < 16; ++i) {
		_state[i] = 0;
	}
}

uint8_t HT16K33_LEDMatrix::mask(uint8_t value) {
	uint8_t x = 1;

	for (uint8_t i = 0; i < value; ++i) {
		x *= 2;
	}

	return x;
}

void HT16K33_LEDMatrix::pixel(uint8_t x, uint8_t y, uint8_t color) {
	constrain(x, 0, 7);
	constrain(y, 0, 7);

	y *= 2;

	switch (color) {
		case 0:
			_state[y]   &= ~mask(x);
			_state[y+1] &= ~mask(x);
			break;

		case 1:
			_state[y]   |=  mask(x);
			_state[y+1] &= ~mask(x);
			break;

		case 2:
			_state[y]   &= ~mask(x);
			_state[y+1] |=  mask(x);
			break;

		case 3:
			_state[y]   |=  mask(x);
			_state[y+1] |=  mask(x);
			break;
	}
}

void HT16K33_LEDMatrix::pixel(int x, int y, int color) {
	pixel((uint8_t)x, (uint8_t)y, (uint8_t)color);
}

uint8_t HT16K33_LEDMatrix::read(uint8_t address) {
	Wire.beginTransmission(_i2cAddress);
	Wire.write(address);
	Wire.endTransmission();

	Wire.requestFrom(_i2cAddress, (uint8_t) 1);

	return Wire.read();
}

void HT16K33_LEDMatrix::setBrightness(uint8_t brightness) {
	write(constrain(brightness, 0, 15) + 0xE0); // 0xE0: Shift to brightness register
}

void HT16K33_LEDMatrix::setBrightness(int brightness) {
	setBrightness((uint8_t)brightness);
}

void HT16K33_LEDMatrix::draw() {
	for (int i = 0; i < 16; ++i) {
		write(i, _state[i]);
	}
}

uint8_t HT16K33_LEDMatrix::write(uint8_t command) {
	Wire.beginTransmission(_i2cAddress);
	Wire.write(command);

	return Wire.endTransmission();
}

uint8_t HT16K33_LEDMatrix::write(uint8_t address, uint8_t data) {
	Wire.beginTransmission(_i2cAddress);
	Wire.write(address);
	Wire.write(data);

	return Wire.endTransmission();
}
