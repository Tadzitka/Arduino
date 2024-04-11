#include "SevSeg.h"
SevSeg sevseg; 

int x = 10;

void odlic(){
  sevseg.setNumber(1);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(2);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(3);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(4);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(5);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(6);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(7);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(8);
  delay(600);
  sevseg.refreshDisplay();
  sevseg.setNumber(9);
  delay(600);
  sevseg.refreshDisplay();
}

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_ANODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
  if (x > 0) {
  sevseg.refreshDisplay();
  sevseg.setNumber(x);
  delay(1000);
  x -= 1;
}
  else if (x <= 0) {
  sevseg.refreshDisplay();
  sevseg.setNumber(x);
  delay(600);
  x = 10;
}
}
