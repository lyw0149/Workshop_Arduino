#include <Adafruit_NeoPixel.h>

#define pinPix 6 // WS2812에 연결하는데 사용하는 pin 번호
#define numPix 12 // 링에 연결되어 있는 WS2812 LED 갯수


Adafruit_NeoPixel myLeds = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);  //네오픽셀을 myLEDs 라는 이름으로 사용하겠다라는 선언


int trigPin = 9;
int echoPin = 8;
int ledPin = 13;

//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);

  myLeds.begin();
}

//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;
  int ledNum = map(distance, 0, 50, 0, 11);

  for (int i = 0; i < ledNum; i++) {
    myLeds.setPixelColor(i, 255, 255, 255);
  }
  myLeds.show();
  for (int i = 0; i < numPix; i++) {
    myLeds.setPixelColor(i, 0, 0, 0);
  }
  



  Serial.print("DIstance:"); // 거리표시
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

