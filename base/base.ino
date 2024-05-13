#include <FastLED.h>
 
#define NUM_LEDS 12
#define controlPin 5
 
CRGB leds[NUM_LEDS];
 
void setup() { 
    FastLED.addLeds<WS2812B, controlPin, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(8);
}
 
void loop() { 
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Green;
    leds[i + 2] = CRGB::LightGoldenrodYellow;;
    leds[i + 3] = CRGB::Blue;
    leds[i + 4] = CRGB::LightGoldenrodYellow;;
    i -= 1;
  }
  FastLED.show();
  delay(100);
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Green;
    leds[i + 1] = CRGB::Fuchsia;
    leds[i + 2] = CRGB::Blue;
    leds[i + 3] = CRGB::LightGoldenrodYellow;
    leds[i + 4] = CRGB::Fuchsia;
    i -= 1;
  }
  FastLED.show();
  delay(1000);
  for (int i = 0; i < NUM_LEDS; i += 6) {
    leds[i] = CRGB::Blue;
    leds[i + 1] = CRGB::MediumSpringGreen;
    leds[i + 2] = CRGB::Red;
    leds[i + 3] = CRGB::MediumSpringGreen;
    leds[i + 4] = CRGB::Green;
    i -= 1;
  }
  FastLED.show();
  delay(100);
}
