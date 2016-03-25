#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); //Connect HC-06 TX,RX

void setup()  
{
  Serial.begin(9600);
  Serial.println("Hello!");

  // set the data rate for the BT port
  BTSerial.begin(9600);
}

void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
}

