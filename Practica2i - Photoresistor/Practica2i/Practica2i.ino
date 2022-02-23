// Pin donde se conectan los leds
int pinLed1 = 2;
int pinLed2 = 3;
int pinLed3 = 4;
int pinLed4 = 5;
int pinLed5 = 6;
int pinLed6 = 7;
int pinLed7 = 8;
int pinLed8 = 9;
// Pin analogico de entrada para el LDR
int pinLDR = 0;
 
// Variable donde se almacena el valor del LDR
int valorLDR = 0;  
 
void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  pinMode(pinLed7, OUTPUT);
  pinMode(pinLed8, OUTPUT);
  
  //  Configurar el puerto serial
  Serial.begin(9600);
}
 
void loop()
{
  // Apagar todos los leds siempre que se inicia el ciclo
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed5, LOW);
  digitalWrite(pinLed6, LOW);
  digitalWrite(pinLed7, LOW);
  digitalWrite(pinLed8, LOW);
 
  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valorLDR= analogRead(pinLDR);
  
  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.println(valorLDR);
 
  // Encender los leds apropiados de acuerdo al valor de ADC
  if(valorLDR > 100)
  {
    digitalWrite(pinLed1, HIGH);
  }
  if(valorLDR > 200)
  {
    digitalWrite(pinLed2, HIGH);
  }
  if(valorLDR > 300)
  {
    digitalWrite(pinLed3, HIGH);
  }
    if(valorLDR > 400)
  {
    digitalWrite(pinLed4, HIGH);
  }
    if(valorLDR > 500)
  {
    digitalWrite(pinLed5, HIGH);
  }
    if(valorLDR > 600)
  {
    digitalWrite(pinLed6, HIGH);
  }
    if(valorLDR > 700)
  {
    digitalWrite(pinLed7, HIGH);
  }
    if(valorLDR > 800)
  {
    digitalWrite(pinLed8, HIGH);
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
