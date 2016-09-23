#ifndef MAX7219_LEDMatrix_h
#define MAX7219_LEDMatrix_h

#include <inttypes.h>

#define NOOP 0x00
#define DIGIT0 0x01
#define DIGIT1 0x02
#define DIGIT2 0x03
#define DIGIT3 0x04
#define DIGIT4 0x05
#define DIGIT5 0x06
#define DIGIT6 0x07
#define DIGIT7 0x08
#define DECODEMODE 0x09
#define INTENSITY 0x0A
#define SCANLIMIT 0x0B
#define SHUTDOWN 0x0C
#define DISPLAYTEST 0x0F

class MAX7219_LEDMatrix {
   public:
    MAX7219_LEDMatrix(uint8_t spiAddress);

    void begin();
    void clearMatrix();
    void displayTest(bool b = true);
    void drawPixel(uint8_t x, uint8_t y, bool v);
    void setBrightness(uint8_t brightness = 0);
    void setDecodeMode(uint8_t decodeMode = 0);
    void setScanLimit(uint8_t scanLimit = 7);
    void show();
    void hide();

   private:
    uint8_t _stateSize = 16;
    uint8_t _spiAddress;
    uint8_t _state[16] = {};

    void writeByte(uint8_t address, uint8_t value);
    void limit();
};

#endif
