#include <Servo.h>
Servo servo1; //oggetto servo
int lr = 350; // variabile di riferimento dichiarata qui come globale così poi può essere utilizzata in tutto il codice
int t=90; //rotazione costante
// attualmente non prevedo il cambiamento di luminosità che può avvenire in caso di avvicinamento della notte
// sarebbe utile aggiungere una nuova variabile temporanea per la ricerca che completate entrambe le ricerce a vuoto
// fa una nuova ricerca per cercare il valore di luminosità più alto e la relativa posizione per poi andare a piazzarsi 
// li una volta completata questa ricerca

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9); //serve per configurare la porta (PWM) a cui è collegato il servo.
  servo1.write(t); // fisso la prima rotazione all'angolo standard
  Serial.begin(9600); //tempo di lettura simboli per microsecond
  lr = analogRead(A0); //inizializzazione ad un valore standard della variabile di riferimento
}

void loop() {
  // put your main code here, to run repeatedly:
  int l,i;
  l = analogRead(A0);
  Serial.print("Luminosità: ");
  Serial.print(l); // prima stampa i valori rilevati
  servo1.write(t); // mantengo la rotazione o al valore standard o al nuovo assegnato durante la ricerca
  if (l < lr) { // se il valore rilevato è sotto lo standard vuol dire che il pannello è in ombra
    for(i=90; l < lr && i < 180; i++){ // effettua una rotazione prima in un senso alla ricerca di un valore che indichi luce
      servo1.write(i); // indica l'ampiezza di rotazione
      l=analogRead(A0);
      delay(20);
    }
    t=i; // assegnazione al valore standard della nuova posizione
    if(i==180 && l<lr){ // se è arrivato alla fine della prima rotazione senza trovare niente allora deve fare il secondo giro
      for(i=180; l < lr && i>90; i--){ // seconda rotazione ma in senso opposto
        servo1.write(i);
        l=analogRead(A0);
        delay(20);
      }
      t=i; //assegnazione al valore standard della nuova posizione
    }
  } 
  delay(1000);
}
