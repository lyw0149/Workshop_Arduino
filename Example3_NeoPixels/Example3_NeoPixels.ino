#include <Adafruit_NeoPixel.h>

#define pinPix 12 // WS2812에 연결하는데 사용하는 pin 번호
#define numPix 16 // 링에 연결되어 있는 WS2812 LED 갯수

// Parameter 1 = 링에 연결되어 있는 WS2812 LED 갯수
// Parameter 2 = WS2812에 연결하는데 사용하는 pin 번호
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel myLeds = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);

void setup() {
  myLeds.begin(); // Initialize the NeoPixel array in the Arduino's memory,
  myLeds.show(); // turn all pixels off, and upload to ring or string
}

void loop() {
  int pause = 100;

  for (int i=0; i<numPix; i++) { 
    myLeds.setPixelColor(i,255,255,255);
    myLeds.show();
    delay(pause);
  }

  for (int i=0; i<numPix; i++) {
    myLeds.setPixelColor(i,0,0,0);
    myLeds.show();
    delay(pause);
  }
}
