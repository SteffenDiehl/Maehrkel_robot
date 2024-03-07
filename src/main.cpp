#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include <charge.h>
#include <display.h>
#include <safety.h>
#include <request.h>
#include <distance.h>
#include <drive.h>
#include <cut.h>
#include <ledTape.h>
#include <boundary.h>

String current_Date;
String current_Time;
String current_Humidity;
String current_Temperature;

int Status = 2; // 0 == "RUN", 1 ==  "GO HOME", 2 == "STOP"
int drive_status = 0; //durring "RUN": 0 == forward, 1 == backward, 2 == turn
bool current_distance = false;
int current_chargeState = 0; // 0 == "Low", 1 == "Mid", 2 == "High"
bool state_emergency = false;
bool state_boundry = false;

int pwm_F_L = 255;
int pwm_B_L = 255;
int pwm_F_R = 255;
int pwm_B_R = 255;

int drive_timer = 0;
int reverse_time = 500; //0,5s
int turn_time = 500; //0,5s

void setup(){
    Serial.begin(115200);
    setup_wifi();
    //setup_distance();
    setup_display();
    setup_drive();
    setup_safety();
    setup_cut();
    setup_led();
    setup_boundary();
    setup_charge(&current_chargeState);
}

void loop(){
    get_safety(&state_emergency);
    send_data(state_emergency);
    get_data(&current_Date, &current_Time, &Status, &current_Humidity, &current_Temperature);
    get_distance(&current_distance);
    display_output(current_Date, current_Time, Status, current_Humidity, current_Temperature);
    get_boundary(&state_boundry);
    check_charge();
    led_on(Status);
    if (Status == 0){
        cut_start();
        if (current_distance)        {
            drive_status = 1;
            drive_timer = millis();
        }
        if (drive_status == 0){
            drive_forward(pwm_F_L, pwm_F_R);
        }
        else if (drive_status == 1){
            drive_backwards(pwm_B_L, pwm_B_R);
            if (millis() >= (drive_timer + reverse_time))
            {
                drive_status = 2;
                drive_timer = millis();
            }
            
        }
        else if (drive_status == 2){
            drive_turn_left(pwm_B_L, pwm_F_R);
            if (millis() >= (drive_timer + turn_time))
            {
                drive_status = 0;
            }
        }
        else{
            drive_stop();
            cut_stop();
        }
    }
    else if (Status == 1){
        drive_backwards(pwm_B_L, pwm_B_R);
    }
    else{
        drive_status = 0;
        drive_stop();
        cut_stop();
    }
}