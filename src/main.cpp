#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include <charge.h>
#include <display.h>
#include <safety.h>
#include <request.h>
#include <distance.h>

int current_hour = 0;
int current_min = 0;
int current_sec = 0;
int current_day = 0;
int current_month = 0;
int current_year = 0;
int status = 0;

void setup(){
    Serial.begin(115200);
    setup_wifi();
    setup_HCSR04();
}
void loop(){
    get_time_date();
    get_distance();
    delay(1000);
}