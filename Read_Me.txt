This is the robot's operational program.
Also see "Maehrkel_station".
Address
staticIP(192, 168, 178, 27);    //IP-addresse
gateway(192, 168, 178, 1);      //gateway
subnet(255, 255, 255, 0);       //subnetz mask
dns(8, 8, 8, 8);                //DNS

ESP32 Pinout

GPIO-0  Safety      lift1
GPIO-1  //
GPIO-2  //
GPIO-3  //
GPIO-4  Drive       PWM forward L
GPIO-5  Distance    sensePin
GPIO-6  //
GPIO-7  //
GPIO-8  //
GPIO-9  //
GPIO-10 //
GPIO-11 //
GPIO-12 Cut         Output
GPIO-13 LED-Tape    DATA_PIN
GPIO-14 Drive       const backward R
GPIO-15 Drive       PWM backward R
GPIO-16 Drive       PWM forward R
GPIO-17 Display     TFT_RESET
GPIO-18 Display     TFT_SCK
GPIO-19 Display     TFT_MISO
GPIO-21 Display     TFT_DC
GPIO-22 Display     TFT_CS
GPIO-23 Display     TFT_MOSI
GPIO-25 Drive       const forward L
GPIO-26 Drive       const backward L
GPIO-27 Drive       const forward R
GPIO-32 Boundry     coil1
GPIO-33 Drive       PWM backward L
GPIO-34 Charrge     chargePin
GPIO-35 Boundry     coil2
