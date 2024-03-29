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
#include <buttons.h>


String current_Date = "NULL";
String current_Time = "NULL";
String current_Humidity  = "NULL";
String current_Temperature = "NULL";

int Status = 2; // 0 == "RUN", 1 ==  "GO HOME", 2 == "STOP"
int led_status = 0;

bool current_distance = false;
int current_chargeState = 0; // 0 == "Low", 1 == "Mid", 2 == "High"
bool state_emergency = false;
bool state_boundry = false;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_distance();
    setup_display();
    setup_drive();
    setup_safety();
    setup_cut();
    setup_led();
    setup_boundary();
    setup_charge(&current_chargeState);
    setup_buttons();
}

void loop(){
    get_safety(&state_emergency);
    send_emergency(state_emergency);
    get_data(&current_Date, &current_Time, &Status, &current_Humidity, &current_Temperature);
    get_distance(&current_distance);
    get_boundary(&state_boundry);
    check_charge();
    check_buttons();
    if (led_status != Status)
    {
        led_on(Status);
        led_status = Status;
    }
    // display_output(&current_Date, &current_Time, &Status, &current_Humidity, &current_Temperature);//current_Date, current_Time, Status, current_Humidity, current_Temperature
    
    if (Status == 0){
        cut_start();
        driving(current_distance, state_boundry, Status);
    }
    else if (Status == 1){
        driving(current_distance, state_boundry, Status);
        cut_stop();
    }
    else{
        drive_status = 0;
        drive_stop();
        cut_stop();
    }
    delay(100);
}