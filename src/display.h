#include <Arduino_GFX_Library.h>

#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     22
#define TFT_DC     21
#define TFT_RESET  17

Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
Arduino_ILI9341 display = Arduino_ILI9341(&bus, TFT_RESET);
String myStatus[] = {"RUN", "GO HOME", "STOP"};

void setup_display(void)
{
    display.begin();
    display.setRotation(1);
    display.setCursor(20, 20);
    display.setTextColor(BLACK);
    display.fillRect(0, 0, 320, 40, DARKGREEN);
    display.setCursor(12, 12);
    display.setTextSize(3.5);
    display.println("Maehrkel_Station_Robot");
    display.fillRect(0, 40, 320, 200, GREEN);
    display.setTextSize(2.8);
    display.setCursor(0, 50);
    display.println(" IP:");
    display.println(" Date:");
    display.println(" Time:");
    display.println(" Status:");
    display.println(" Distance:");
    display.setCursor(120, 50);
    display.println("192.168.178.25");
}
void display_output(float cDistance, String cDate, String cTime, int cStatus){
    display.fillRect(120, 65, 200, 175, GREEN);
    display.setCursor(120, 66);
    display.println(cDate);
    display.setCursor(120, 82);
    display.println(cTime);
    display.setCursor(120, 98);
    display.println(myStatus[cStatus]);
    display.setCursor(120, 114);
    display.println(String(cDistance));
}
