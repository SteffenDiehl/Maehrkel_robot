#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include <charge.h>
#include <display.h>
#include <safety.h>
#include <request.h>
#include <distance.h>
#include <drive.h>

// int current_hour = 0;
// int current_min = 0;
// int current_sec = 0;
// int current_day = 0;
// int current_month = 0;
// int current_year = 0;
String current_Date;
String current_Time;
int Status = 0;
float current_distance = 0;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_HCSR04();
    setup_display();
    setup_drive();
    setup_safety();
}
void loop(){
    get_data(&current_Date, &current_Time, &Status);
    get_distance(&current_distance);
    display_output(current_distance, current_Date, current_Time, Status);
    drive_now();
    delay(1000);
}