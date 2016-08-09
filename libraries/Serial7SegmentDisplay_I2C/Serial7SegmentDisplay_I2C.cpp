#include "Serial7SegmentDisplay_I2C.h"

#include "Arduino.h"
#include <Wire.h>

Serial7SegmentDisplay_I2C::Serial7SegmentDisplay_I2C(int i2cAddress) {
    _i2cAddress = (uint8_t)i2cAddress;
}

void Serial7SegmentDisplay_I2C::begin() {
    write(CLEARDISPLAY);
    write(BRIGHTNESS, 127); // Halbe Helligkeit
}

uint8_t Serial7SegmentDisplay_I2C::write(uint8_t command) {
    Wire.beginTransmission(_i2cAddress);
    Wire.write(command);
    
    return Wire.endTransmission();
}

uint8_t Serial7SegmentDisplay_I2C::write(uint8_t command, uint8_t data) {
    Wire.beginTransmission(_i2cAddress);
    Wire.write(command);
    Wire.write(data);
    
    return Wire.endTransmission();
}
