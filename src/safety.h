#include <Arduino.h>

const int lift = 0;
//const int lift2 = 2;
//const int bumper = 34;

void setup_safety() {
    pinMode(lift, INPUT);
    //pinMode(lift2, INPUT);
    //pinMode(bumper, INPUT);
}

void get_safety(bool *s_emergency){
    if (not digitalRead(lift))// remove not later
    {
        *s_emergency = false;
        //Serial.println("not ok");
    }
    else{
        *s_emergency = true;
        //Serial.println("ok");
    }
}