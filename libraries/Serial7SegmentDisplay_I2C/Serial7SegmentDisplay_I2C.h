#ifndef Serial7SegmentDisplay_I2C_h
#define Serial7SegmentDisplay_I2C_h

#include <inttypes.h>

// Special Commands
#define CLEARDISPLAY 0x76
#define DECIMAL      0x77 // 0-63
#define CURSOR       0x79 // 0-3
#define BRIGHTNESS   0x7A // 0-255
#define DIGIT1       0x7B // 0-127
#define DIGIT2       0x7C // 0-127
#define DIGIT3       0x7D // 0-127
#define DIGIT4       0x7E // 0-127
#define BAUDRATE     0x7F // 0-11
#define I2CADDRESS   0x80 // 1-126
#define FACTORYRESET 0x81

class Serial7SegmentDisplay_I2C {
    public:
    	Serial7SegmentDisplay_I2C(int i2cAddress);

    	void begin();

        uint8_t write(uint8_t command);
        uint8_t write(uint8_t command, uint8_t data);

    private:
        uint8_t _i2cAddress;
};

#endif
