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
int current_distance = 0;
int current_chargeState = 0; // 0 == "Low", 1 == "Mid", 2 == "High"
int state_emergency = 1;
int state_bumper = 1;
int state_coil1 = 0;
int state_coil2 = 0;

int pwm_F_L = 255;
int pwm_B_L = 255;
int pwm_F_R = 255;
int pwm_B_R = 255;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_distance(&current_distance);
    setup_display();
    setup_drive();
    setup_safety();
    setup_cut();
    setup_led();
    setup_boundary();
    setup_charge(&current_chargeState);
}

void loop(){
    get_data(&current_Date, &current_Time, &Status);
    get_distance();
    display_output(current_Date, current_Time, Status, current_Humidity, current_Temperature);
    get_safety(&state_emergency, &state_bumper);
    get_boundary(&state_coil1, &state_coil2);
    check_charge();
    led_on(Status);
    if (Status == 0){
        cut_start();
        if (Status == 0)
        {
            drive_forward(pwm_F_L, pwm_F_R);
        }
        else if (Status == 0)
        {
            drive_forward(pwm_F_L, pwm_F_R);
        }
        else
        {
            drive_forward(pwm_F_L, pwm_F_R);
        }
    }
    else if (Status == 1){
        drive_backwards(pwm_B_L, pwm_B_R);
    }
    else{
        drive_stop();
        cut_stop();
    }
}