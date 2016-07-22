void setup() {
  Serial.begin(9600);
}
 
void loop() {
  float vol;
  int sensorValue = analogRead(A0);  // 데이터 읽기
  vol=(float)sensorValue/1024*5.0;  // 100분율로 변환해서 출력   
  Serial.println(vol,1);
}
