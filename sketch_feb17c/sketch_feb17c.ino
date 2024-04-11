#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Orange_Multany";     // Change to your WiFi SSID
const char* password = "Kaczorek5"; // Change to your WiFi password

const int ledPin = 5; // GPIO 5 corresponds to pin D1 on many ESP8266 boards

ESP8266WebServer server(80);

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
</head>
<body>
    <h1>Arduino Control</h1>
    <button onclick="sendCommand('ledon')">LED Off</button>
    <button onclick="sendCommand('ledoff')">LED On</button>
    
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
    </script>
</body>
</html>
)=====";

void setup() {
  Serial.begin(115200);
  
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

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
