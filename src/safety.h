#include <Arduino.h>

const int emergency = 33;
const int bumber = 25;

void setup_safety() {
    pinMode(emergency, INPUT); // Sets thePin as an INPUT
    pinMode(bumber, INPUT);
}