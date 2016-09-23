#include <LiquidTWI2.h>
#include <Wire.h>

LiquidTWI2 lcd(0);

String str;
String line[4];

void setup() {
    Serial1.begin(9600);

    lcd.begin(20, 4);
    lcd.clear();
}

void loop() {
    while (Serial1.available() > 0) {
        str += Serial1.read();
    }

    if (str.length() > 0) {
        for (int i = 0; i < 3; i++) {
            line[i] = line[i + 1];
        }

        line[3] = str;
        str = "";

        lcd.clear();

        for (int i = 0; i < 4; i++) {
            lcd.setCursor(0, i);
            lcd.print(line[i]);
        }
    }
}
