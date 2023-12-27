#include <Arduino.h>

//PWM Outputs
const int pwm_pin_forward_L = 4;
const int pwm_pin_backward_L = 33;
const int pwm_pin_forward_R = 16;
const int pwm_pin_backward_R = 15;
//Const Outputs
const int forward_L = 25;
const int backward_L = 26;
const int forward_R = 27;
const int backward_R = 14;

// setting PWM properties
const int freq = 5000;
const int channel_pwm_forward_L = 0;
const int channel_pwm_backward_L = 1;
const int channel_pwm_forward_R = 2;
const int channel_pwm_backward_R = 3;
const int resolution = 8;

const int pwm_forward_L = 5;
const int pwm_backward_L = 5;
const int pwm_forward_R = 5;
const int pwm_backward_R = 5;

void setup_drive() {
    // configure LED PWM functionalitites
    ledcSetup(channel_pwm_forward_L, freq, resolution);
    ledcSetup(channel_pwm_backward_L, freq, resolution);
    ledcSetup(channel_pwm_forward_R, freq, resolution);
    ledcSetup(channel_pwm_backward_R, freq, resolution);
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(pwm_pin_forward_L, channel_pwm_forward_L);
    ledcAttachPin(pwm_pin_backward_L, channel_pwm_backward_L);
    ledcAttachPin(pwm_pin_forward_R, channel_pwm_forward_R);
    ledcAttachPin(pwm_pin_backward_R, channel_pwm_backward_R);
    // Sets theConstantPin as an OUTPUT
    pinMode(forward_L, OUTPUT);
    pinMode(backward_L, OUTPUT);
    pinMode(forward_R, OUTPUT);
    pinMode(backward_R, OUTPUT);
}

void drive_forward() {
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    digitalWrite(backward_L, LOW);
    digitalWrite(backward_R, LOW);
    delay(500);
    ledcWrite(channel_pwm_forward_L, pwm_forward_L);
    ledcWrite(channel_pwm_forward_R, pwm_forward_R);
    digitalWrite(forward_L, HIGH);
    digitalWrite(forward_R, HIGH);
    delay(2000);
    ledcWrite(channel_pwm_forward_L, 255);
    delay(2000);
}

void drive_backwards() {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    digitalWrite(forward_L, LOW);
    digitalWrite(forward_R, LOW);
    delay(500);
    ledcWrite(channel_pwm_backward_L, pwm_backward_L);
    ledcWrite(channel_pwm_backward_R, pwm_backward_R);
    digitalWrite(backward_L, HIGH);
    digitalWrite(backward_R, HIGH);
    delay(2000);
    ledcWrite(channel_pwm_backward_L, 255);
    delay(2000);
}

void drive_turn_right() {
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    digitalWrite(backward_L, LOW);
    digitalWrite(forward_R, LOW);
    delay(500);
    ledcWrite(channel_pwm_forward_L, pwm_forward_L);
    ledcWrite(channel_pwm_backward_R, pwm_backward_R);
    digitalWrite(forward_L, HIGH);
    digitalWrite(backward_R, HIGH);
}

void drive_turn_left() {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    digitalWrite(forward_L, LOW);
    digitalWrite(backward_R, LOW);
    delay(500);
    ledcWrite(channel_pwm_backward_L, pwm_backward_L);
    ledcWrite(channel_pwm_forward_R, pwm_forward_R);
    digitalWrite(backward_L, HIGH);
    digitalWrite(forward_R, HIGH);
}

void drive_stop() {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    digitalWrite(forward_L, LOW);
    digitalWrite(backward_L, LOW);
    digitalWrite(forward_R, LOW);
    digitalWrite(backward_R, LOW);
}