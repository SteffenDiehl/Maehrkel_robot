#include <Arduino.h>

const int lift1 = 0;
const int lift2 = 0;
const int bumper = 2;

void setup_safety() {
    pinMode(lift1, INPUT);
    pinMode(lift2, INPUT);
    pinMode(bumper, INPUT);
}

void get_safety(bool *s_emergency){
    if (digitalRead(lift1) or digitalRead(lift2) or digitalRead(bumper))
    {
        *s_emergency = true;
    }
    else{
        *s_emergency = false;
    }
}