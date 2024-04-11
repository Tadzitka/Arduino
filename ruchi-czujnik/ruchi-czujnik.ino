// Definicja pinu czujnika PIR
#define PIR_PIN 2

void setup() {
  // Inicjalizacja transmisji szeregowej
  Serial.begin(9600);
  
  // Inicjalizacja pinu czujnika PIR jako wejście
  pinMode(PIR_PIN, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // Odczytanie stanu czujnika PIR
  int pirState = digitalRead(PIR_PIN);
  
  // Sprawdzenie, czy wykryto ruch
  if (pirState == HIGH) {
    Serial.println("Ruch wykryty!");
  } else {
    Serial.println("Brak ruchu.");
  }
  
  // Odczekanie 500 milisekund
  delay(500);
}
