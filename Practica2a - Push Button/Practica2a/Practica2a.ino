const int LED = 13;
const int BOTON = 7;
int VALOR = 0;

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(BOTON,INPUT);
  }

void loop(){
  VALOR = digitalRead(BOTON);
  if (VALOR==HIGH){
    digitalWrite(LED,HIGH);
    }
    else {digitalWrite(LED,LOW);
    }
  }
