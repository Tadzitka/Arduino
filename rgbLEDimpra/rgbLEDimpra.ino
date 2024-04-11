// Define LED pins
const int blueLedPin = 9;
const int greenLedPin = 10;
const int redLedPin = 11;

void setup() {
  // Set LED pins as outputs
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Turn on all LEDs
  digitalWrite(blueLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

void loop() {
  // Nothing to do here since LEDs are already on
}
