#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN A0      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 11

#define BUTTON_INPUT_PIN 3  // Digital pin connected to one side of the button
#define BUTTON_OUTPUT_PIN 4 // Digital pin connected to the other side of the button
#define LIGHTPIN 2           // Digital pin connected to the TSL235R sensor
const int trigPin = 7;
const int echoPin = 8;

DHT dht(DHTPIN, DHTTYPE);

unsigned int counter = 0;
bool buttonState = false;
bool lastButtonState = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

enum Screen { TEMPERATURE, HUMIDITY, LIGHT_INTENSITY, ULTRASOUND };
Screen currentScreen = TEMPERATURE;

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  // Initialize DHT sensor
  dht.begin();

  // Set button pin modes
  pinMode(BUTTON_INPUT_PIN, INPUT_PULLUP);  // Input with internal pull-up resistor
  pinMode(BUTTON_OUTPUT_PIN, OUTPUT);
  digitalWrite(BUTTON_OUTPUT_PIN, LOW); // Initialize as low

  // Set light sensor pin mode
  pinMode(LIGHTPIN, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read button state with debounce
  int reading = digitalRead(BUTTON_INPUT_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        // Toggle between screens when the button is pressed
        currentScreen = static_cast<Screen>((currentScreen + 1) % 4);
      }
    }
  }
  //if (currentScreen == ULTRASOUND){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  //}
  long duration = pulseIn(echoPin, HIGH);
  long cm = microsecondsToCentimeters(duration);

  lastButtonState = reading;

  // Clear the display buffer
  display.clearDisplay();

  // Display temperature, humidity, or light intensity based on the current screen
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  if (currentScreen == TEMPERATURE) {
    display.print("Temp: ");
    display.setCursor(0, 20);
    display.print(temperature);
    display.println("C");
  } else if (currentScreen == HUMIDITY) {
    display.print("Wilgoc: ");
    display.setCursor(0, 20);
    display.print(humidity);
    display.println("%");
  } else if (currentScreen == LIGHT_INTENSITY) {
    int lightIntensity = analogRead(LIGHTPIN);
    display.print("Swiatlo: ");
    display.setCursor(0, 20);
    display.print(lightIntensity);
  } else if (currentScreen == ULTRASOUND){
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Distance: ");
    display.print(cm);
    display.println("cm");
    delay(100);
  }

  // Update OLED display
  display.display();
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
