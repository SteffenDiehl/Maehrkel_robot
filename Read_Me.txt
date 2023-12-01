This is the robot's operational program.
Also see "Maehrkel_station".
Address
staticIP(192, 168, 178, 27);    //IP-addresse
gateway(192, 168, 178, 1);      //gateway
subnet(255, 255, 255, 0);       //subnetz mask
dns(8, 8, 8, 8);                //DNS

ESP32 Pinout

GPIO-0 safety emergency
GPIO-1 
GPIO-2 safety bumper
GPIO-3
GPIO-4 
GPIO-5 Distance trigPin
GPIO-6
GPIO-7
GPIO-8
GPIO-9
GPIO-10
GPIO-11
GPIO-12 Cut Output
GPIO-13 ledTape DATA_PIN
GPIO-14 Drive backward_R
GPIO-15
GPIO-16
GPIO-17 Display TFT_RESET
GPIO-18 Display TFT_SCK
GPIO-19 Display TFT_MISO
GPIO-21 Display TFT_DC
GPIO-22 Display TFT_CS
GPIO-23 Display TFT_MOSI
GPIO-25 Drive forward_L
GPIO-26 Drive backward_L
GPIO-27 Drive forward_R
GPIO-32 Distance echoPin
GPIO-33 pwm LED1
GPIO-34 pwm LED2
GPIO-35
