void setup() {
  Serial.begin(9600);            //9600보 레이트로 시리얼 통신 시작
  pinMode(13, OUTPUT);           //13번 핀을 출력 핀 으로 설정
}

void loop() {
  if (Serial.available()) {     //시리얼 포트가 열려 있다면,
    int data = Serial.read();   //시리얼포트로부터 받아온 정보를 변수에 저장

    if (data == 'H') {          //만약 H라면  
      digitalWrite(13, HIGH);   //LED를 켜고
      Serial.write("LED ON");
    } else if (data == 'L') {   //만약 L이라면
      digitalWrite(13, LOW);    //LED를 끈다
      Serial.write("LED OFF");
    }
  }
}
  
