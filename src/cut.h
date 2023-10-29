#include <Arduino.h>

const int cut_pin = 12;

void setup_cut() {
    pinMode(cut_pin, OUTPUT); // Sets thePin as an OUTPUT
}

void cut_start() {
    digitalWrite(cut_pin, HIGH);
}

void cut_stop() {
    digitalWrite(cut_pin, LOW);
}