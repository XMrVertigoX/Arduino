#ifndef FM24W256_h
#define FM24W256_h

#include <inttypes.h>

// First four bit of I2C address. Shifted one bit right to run with arduino Wire library
const uint8_t slaveID = 0b10100000 >> 1;

class FM24W256 {
   public:
    FM24W256(uint8_t deviceSelect);

    // Reads an array of bytes
    void read(uint16_t address, uint8_t *buffer, uint16_t quantity);

    // Writes an array of bytes
    void write(uint16_t address, uint8_t *data, uint16_t quantity);

   private:
    uint8_t _i2cAddress;

    // Moves the internal address latch into position. Does not send stop condition for further operations.
    void latch(uint16_t address, bool end);
};

#endif
