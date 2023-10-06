#include <Arduino.h>

const int emergency = 13;
const int bumper = 12;

void setup_safety() {
    pinMode(emergency, INPUT); // Sets thePin as an INPUT
    pinMode(bumper, INPUT);
}

void get_safety(int* s_emergency, int* s_bumper){
    *s_emergency = digitalRead(emergency);
    *s_bumper = digitalRead(bumper);
    Serial.println(String(digitalRead(bumper)) + "  other   " + String(digitalRead(emergency)));
}