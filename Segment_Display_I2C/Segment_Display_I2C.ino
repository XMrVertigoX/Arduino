#include <Wire.h>
#include <Serial7SegmentDisplay_I2C.h>

Serial7SegmentDisplay_I2C display1(0x71);
Serial7SegmentDisplay_I2C display2(0x72);

void setup() {
  Wire.begin();
  
  display1.begin();
  display2.begin();
}

void loop() {
  
}
