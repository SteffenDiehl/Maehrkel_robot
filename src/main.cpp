#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include <charge.h>
#include <display.h>
#include <safety.h>
#include <request.h>

int current_hour = 0;
int current_min = 0;
int current_sec = 0;
int current_day = 0;
int current_month = 0;
int current_year = 0;
int status = 0;

void setup(){
    setup_wifi();

}
void loop(){
    get_time_date();
    delay(1000);
}