#include <Arduino.h>

const int coil1 = 32;
const int coil2 = 35;

void setup_boundary() {
    pinMode(coil1, INPUT); // Sets thePin as an INPUT
    pinMode(coil2, INPUT);
}

void get_boundary(bool *s_boundry){
    if (digitalRead(coil1) or digitalRead(coil2)){
        *s_boundry = true;
    }
    else{
        *s_boundry = false;
    }
}