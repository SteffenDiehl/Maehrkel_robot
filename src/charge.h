#include <Arduino.h>

const int analogChargePin = 34; // Analog pin on ESP32
int *chargeState = nullptr;

void setup_charge(int *c_chargestate) {
  pinMode(analogChargePin, INPUT);
  chargeState = c_chargestate;
}

void check_charge() {
  int analogValue = analogRead(analogChargePin);
  // Serial.print("analog Charge: ");
  // Serial.println(analogRead(analogChargePin));
  if (analogValue < 500) { // Example threshold values, adjust as needed
    *chargeState = 0;
  } else if (analogValue < 1500) {
    *chargeState = 1;
  } else {
    *chargeState = 2;
  }
}