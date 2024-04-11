#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Orange_Multany";
const char* password = "Kaczorek5";

const int ledPin = 13;
const int anotherPin = 12;

ESP8266WebServer server(80);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(anotherPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(anotherPin, LOW);

  Serial.begin(115200);
  Serial.println();
  Serial.print("WiFi connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  Serial.println("WiFi Connected Success!");
  Serial.print("NodeMCU IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/control", handleControl);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", "<h1>Hello from Arduino!</h1>");
}

void handleControl() {
  String command = server.arg("command");
  if (command == "pin13on") {
    digitalWrite(ledPin, HIGH);
  } else if (command == "pin13off") {
    digitalWrite(ledPin, LOW);
  } else if (command == "pin12on") {
    digitalWrite(anotherPin, HIGH);
  } else if (command == "pin12off") {
    digitalWrite(anotherPin, LOW);
  }
  server.send(200, "text/plain", "OK");
}
