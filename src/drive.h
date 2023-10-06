#include <Arduino.h>

const int forward_L = 36;
const int backward_L = 39;
const int forward_R = 34;
const int backward_R = 35;

void setup_drive() {
    pinMode(forward_L, OUTPUT); // Sets thePin as an OUTPUT
    pinMode(backward_L, OUTPUT);
    pinMode(forward_R, OUTPUT);
    pinMode(backward_R, OUTPUT);
}

void drive_now() {
    digitalWrite(forward_L, HIGH);
    digitalWrite(backward_L, HIGH);
    digitalWrite(forward_R, HIGH);
    digitalWrite(backward_R, HIGH);
}