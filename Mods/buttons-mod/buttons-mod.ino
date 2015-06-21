#include <Pinball.h>

int ledpin = 12;
int ledb = 11;
int buttonpin = 10;

int ontimeb = 500;

void setup() {
  
  pinMode(ledpin, OUTPUT);
  pinMode(ledb, OUTPUT);
  
  pinMode(buttonpin, INPUT); 
  digitalWrite(buttonpin, 1);

}


void loop() {

  digitalWrite(ledb, 1);
  delay(ontimeb);
  digitalWrite(ledb, 0);
  delay(ontimeb); 
  
  if ( digitalRead(buttonpin) == LOW ) {
    digitalWrite(ledpin, 1);
  }
  else {
    digitalWrite(ledpin, 0);
  }
  
}

