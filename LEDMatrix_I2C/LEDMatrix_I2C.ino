#include <Wire.h>
#include <HT16K33_LEDMatrix.h>

HT16K33_LEDMatrix matrix(0x70);

void setup() {
  Wire.begin();
  
  matrix.begin();
  matrix.setBrightness(15);
  matrix.draw();
}

void loop() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      matrix.pixel(j, i, random()%4);
    }
  }
  
  matrix.draw();
  
  delay(1000);
}
