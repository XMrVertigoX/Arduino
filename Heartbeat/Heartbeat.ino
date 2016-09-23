int led = 13;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(250);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(1000);
}
