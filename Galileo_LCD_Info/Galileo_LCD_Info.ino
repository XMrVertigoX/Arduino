#include <Wire.h>
#include <Ethernet.h>
#include <LiquidTWI2.h>
#include <time.h>

time_t tnow;
struct tm *tmnow;

char line[20];

LiquidTWI2 lcd(0);
byte MAC[] = {0x98, 0x4f, 0xEE, 0x00, 0x52, 0x72};

void setup() {
  Ethernet.begin(MAC);
  
  lcd.begin(20, 4);
  lcd.clear();
}

void loop() {
  time(&tnow);
  tmnow = localtime(&tnow);
  
  lcd.setCursor(0, 0);
  lcd.print("-- Intel Galileo  --");
  
  lcd.setCursor(0, 1);
  strftime(line, 20, "  %a,  %d.%m.%Y", tmnow);
  lcd.print(line);
  
  lcd.setCursor(0, 2);
  strftime(line, 20, "      %H:%M:%S", tmnow);
  lcd.print(line);
  
  lcd.setCursor(0, 3);
  lcd.print("IP:");
  lcd.setCursor(5, 3);
  lcd.print(Ethernet.localIP());
}
