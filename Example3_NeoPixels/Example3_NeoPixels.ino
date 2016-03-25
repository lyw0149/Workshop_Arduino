#include <Adafruit_NeoPixel.h>

#define pinPix 6 // WS2812에 연결하는데 사용하는 pin 번호
#define numPix 12 // 링에 연결되어 있는 WS2812 LED 갯수

// Parameter 1 = 링에 연결되어 있는 WS2812 LED 갯수
// Parameter 2 = WS2812에 연결하는데 사용하는 pin 번호
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel myLeds = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);  //네오픽셀을 myLEDs 라는 이름으로 사용하겠다라는 선언

void setup() {
  myLeds.begin(); // 네오픽셀을 아두이노 메모리에 로드한다.
}

void loop() {
  int pause = 100;

  for (int i=0; i<numPix; i++) { 
    myLeds.setPixelColor(i,255,255,255);// i번째 LED 를 255/255/255 색으로 설정한다.
    myLeds.show();                      //설정한 값을 적용한다.
    delay(pause);                       //100ms 만큼 지연시간을 준다.
  }

  for (int i=0; i<numPix; i++) {
    myLeds.setPixelColor(i,0,0,0);//i번째 LED 를 0/0/0 색으로 설정한다.
    myLeds.show();                //설정한 값을 적용한다.
    delay(pause);                 //100ms 만큼 지연시간을 준다.
  }
}
