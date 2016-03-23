// 초기설정을 위한 함수
void setup() {
  // 13번 핀을 출력 핀으로 설정합니다.
  pinMode(13, OUTPUT);
}

// 초기설정이 끝난후 지속적으로 반복되는 함수
void loop() {
  digitalWrite(13, HIGH);   // LED를 켭니다.
  delay(1000);              // 1 초간 기다립니다.
  digitalWrite(13, LOW);    // LED를 끕니다.
  delay(1000);              // 1 초간 기다립니다.
}
