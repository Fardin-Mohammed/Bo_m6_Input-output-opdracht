#include <Adafruit_NeoPixel.h>

//led links blauw = pin  /   bruin = gnd  / geel = 5v 
//led rechts blauw = pin /  bruin = gnd  / rood = 5v
#define PIN1 7
#define PIN2 8
#define NUM_LEDS 180

Adafruit_NeoPixel strip1(NUM_LEDS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_LEDS, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
}

void loop() {
  waveEffect();
}

void waveEffect() {
  static uint16_t pos = 0;
  pos++;

  for (int i = 0; i < NUM_LEDS; i++) {
    int brightness = (sin((i + pos) * 0.20) * 127) + 128;

    int r = brightness * 0.1;  
    int g = brightness * 0.3;
    int b = brightness;

    strip1.setPixelColor(i, strip1.Color(r, g, b));
    strip2.setPixelColor(i, strip2.Color(r, g, b));
  }

  strip1.show();
  strip2.show();
  delay(25);  
}


//