#include <Adafruit_NeoPixel.h>

#define pinPix 6 // WS2812에 연결하는데 사용하는 pin 번호
#define numPix 12 // 링에 연결되어 있는 WS2812 LED 갯수


Adafruit_NeoPixel myLeds = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);  //네오픽셀을 myLEDs 라는 이름으로 사용하겠다라는 선언


void setup() {
  // put your setup code here, to run once:
  myLeds.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String data = Serial.readString();
    Serial.println(data);

    if(data == "on"){
      Serial.println("불 켠다");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 255,255,255);
      }
      myLeds.show();
    } 

    else if(data == "off"){
      Serial.println("불 끈다");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 0,0,0);
      }
      myLeds.show();
    }

    else if(data == "red"){
      Serial.println("빨간색");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 255,0,0);
      }
      myLeds.show();
    }

    else if(data == "blue"){
      Serial.println("파란색");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 0,0,255);
      }
      myLeds.show();
    }

    else if(data == "green"){
      Serial.println("녹색");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 0,255,0);
      }
      myLeds.show();
    }

    else if(data == "orange"){
      Serial.println("오렌지");
      for(int i=0; i<numPix; i++){
        myLeds.setPixelColor(i, 255,149,0);
      }
      myLeds.show();
    }
    
  }
}

