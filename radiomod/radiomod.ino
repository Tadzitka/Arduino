#include <ESP8266WiFi.h>
#include <RCSwitch.h>

#define TX_PIN 2 // Define the transmitter pin (GPIO2)

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(TX_PIN);
}

void loop() {
  const char* message = "Hello!";
  unsigned long code = 0; // Initialize the code variable
  for (int i = 0; message[i] != '\0'; i++) {
    code = code << 8 | message[i]; // Append each character of the message to the code
  }
  mySwitch.send(code, strlen(message) * 8); // Send the code with its length
  delay(1000);
}
