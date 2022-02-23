#define PIN_LED_1 11 //Pin al que conectamos el led del jugador 1
#define PIN_BOTON_1 12 //Pin al que conectamos el botón del jugador 1
#define PIN_LED_2 2 //Pin al que conectamos el led del jugador 2
#define PIN_BOTON_2 3 //Pin al que conectamos el botón del jugador 2
#define PIN_SALIDA 7 //Pin al que conectamos el led verde de salida

byte game_over; //Variable para indicar que el juego se ha acabado

void setup() {
  pinMode(PIN_LED_1, OUTPUT); //Declaramos los pines de entrada
  pinMode(PIN_BOTON_1, INPUT); //y salida
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_BOTON_2, INPUT);
  pinMode(PIN_SALIDA, OUTPUT);
  game_over = 0; //Al comienzo del juego
  digitalWrite(PIN_LED_1, LOW); //apagamos ledes de jugadores
  digitalWrite(PIN_LED_2, LOW);
  digitalWrite(PIN_SALIDA, HIGH); //Encendemos el led de salida
  delay(random(5000)); //Tiempo aleatorio entre 1 y 5 segundos
  digitalWrite(PIN_SALIDA, LOW); //Pistoletazo de salida
}

void loop() {
  byte boton_1 = digitalRead(PIN_BOTON_1);
  byte boton_2 = digitalRead(PIN_BOTON_2);
  if ((boton_1 == 1) && (game_over == 0)) { //Jugador 1 gana
    digitalWrite(PIN_LED_1, HIGH);
    game_over = 1;
  }
  if ((boton_2 == 1) && (game_over == 0)) { //Jugador 2 gana
    digitalWrite(PIN_LED_2, HIGH);
    game_over = 1;
  }
  delay(10); //Una pausa para no volvernos locos
}
