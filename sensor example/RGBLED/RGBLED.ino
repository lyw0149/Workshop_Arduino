int rPin = 5;
int gPin = 6;
int bPin = 7;

void setup() {
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);

}

void loop() {
  
  analogWrite(rPin,255);
  delay(1000);
  analogWrite(rPin,0);
  analogWrite(gPin,255);
  delay(1000);
  analogWrite(gPin,0);
  analogWrite(bPin,255);
  delay(1000);
  analogWrite(bPin,0);
}
