int val = 0;   // variable para almacenar valor de lectura del pin A0

void setup() {
        Serial.begin(9600);     //configura la velocidad de transmisión de datos
}

void loop() {
   val = analogRead(0);             // el valor de la lectura se almacena en la variable creada
   Serial.print("El valor es: ");         //Imprime el mensaje entre comillas y se mantiene en el renglón
   Serial.println(val);             //imprime el valor y salta a la siguiente línea
   delay(1000);
   Serial.print("El valor en binario es: ");  //Imprime el mensaje entre comillas y se mantiene en el renglón
   Serial.println(val,BIN);           //imprime el valor en binario y salta a la siguiente línea
   delay(1000);
   Serial.print("El valor en hexadecimal es: ");  //Imprime el mensaje entre comillas y se mantiene en el renglón
   Serial.println(val,HEX);           //imprime el valor en hexadecimal y salta a la siguiente línea
   delay(1000);
   Serial.println(1.555,2); //escribe 1.555 en el monitor serial con 2 decimales 
   delay(1000); 
   Serial.println(1.555,0); //escribe 1.555 en el monitor serial con 0 decimales 
}
