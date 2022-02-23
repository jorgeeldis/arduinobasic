// Programa para modificar la intensidad de un LED usando PWM
int LED = 3;                // Salida PWM a utilizar con el LED.
void setup() {
  // Bloque de código de configuración.
  pinMode(LED, OUTPUT);
}
void loop() {
  analogWrite(LED, 50);     // Enciende el LED
  delay(1000);              // Espera un segundo
  analogWrite(LED, 100);    // Enciende el LED
  delay(1000); 
  analogWrite(LED, 150);    // Enciende el LED
  delay(1000); 
  analogWrite(LED, 200);    // Enciende el LED
  delay(1000); 
  analogWrite(LED, 250);    // Enciende el LED
  delay(1000); 
}
