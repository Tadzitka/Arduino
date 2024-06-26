#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;                       // variable to store the measured temperaturevariabele (float = floating point number)
int oneWireBus = 4;                    // 1-wire pin
OneWire oneWire(oneWireBus);            // 1-wire instance on the oneWireBus pin
DallasTemperature sensors(&oneWire);    // give the OneWire instance as parameter to the DallasTemperature library

void setup(void) {
    
    pinMode(LED_BUILTIN, OUTPUT);         // Initilise the LED_BUILTIN pin as output
    digitalWrite(LED_BUILTIN, LOW);       // Make sure the LED is turned off (LOW) when the program starts

    Serial.begin(9600);                   // initialize the serial monitor
    Serial.println("Bas on Tech - 1-wire temperatuur sensor"); // print message to serial monitor
    sensors.begin();                      // start with reading the sensor
}

void loop(void) { 
    sensors.requestTemperatures();          // read the temperature of all 1-wire sensors connected to the 1-wire bus
    temp = sensors.getTempCByIndex(0);      // get the temperature of the first sensors in Celcius (lists start with 0 not 1)
    // temp = sensors.getTempFByIndex(0);   // get the temperature of the first sensors in Fahrenheit (lists start with 0 not 1)
    Serial.print("Temperature is: ");       // print message without a newline
    Serial.println(temp);                   // print the temperature with a newline

    delay(1000);                            // pause 1000ms / 1 second
}
