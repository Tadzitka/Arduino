// Definicje pinów
#define trigPin 7
#define echoPin 8

// Stała do obliczania odległości w centymetrach
const float SOUND_SPEED = 0.0343 / 2;

void setup() {
  // Inicjalizacja pinów
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(9, OUTPUT);
  
  // Włączenie transmisji szeregowej
  Serial.begin(9600);
}

void loop() {
  // Wyłączenie trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Włączenie trigPin na 10 mikrosekund
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Odczytanie czasu trwania sygnału echoPin
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  // Obliczenie odległości w centymetrach
  float distance = duration * SOUND_SPEED;
  
  // Wypisanie odległości w centymetrach
  Serial.print("Odleglosc: ");
  Serial.print(distance);
  Serial.println(" cm");
  

  if (distance < 100) {
    digitalWrite(9, LOW);
  }
  else {
    digitalWrite(9, HIGH);
  }
  
  // Odczekanie 500 milisekund
  delay(500);
}
