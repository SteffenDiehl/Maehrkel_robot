#include <Arduino.h>

const int LED1 = 14;
const int LED2 = 27;


// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int ledChanne2 = 0;
const int resolution = 8;

void setup_pwm(){
  // configure LED PWM functionalitites
    ledcSetup(ledChannel, freq, resolution);
    ledcSetup(ledChanne2, freq, resolution);
  // attach the channel to the GPIO to be controlled
    ledcAttachPin(LED1, ledChannel);
    ledcAttachPin(LED2, ledChanne2);
}
void pwm(){
  // increase the LED brightness
    for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
        ledcWrite(ledChannel, dutyCycle);
        ledcWrite(ledChanne2, dutyCycle);
        delay(10);
    }

    // decrease the LED brightness
    for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
        // changing the LED brightness with PWM
        ledcWrite(ledChannel, dutyCycle);   
        ledcWrite(ledChanne2, dutyCycle); 
        delay(10);
    }
}