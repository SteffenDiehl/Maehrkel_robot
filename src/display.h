#include <Arduino_GFX_Library.h>

#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     22
#define TFT_DC     21
#define TFT_RESET  17

Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
Arduino_ILI9341 display = Arduino_ILI9341(&bus, TFT_RESET);
String myStatus[] = {"RUN", "STOP", "GO HOME"};

void setup_display(void)
{
    display.begin();
    display.setRotation(1);
    display.fillScreen(GREEN);
    display.fillRect(0, 0, 320, 100, DARKGREEN);
    display.setCursor(20, 20);
    display.setTextSize(2.8);
    display.setTextColor(BLACK);
}
void display_output(float cDistance, String cDate, String cTime, int cStatus){
    display.fillScreen(GREEN);
    display.fillRect(0, 0, 320, 100, DARKGREEN);
    display.setCursor(15, 15);
    display.println("Maehrkel");
    display.println("IP: 192.168.178.25");
    display.println("Date: " + cDate);
    display.println("Time: " + cTime);
    display.println("Distance: " + String(cDistance));
    display.println("Status: " + myStatus[cStatus]);
}