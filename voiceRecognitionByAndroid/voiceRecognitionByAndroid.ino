#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

 
int lightPin = 8;
int usTrigPin = 4;
int usEchoPin = 5;


void setup() {
  pinMode(lightPin,OUTPUT);
  pinMode(usTrigPin,OUTPUT); // 센서 Trig 핀
  pinMode(usEchoPin,INPUT); // 센서 Echo 핀
  
  digitalWrite(lightPin,LOW);

  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
  if(BTSerial.available()){
    String data = BTSerial.readString();
    Serial.println("[Log] 명령 수신완료 : "+data);
    execFunc(data);
    }
}

int execFunc(String input){
  if(input == "turn On")turnOn();
  if(input == "turn Off")turnOff();
  if(input == "report Dist")reportDist();
  }



void turnOn(){
  digitalWrite(lightPin,HIGH);
  Serial.println("[Log] 명령 실행완료 : 불을 켰습니다.");
  
  }

void turnOff(){
  digitalWrite(lightPin,LOW);
  Serial.println("[Log] 명령 실행완료 : 불을 꼈습니다.");
  }

void reportDist(){
  String result = "현재 감지된 거리는 " + String(getDist()) + " cm 입니다";
  BTSerial.print(result);
  Serial.print("[Log] 원격 보고완료 : " + result);
}
int getDist(){
  digitalWrite(usTrigPin,HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(usTrigPin,LOW); // Trig 신호 off

  int duration = pulseIn(usEchoPin,HIGH); // Echo pin: HIGH->Low 간격을 측정
  int cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환

  return cm;
  }

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
