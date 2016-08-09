#include <inttypes.h>
#include <Wire.h>
#include "FM24W256.h"

FM24W256 fram(0);

void setup() {
	Serial.begin(9600); // Start serial interface for debugging
	Wire.begin(); // Start I2C interface
}

void loop() {
	delay(1000);
	
	if (Serial.available() > 0) {
		uint16_t serialBufferLength = Serial.available();
		uint8_t serialBuffer[serialBufferLength];

		for (int i = 0; i < serialBufferLength; i++) {
		    serialBuffer[i] = Serial.read();
		}

		uint16_t memAddress = (uint16_t) random(0x7FFF);
		uint8_t memData[serialBufferLength];

		fram.write(memAddress, serialBuffer, serialBufferLength);
		fram.read(memAddress, memData, serialBufferLength);

		Serial.print(memAddress, HEX);
		Serial.print(": ");
		
		for(int i = 0; i < serialBufferLength; i++) {
		    Serial.print((char) memData[i]);
		}

		Serial.println();
	}
}
