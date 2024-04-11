#include <VirtualWire.h>

const int ledPin = 13; // Pin for LED indicator

void setup() {
  // Initialize the communication to the receiver module
  vw_set_rx_pin(12);   // Set the receiver pin
  vw_setup(2000);      // Bits per second
  vw_rx_start();       // Start the receiver
  
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Buffer to store received message
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Length of the message buffer
  
  if (vw_get_message(buf, &buflen)) { // If a message is received
    digitalWrite(ledPin, HIGH); // Turn on LED
    Serial.print("Received: ");
    for (int i = 0; i < buflen; i++) {
      Serial.write(buf[i]); // Print the received message
    }
    Serial.println();
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(1000); // Wait for 1 second before receiving again
  }
}
