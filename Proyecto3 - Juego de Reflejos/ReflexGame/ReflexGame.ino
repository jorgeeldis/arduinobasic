#include "pitches.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //

#define PIN_LED_1 11 //Pin al que conectamos el led del jugador 1
#define PIN_BOTON_1 12 //Pin al que conectamos el botón del jugador 1
#define PIN_LED_2 5 //Pin al que conectamos el led del jugador 2
#define PIN_BOTON_2 6 //Pin al que conectamos el botón del jugador 2
#define PIN_LED_3 2 //Pin al que conectamos el led del jugador 2
#define PIN_BOTON_3 3 //Pin al que conectamos el botón del jugador 2
#define PIN_BOTON_4 44 //Pin al que conectamos el botón del jugador 2
#define PIN_SALIDA 7 //Pin al que conectamos el led verde de salida
byte game_over; //Variable para indicar que el juego se ha acabado
byte PuntosJorge;
byte PuntosRicardo;
byte PuntosJuan;
byte ronda;
byte menu;
void setup() {
  byte boton_4 = digitalRead(PIN_BOTON_4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenidos a");
  lcd.setCursor(0, 1);
  lcd.print("el proyecto 3");
  delay(3000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("El menu:");
  delay(3000);
    lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Boton 1: Iniciar");
  lcd.setCursor(0, 1);
  lcd.print("Boton 2: Info");
  pinMode(PIN_LED_1, OUTPUT); //Declaramos los pines de entrada
  pinMode(PIN_BOTON_1, INPUT); //y salida
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_BOTON_2, INPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_BOTON_3, INPUT);
  pinMode(PIN_BOTON_4, INPUT);
  pinMode(PIN_SALIDA, OUTPUT);
  game_over = 0; //Al comienzo del juego
  menu = 2;
  PuntosJorge = 0;
  PuntosRicardo = 0;
  PuntosJuan = 0;
  ronda = 1;
  digitalWrite(PIN_LED_1, LOW); //apagamos ledes de jugadores
  digitalWrite(PIN_LED_2, LOW);
  digitalWrite(PIN_LED_3, LOW);
}


void loop() {
  int A;
  int tempo=114; 

for(A=0; A<=2; A++) {

  byte boton_4 = digitalRead(PIN_BOTON_4);

  if ((boton_4 == 1) && (game_over <= 3)){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Juego de");
  lcd.setCursor(0, 1);
  lcd.print("Reflejos");
  digitalWrite(PIN_SALIDA, HIGH); //Encendemos el led de salida
  tone(8, 660);
  delay(500);
  tone(8, 550);
  delay(500);
  tone(8, 440);
  delay(500);
  noTone(8);
  delay(random(10000));//Tiempo aleatorio entre 1 y 5 segundos
  digitalWrite(PIN_SALIDA, LOW);
  ronda++;
  menu--;
}//Pistoletazo de salida


  byte boton_1 = digitalRead(PIN_BOTON_1);
  byte boton_2 = digitalRead(PIN_BOTON_2);
  byte boton_3 = digitalRead(PIN_BOTON_3);

    if ((boton_1 == 1) && (menu == 2)){
        // Play Fireball sound
  tone(8,NOTE_B5,100);
  delay(100);
  tone(8,NOTE_E6,850);
  delay(800);
  noTone(8);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Info del juego");
  lcd.setCursor(0, 1);
  lcd.print("de reflejos.");
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Consta de 3");
  lcd.setCursor(0, 1);
  lcd.print("jugadores y");
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("un juez.");
  lcd.setCursor(0, 1);
  lcd.print("El cual tocara");
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("el boton que");
  lcd.setCursor(0, 1);
  lcd.print("acciona el LED.");
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("El momento en");
  lcd.setCursor(0, 1);
  lcd.print("donde el LED se");
  delay(1000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("apague, uno de");
  lcd.setCursor(0, 1);
  lcd.print("los 3 jugadores");
  delay(1000);
    lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("presionara el");
  lcd.setCursor(0, 1);
  lcd.print("boton, el mas");
  delay(1000);
      lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("rapido ganara!");
  lcd.setCursor(0, 1);
  lcd.print("Son 3 rondas!");
  delay(1000);
        lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SUERTE!");
  delay(1000);
    lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Boton 1: Iniciar");
  lcd.setCursor(0, 1);
  lcd.print("Boton 2: Repetir");
}//Pistoletazo de salida

  
  if ((ronda > 1) && (boton_1 == 1) && (game_over <= 3)) { //Jorge gana
    digitalWrite(PIN_LED_1, HIGH);
    game_over++;
    PuntosJorge++;
    ronda--;
    menu--;
      // Play coin sound
  tone(8,NOTE_E6,125);
  delay(130);
  tone(8,NOTE_G6,125);
  delay(130);
  tone(8,NOTE_E7,125);
  delay(130);
  tone(8,NOTE_C7,125);
  delay(130);
  tone(8,NOTE_D7,125);
  delay(130);
  tone(8,NOTE_G7,125);
  delay(125);
  noTone(8);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jorge gana");
  lcd.setCursor(0, 1);
  lcd.print("la ronda!");
  delay(1000);
  digitalWrite(PIN_LED_1, LOW);
   Serial.println("El Jorge fue el ganador!");
   
  }
  if ((ronda > 1) && (boton_2 == 1) && (game_over <= 3)){ //Juan gana
    digitalWrite(PIN_LED_2, HIGH);
    game_over++;
    PuntosJuan++;
    ronda--;
    menu--;
      // Play coin sound
  tone(8,NOTE_E6,125);
  delay(130);
  tone(8,NOTE_G6,125);
  delay(130);
  tone(8,NOTE_E7,125);
  delay(130);
  tone(8,NOTE_C7,125);
  delay(130);
  tone(8,NOTE_D7,125);
  delay(130);
  tone(8,NOTE_G7,125);
  delay(125);
  noTone(8);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Juan gana");
  lcd.setCursor(0, 1);
  lcd.print("la ronda!");
    delay(1000);
  digitalWrite(PIN_LED_2, LOW);
    Serial.println("El Juan fue el ganador!");
    
  }
  if ((ronda > 1) && (boton_3 == 1) && (game_over <= 3)) { //Ricardo gana
    digitalWrite(PIN_LED_3, HIGH);
    game_over++;
    PuntosRicardo++;
    ronda--;
    menu--;
      // Play coin sound
  tone(8,NOTE_E6,125);
  delay(130);
  tone(8,NOTE_G6,125);
  delay(130);
  tone(8,NOTE_E7,125);
  delay(130);
  tone(8,NOTE_C7,125);
  delay(130);
  tone(8,NOTE_D7,125);
  delay(130);
  tone(8,NOTE_G7,125);
  delay(125);
  noTone(8);
      lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ricardo gana");
  lcd.setCursor(0, 1);
  lcd.print("la ronda!");
    delay(1000);
  digitalWrite(PIN_LED_3, LOW);
    Serial.println("El Ricardo fue el ganador!");
    
  }
  //delay(1000); //Una pausa para no volvernos locos

    if (game_over == 3){
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Fin del Juego");
  lcd.setCursor(0, 1);
  lcd.print("Puntuacion: ");
  delay(1000);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ricardo: ");
  lcd.setCursor(0, 1);
  lcd.print(PuntosRicardo);
  delay(1000);

    lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jorge: ");
  lcd.setCursor(0, 1);
  lcd.print(PuntosJorge);
  delay(1000);

    lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Juan: ");
  lcd.setCursor(0, 1);
  lcd.print(PuntosJuan);
  delay(1000);
  
  if (PuntosJorge == PuntosJuan == PuntosRicardo){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Empate por:");
  lcd.setCursor(0, 1);
  lcd.print(PuntosJuan);
  delay(1000);}

  if (PuntosJorge > PuntosJuan && PuntosJorge > PuntosRicardo){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gana Jorge:");
  lcd.setCursor(0, 1);
  lcd.print(PuntosJorge);
  delay(1000);}

  if (PuntosRicardo > PuntosJuan && PuntosRicardo > PuntosJorge){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gana Ricardo:");
  lcd.setCursor(0, 1);
  lcd.print(PuntosRicardo);
  delay(1000);}
  
  if (PuntosJuan > PuntosJorge && PuntosJuan > PuntosRicardo){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gana Ricardo:");
  lcd.setCursor(0, 1);
  lcd.print(PuntosJuan);
  delay(1000);}
  }
  }
}
