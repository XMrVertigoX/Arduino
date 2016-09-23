#ifndef MAX7219_h
#define MAX7219_h

#include <inttypes.h>

#define NOOP 0x0
#define DIGIT0 0x1
#define DIGIT1 0x2
#define DIGIT2 0x3
#define DIGIT3 0x4
#define DIGIT4 0x5
#define DIGIT5 0x6
#define DIGIT6 0x7
#define DIGIT7 0x8
#define DECODEMODE 0x9
#define INTENSITY 0xA
#define SCANLIMIT 0xB
#define SHUTDOWN 0xC
#define DISPLAYTEST 0xF

class MAX7219 {
   public:
    MAX7219(uint8_t spiAddress);

    void init();
    void write(uint8_t address, uint8_t data);

   private:
    uint8_t _spiAddress;
};

#endif
