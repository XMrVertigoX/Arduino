#ifndef FM24W256_h
#define FM24W256_h

#include <inttypes.h>

class FM25W256 {
	public:
		FM25W256(uint8_t chipSelect);

		void init();

		// Reads an array of bytes
		void read(uint16_t address, uint8_t *buffer, int quantity);

		// Writes an array of bytes
		void write(uint16_t address, uint8_t *data, int quantity);

	private:
		uint8_t _chipSelect;
};

#endif
