void setup() {
    Serial1.begin(9600);
}

void loop() {
    if (Serial1.available() > 0) {
        Serial1.println(char(Serial1.read()));
    }
}
