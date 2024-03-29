#include <Arduino.h>


// const int trigPin = 5;
// const int echoPin = 32;
const int sensPin = 5;
// const int sens2Pin = 6;
// const int sens3Pin = 7;
// const int IO_Pin = 2;

int sens_time = 0;
int sens_timing = 400; //0,5s
int sens_timeout = 500; //0,5s

void setup_distance() { // Starts the serial communication
  //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sensPin, INPUT); // Sets the echoPin as an Input
  // pinMode(sens2Pin, INPUT);
  // pinMode(sens3Pin, INPUT);
  // pinMode(IO_Pin, OUTPUT);  
}

void get_distance(bool *c_distance) {
  digitalRead(sensPin);
  // digitalRead(sens2Pin);
  // digitalRead(sens3Pin);
  // digitalWrite(IO_Pin, HIGH);
  // digitalWrite(IO_Pin, LOW);
  if (digitalRead(sensPin)) {
    if (sens_time == 0) {
      // If sens_time is not set, set it
      sens_time = millis();
    }
    if (millis() >= (sens_time + sens_timing))
    {
      *c_distance = true;
      Serial.println("Sensor an");
    }
    else{
      *c_distance = false;
    }
  }
  else {
    // Conditions are not met
    if (millis() >= (sens_time + sens_timeout)) {
      // If the timeout has elapsed since sens_time was set
      sens_time = 0; // Reset sens_time
      *c_distance = false;
    }
  }
}