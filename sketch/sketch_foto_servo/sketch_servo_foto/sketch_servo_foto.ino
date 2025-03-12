#include <Servo.h>
Servo servo1;
int lr = 350;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  Serial.begin(9600);
  lr = analogRead(A0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int l,i;
  l = analogRead(A0);
  Serial.print("Luminosità: ");
  Serial.print(l);
  if (l < lr) {
    for(i=0; l < lr && i < 180; i++){
      servo1.write(i);
      l=analogRead(A0);
      delay(20);
    }
    if(i==180){
      for(i=180; l < lr && i>0; i--){
        servo1.write(i);
        l=analogRead(A0);
        delay(20);
      }
    }
  } 
  delay(1000);
}
