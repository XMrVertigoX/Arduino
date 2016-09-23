#include <Ethernet.h>
#include <LiquidTWI2.h>
#include <Wire.h>

byte MAC[] = {0x98, 0x4f, 0xEE, 0x00, 0x52, 0x72};

LiquidTWI2 lcd(0);

void setup() {
    Ethernet.begin(MAC);

    lcd.begin(20, 4);
    lcd.clear();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("-- Intel Galileo  --");
    lcd.setCursor(0, 2);
    lcd.print("IP:");
    lcd.setCursor(5, 2);
    lcd.print(Ethernet.localIP());
}
