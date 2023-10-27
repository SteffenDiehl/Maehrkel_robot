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

String current_Date;
String current_Time;
int Status = 0;
float current_distance = 0;
int state_emergency = 1;
int state_bumper = 1;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_HCSR04();
    setup_display();
    setup_drive();
    setup_safety();
    setup_cut();
}
void loop(){
    get_data(&current_Date, &current_Time, &Status);
    get_distance(&current_distance);
    display_output(current_distance, current_Date, current_Time, Status);
    // get_safety(&state_emergency, &state_bumper);
    if (Status == 0 && state_bumper == 1 && state_emergency == 1){
        drive_now();
        cut_now();
    }
    else{
        stop_now();
        stop_cut();
    }
    delay(1000);
}