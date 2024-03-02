#include <FastLED.h>

// Define the number of LEDs in the strip
#define NUM_LEDS 60

// Define the pin to which the data line is connected
#define DATA_PIN 13

// Create an array to hold the LED data
CRGB leds[NUM_LEDS];
CRGB colors[] = {
    CRGB(0, 255, 0),//Green
    CRGB(255, 100, 0),//Orange
    CRGB(255, 0, 0),//Red
    // Add more colors as needed
};

// CRGB::Black         // RGB(0, 0, 0)
// CRGB::White         // RGB(255, 255, 255)
// CRGB::Red           // RGB(255, 0, 0)
// CRGB::Green         // RGB(0, 255, 0)
// CRGB::Blue          // RGB(0, 0, 255)
// CRGB::Yellow        // RGB(255, 255, 0)
// CRGB::Orange        // RGB(255, 165, 0)
// CRGB::Purple        // RGB(128, 0, 128)
// CRGB::Pink          // RGB(255, 182, 193)
// CRGB::Violet        // RGB(238, 130, 238)
// CRGB::Indigo        // RGB(75, 0, 130)
// CRGB::Cyan          // RGB(0, 255, 255)
// CRGB::Turquoise     // RGB(64, 224, 208)
// CRGB::Lime          // RGB(0, 255, 0)
// CRGB::Magenta       // RGB(255, 0, 255)
// CRGB::Brown         // RGB(165, 42, 42)
// CRGB::DarkOrange    // RGB(255, 140, 0)
// CRGB::Gold          // RGB(255, 215, 0)
// CRGB::Silver        // RGB(192, 192, 192)
// CRGB::Gray          // RGB(128, 128, 128)
// CRGB::DarkGray      // RGB(169, 169, 169)
// CRGB::MediumGray    // RGB(128, 128, 128)
// CRGB::LightGray     // RGB(211, 211, 211)

void setup_led() {
  // Initialize FastLED library
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void led_on(int status) {
    // Fill the entire strip with a color
    fill_solid(leds, NUM_LEDS, colors[status]);

    // Show the changes on the strip
    FastLED.show();
}
void led_off(){
    // Clear the strip
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
}
