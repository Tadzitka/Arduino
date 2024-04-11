/*
 *    FILE: demo01.pde
 *  AUTHOR: Rob Tillaart
 *    DATE: 2011 05 16
 *
 * PURPOSE: prototype TSL235R monitoring  
 *
 * Digital Pin layout ARDUINO
 * =============================
 *  2     IRQ 0    - to TSL235R
 *
 * PIN 1 - GND
 * PIN 2 - VDD - 5V
 * PIN 3 - SIGNAL
 *
 */

volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;

void irq1()
{
  cnt++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(115200);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, irq1, RISING);
}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{
  if (millis() - last >= 1000)
  {
    last = millis();
    t = cnt;
    unsigned long hz = t - oldcnt;
    Serial.print("FREQ: "); 
    Serial.print(hz);
    
    oldcnt = t;
  }
}
// END OF FILE
