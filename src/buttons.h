#include <Arduino.h>


const int start_button = 25;
const int stop_button = 26;


void setup_buttons() {
    pinMode(start_button, INPUT);
    pinMode(stop_button, INPUT);
}

void check_buttons(){
    if (not digitalRead(start_button))
    {
        send_start();
        Serial.println("start");
    }
    if (not digitalRead(stop_button))
    {
        send_stop();
        Serial.println("stop");
    }
}