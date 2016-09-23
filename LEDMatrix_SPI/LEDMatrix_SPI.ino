/*
 * Wiring:
 * VCC: +5V
 * GND: GND
 * DIN: Pin 11
 * CS:  Pin 10
 * CLK: Pin 13
 */

#include <MAX7219_LEDMatrix.h>
#include <SPI.h>

MAX7219_LEDMatrix matrix(10);

void setup() {
    SPI.begin();

    matrix.begin();
    matrix.clearMatrix();
}

void loop() {}
