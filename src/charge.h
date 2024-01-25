#include <Arduino.h>

const int chargePin = 5;

int chargeValue = 0;

void setup_charge() {
    Serial.begin(115200);
    delay(1000);
}

void check_charge() {
  // Reading potentiometer value
    chargeValue = analogRead(chargePin);
    Serial.println(chargeValue);
    delay(500);
}
