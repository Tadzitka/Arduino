#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* ssid = "Orange_Multany";     // Change to your WiFi SSID
const char* password = "Kaczorek5"; // Change to your WiFi password

const int ledPin = 5; // Assuming LED is connected to pin D1 (GPIO 5) on ESP8266 board
const int oneWireBus = 2; // Pin D2 (GPIO 4) is used for the DS18B20 sensor
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

ESP8266WebServer server(80);

// Add this line at the beginning of your code, before the setup() function
#define DEBUG_MODE true

// Then, add this debugPrint() function:
void debugPrint(String message) {
  if (DEBUG_MODE) {
    Serial.println(message);
  }
}

// HTML content served by the Arduino
const char INDEX_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arduino Control</title>
    <style>
        button {
            font-size: 20px;
            padding: 10px;
            margin: 10px;
        }
    </style>
    <script>
        function sendCommand(command) {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    console.log("Command sent: " + command);
                }
            };
            xhttp.open("GET", "/control?command=" + command, true);
            xhttp.send();
        }

        function updateTemperature() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("temperature").innerHTML = this.responseText;
                }
            };
            xhttp.open("GET", "/temperature", true);
            xhttp.send();
        }
        setInterval(updateTemperature, 1000); // Update temperature every second
    </script>
</head>
<body>
    <h1>Arduino Control</h1>
    <button onclick="sendCommand('ledon')">Turn LED On</button>
    <button onclick="sendCommand('ledoff')">Turn LED Off</button>
    <p>Temperature: <span id="temperature">Loading...</span></p>
</body>
</html>
)=====";

void setup() {
  Serial.begin(115200);

  // Add this line at the beginning of your setup function
  debugPrint("Initializing...");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Make sure LED is initially off

  // Start DS18B20 sensor
  sensors.begin();

  // Route for root / web page
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", INDEX_HTML);
  });

  // Route to control the LED
  server.on("/control", HTTP_GET, []() {
    String command = server.arg("command");
    if (command == "ledon") {
      digitalWrite(ledPin, HIGH); // Turn LED on
    } else if (command == "ledoff") {
      digitalWrite(ledPin, LOW); // Turn LED off
    }
    server.send(200, "text/plain", "OK");
  });

  // Route to get temperature
  server.on("/temperature", HTTP_GET, []() {
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    if (temperatureC == -127.00 || temperatureC == 85.00) {
      debugPrint("Temperature sensor not found or reading not ready");
      server.send(200, "text/plain", "Error: Temperature sensor not found");
    } else {
      debugPrint("Temperature: " + String(temperatureC, 2) + " °C");
      server.send(200, "text/plain", String(temperatureC, 2));
    }
  });

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
