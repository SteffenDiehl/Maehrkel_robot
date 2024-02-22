#include <Arduino.h>

const int chargePinLow = 5;
const int chargePinMid = 5;
const int chargePinHigh = 5;

int *chargeState = nullptr;

void setup_charge(int *c_chargestate) {
  pinMode(chargePinLow, INPUT);
  pinMode(chargePinMid, INPUT);
  pinMode(chargePinHigh, INPUT);
  chargeState = c_chargestate;
}

void check_charge() {
  if(digitalRead(chargePinLow) == HIGH){
    *chargeState = 0;
  }
  else if(digitalRead(chargePinLow) == HIGH){
    *chargeState = 1;
  }
  else if(digitalRead(chargePinLow) == HIGH){
    *chargeState = 2;
  }
  delay(500);
}