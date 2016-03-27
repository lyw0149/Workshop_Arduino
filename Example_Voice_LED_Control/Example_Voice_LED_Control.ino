#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#define pinPix 6 // WS2812에 연결하는데 사용하는 pin 번호
#define numPix 12 // 링에 연결되어 있는 WS2812 LED 갯수


Adafruit_NeoPixel myLeds = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);  //네오픽셀을 myLEDs 라는 이름으로 사용하겠다라는 선언
SoftwareSerial BTSerial(2, 3); //Connect HC-06 TX,RX

int trigPin = 9;
int echoPin = 8;

int ledPin = 11;

//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup() {
  Serial.begin(9600);
  myLeds.begin();
  BTSerial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop() {

  delay(2000);

  if (BTSerial.available()) {
    String data = BTSerial.readString();
    Serial.println("[Log] 명령 수신완료 : " + data);
    execFunc(data);
  }
}

int execFunc(String input) {
  if (input == "turn On")turnOn();
  if (input == "turn Off")turnOff();
}

void turnOn() {

  for (int i = 0; i < numPix; i++) {
    myLeds.setPixelColor(i, 255, 255, 255);
  }
  myLeds.show();
  BTSerial.println("1");

}

void turnOff() {
  for (int i = 0; i < numPix; i++) {
    myLeds.setPixelColor(i, 0, 0, 0);
  }
  myLeds.show();
  BTSerial.println("1");
}



