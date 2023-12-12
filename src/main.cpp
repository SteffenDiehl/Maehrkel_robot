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
int Status = 2; // 0 == "RUN", 1 ==  "GO HOME", 2 == "STOP"
float current_distance = 0;
int state_emergency = 1;
int state_bumper = 1;
int state_coil1 = 0;
int state_coil2 = 0;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_HCSR04();
    setup_display();
    setup_drive();
    setup_safety();
    setup_cut();
    setup_led();
    setup_boundary();
}
void loop(){
    get_data(&current_Date, &current_Time, &Status);
    // get_distance(&current_distance);
    display_output(current_distance, current_Date, current_Time, Status);
    // get_safety(&state_emergency, &state_bumper);
    // get_boundary(&state_coil1, &state_coil2);
    if (Status == 0 && state_bumper == 1 && state_emergency == 1){
        drive_forward();
        cut_start();
    }
    else if (Status == 1 && state_bumper == 1 && state_emergency == 1){
        drive_backwards();
        // delay(1000);
        // drive_turn();
        // delay(1000);
        // drive_forward();
    }
    else{
        drive_stop();
        cut_stop();
    }
    led_on(Status);
    //delay(1000);
}