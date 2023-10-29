#include <Arduino.h>

const int forward_L = 25;
const int backward_L = 26;
const int forward_R = 27;
const int backward_R = 14;

void setup_drive() {
    pinMode(forward_L, OUTPUT); // Sets thePin as an OUTPUT
    pinMode(backward_L, OUTPUT);
    pinMode(forward_R, OUTPUT);
    pinMode(backward_R, OUTPUT);
}

void drive_forward() {
    digitalWrite(forward_L, HIGH);
    digitalWrite(backward_L, LOW);
    digitalWrite(forward_R, HIGH);
    digitalWrite(backward_R, LOW);
}

void drive_backwards() {
    digitalWrite(forward_L, LOW);
    digitalWrite(backward_L, HIGH);
    digitalWrite(forward_R, LOW);
    digitalWrite(backward_R, HIGH);
}

void drive_turn() {
    digitalWrite(forward_L, HIGH);
    digitalWrite(backward_L, LOW);
    digitalWrite(forward_R, LOW);
    digitalWrite(backward_R, HIGH);
}

void drive_stop() {
    digitalWrite(forward_L, LOW);
    digitalWrite(backward_L, LOW);
    digitalWrite(forward_R, LOW);
    digitalWrite(backward_R, LOW);
}