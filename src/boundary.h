#include <Arduino.h>

const int coil1 = 13;
const int coil2 = 12;

void setup_boundary() {
    pinMode(coil1, INPUT); // Sets thePin as an INPUT
    pinMode(coil2, INPUT);
}

void get_boundary(int* s_coil1, int* s_coil2){
    *s_coil1 = digitalRead(coil1);
    *s_coil2 = digitalRead(coil2);
    Serial.println(String(digitalRead(coil1)) + "  other   " + String(digitalRead(coil2)));
}