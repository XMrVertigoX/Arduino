#ifndef HT16K33_LEDMatrix_h
#define HT16K33_LEDMatrix_h

#include <inttypes.h>

#define BLACK  0x00
#define GREEN  0x01
#define RED    0x02
#define YELLOW 0x03

class HT16K33_LEDMatrix {
	public:
		HT16K33_LEDMatrix(int i2cAddress);
		HT16K33_LEDMatrix(uint8_t i2cAddress);

		void begin();
		void clear();
		void draw();
		void pixel(uint8_t x, uint8_t y, uint8_t color);
		void pixel(int x, int y, int color);
		void setBrightness(uint8_t brightness);
		void setBrightness(int brightness);

	private:
		uint8_t _i2cAddress;
		uint8_t _state[16];

		uint8_t read(uint8_t address);
		uint8_t write(uint8_t command);
		uint8_t write(uint8_t command, uint8_t data);

		static uint8_t mask(uint8_t value);
};

#endif
