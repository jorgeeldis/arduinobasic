const int relay = 11;


void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  digitalWrite(relay, HIGH);
  Serial.println ("relay: 1");
  delay(1000);
  digitalWrite(relay, LOW);
  Serial.println ("relay: 0");
  delay(1000);
}
