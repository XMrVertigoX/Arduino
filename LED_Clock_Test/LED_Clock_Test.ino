#include <SPI.h>
#include <MAX7219.h>

MAX7219 segment(10);

void setup() {
    SPI.begin();
    
    segment.begin();

    segment.write(DECODEMODE, 0xFF);
    segment.write(INTENSITY, 0xFF);
    segment.write(SCANLIMIT, 0x07);
    segment.write(SHUTDOWN, 0x01);
    segment.write(DISPLAYTEST, 0x00);
}

void loop() {
    segment.write(DIGIT0, random(0, 9));
    segment.write(DIGIT1, random(0, 9));
    segment.write(DIGIT2, random(0, 9));
    segment.write(DIGIT3, random(0, 9));
    segment.write(DIGIT4, random(0, 9));
    segment.write(DIGIT5, random(0, 9));

    delay(1000);
}
