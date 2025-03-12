#include <Servo.h>
Servo servo1; //oggetto servo
int lr = 350; // variabile di riferimento dichiarata qui come globale così poi può essere utilizzata in tutto il codice

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9); //serve per configurare la porta (PWM) a cui è collegato il servo.
  Serial.begin(9600); //tempo di lettura simboli per microsecond
  lr = analogRead(A0); //inizializzazione ad un valore standard della variabile di riferimento
}

void loop() {
  // put your main code here, to run repeatedly:
  int l,i;
  l = analogRead(A0);
  Serial.print("Luminosità: ");
  Serial.print(l); // prima stampa i valori rilevati
  if (l < lr) { // se il valore rilevato è sotto lo standard vuol dire che il pannello è in ombra
    for(i=0; l < lr && i < 180; i++){ // effettua una rotazione prima in un senso alla ricerca di un valore che indichi luce
      servo1.write(i); // indica l'ampiezza di rotazione
      l=analogRead(A0);
      delay(20);
    }
    if(i==180 && l<lr){ // se è arrivato alla fine della prima rotazione senza trovare niente allora deve fare il secondo giro
      for(i=180; l < lr && i>0; i--){ // seconda rotazione ma in senso opposto
        servo1.write(i);
        l=analogRead(A0);
        delay(20);
      }
    }
  } 
  delay(1000);
}
