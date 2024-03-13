#include <Arduino.h>


//PWM Outputs
const int pwm_pin_forward_L = 4;
const int pwm_pin_backward_L = 33;
const int pwm_pin_forward_R = 16;
const int pwm_pin_backward_R = 15;
//Const Outputs
// const int forward_L = 25;
// const int backward_L = 26;
// const int forward_R = 27;
// const int backward_R = 14;

// setting PWM properties
const int freq = 5000;
const int channel_pwm_forward_L = 0;
const int channel_pwm_backward_L = 1;
const int channel_pwm_forward_R = 2;
const int channel_pwm_backward_R = 3;
const int resolution = 8;

int drive_timer = 0;
int reverse_time = 500; //0,5s
int turn_time = 500; //0,5s

int drive_status = 0; //durring "RUN": 0 == forward, 1 == backward, 2 == turn

int pwm_F_L = 255;
int pwm_B_L = 255;
int pwm_F_R = 255;
int pwm_B_R = 255;

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
    // pinMode(forward_L, OUTPUT);
    // pinMode(backward_L, OUTPUT);
    // pinMode(forward_R, OUTPUT);
    // pinMode(backward_R, OUTPUT);
}

void drive_forward(int pwm_L, int pwm_R) {
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    // digitalWrite(backward_L, LOW);
    // digitalWrite(backward_R, LOW);
    delay(200);
    ledcWrite(channel_pwm_forward_L, pwm_L);
    ledcWrite(channel_pwm_forward_R, pwm_R);
    // digitalWrite(forward_L, HIGH);
    // digitalWrite(forward_R, HIGH);
}

void drive_backwards(int pwm_L, int pwm_R) {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    // digitalWrite(forward_L, LOW);
    // digitalWrite(forward_R, LOW);
    delay(200);
    ledcWrite(channel_pwm_backward_L, pwm_L);
    ledcWrite(channel_pwm_backward_R, pwm_R);
    // digitalWrite(backward_L, HIGH);
    // digitalWrite(backward_R, HIGH);
}

void drive_turn_right(int pwm_L, int pwm_R) {
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    // digitalWrite(backward_L, LOW);
    // digitalWrite(forward_R, LOW);
    delay(200);
    ledcWrite(channel_pwm_forward_L, pwm_L);
    ledcWrite(channel_pwm_backward_R, pwm_R);
    // digitalWrite(forward_L, HIGH);
    // digitalWrite(backward_R, HIGH);
}

void drive_turn_left(int pwm_L, int pwm_R) {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    // digitalWrite(forward_L, LOW);
    // digitalWrite(backward_R, LOW);
    delay(200);
    ledcWrite(channel_pwm_backward_L, pwm_L);
    ledcWrite(channel_pwm_forward_R, pwm_R);
    // digitalWrite(backward_L, HIGH);
    // digitalWrite(forward_R, HIGH);
}

void drive_stop() {
    ledcWrite(channel_pwm_forward_L, 0);
    ledcWrite(channel_pwm_backward_L, 0);
    ledcWrite(channel_pwm_forward_R, 0);
    ledcWrite(channel_pwm_backward_R, 0);
    // digitalWrite(forward_L, LOW);
    // digitalWrite(backward_L, LOW);
    // digitalWrite(forward_R, LOW);
    // digitalWrite(backward_R, LOW);
}

void driving(bool drive_distance, bool drive_boundary, int state){
    // if (drive_distance or drive_boundary)        {
    //         drive_status = 1;
    //         drive_timer = millis();
    //     }
    //     if (drive_status == 0){
    //         drive_forward(pwm_F_L, pwm_F_R);
    //     }
    //     else if (drive_status == 1){
    //         drive_backwards(pwm_B_L, pwm_B_R);
    //         if (millis() >= (drive_timer + reverse_time))
    //         {
    //             drive_status = 2;
    //             drive_timer = millis();
    //         }
            
    //     }
    //     else if (drive_status == 2){
    //         drive_turn_left(pwm_B_L, pwm_F_R);
    //         if (millis() >= (drive_timer + turn_time))
    //         {
    //             drive_status = 0;
    //         }
    //     }
        if (state == 0)
        {
            drive_forward(pwm_F_L, pwm_F_R);
        }
        else if (state == 1)
        {
            drive_backwards(pwm_B_L, pwm_B_R);
        }
        else{
            drive_stop();
        }
}