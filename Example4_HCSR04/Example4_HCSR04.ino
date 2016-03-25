int trigPin = 9;
int echoPin = 8;
 
//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop(){
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;
 

  Serial.print("DIstance:"); // 거리표시
  Serial.print(distance);
  Serial.println("cm");
  delay(300);
}

 
