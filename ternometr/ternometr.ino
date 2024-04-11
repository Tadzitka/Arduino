#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(2);
DallasTemperature sensors(&oneWire);
void ledy_siedem(int n)
{
  if (n == 0)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    }
  
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
pinMode(14, OUTPUT);
  digitalWrite(14, LOW);
pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
pinMode(17, OUTPUT);
  digitalWrite(17, LOW);
pinMode(18, OUTPUT);
  digitalWrite(18, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));
  delay(500);
}
