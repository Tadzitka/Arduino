int jeden()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
}
int dwa()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
int trzy()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
int cztery()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
int piec()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
int szesc()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
int siedem()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
int osiem()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
int dziewiec()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
int zero()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}



void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
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

}

void loop() {
  // put your main code here, to run repeatedly:
jeden();
delay(500);
dwa();
delay(500);
trzy();
delay(500);
cztery();
delay(500);
piec();
delay(500);
szesc();
delay(500);
siedem();
delay(500);
osiem();
delay(500);
dziewiec();
delay(500);
zero();
delay(500);
}
