void setup() {
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Orange_Multany";
const char* password = "Kaczorek5";

ESP8266WebServer server(80);

// Define the HTML content as a string
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
    <button onclick="sendCommand('pin13on')">Turn Pin 13 On</button>
    <button onclick="sendCommand('pin13off')">Turn Pin 13 Off</button>
    
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

  // Serve the HTML file
  server.on("/", HTTP_GET, []() {
    server.sendHeader("Content-Encoding", "gzip");
    server.send(200, "text/html", INDEX_HTML, sizeof(INDEX_HTML));
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
