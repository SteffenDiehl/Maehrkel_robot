#include <Arduino.h>

const int cut_pin = 12;

void setup_cut() {
    pinMode(cut_pin, OUTPUT); // Sets thePin as an OUTPUT
}

void cut_now() {
    digitalWrite(cut_pin, HIGH);
}

void stop_cut() {
    digitalWrite(cut_pin, LOW);
}