#include <Arduino.h>

// const int trigPin = 5;
// const int echoPin = 32;
const int sens1Pin = 5;
const int sens2Pin = 6;
const int sens3Pin = 7;

//define sound speed in cm/uS
// #define SOUND_SPEED 0.034

// long duration;
// float distanceCm;

void setup_HCSR04() { // Starts the serial communication
  //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sens1Pin, INPUT); // Sets the echoPin as an Input
  pinMode(sens2Pin, INPUT);
  pinMode(sens3Pin, INPUT);
}

void get_distance(float *cdistance) {
  // // Clears the trigPin
  //   digitalWrite(trigPin, LOW);
  //   delayMicroseconds(2);
  // // Sets the trigPin on HIGH state for 10 micro seconds
  //   digitalWrite(trigPin, HIGH);
  //   delayMicroseconds(10);
  //   digitalWrite(trigPin, LOW);

  // // Reads the echoPin, returns the sound wave travel time in microseconds
  //   duration = pulseIn(echoPin, HIGH);

  // // Calculate the distance
  //   distanceCm = duration * SOUND_SPEED/2;
    
  // // Prints the distance in the Serial Monitor
  //   Serial.print("Distance (cm): ");
  //   Serial.println(distanceCm);
  //   *cdistance = distanceCm; 
    
  //   delay(1000);
}