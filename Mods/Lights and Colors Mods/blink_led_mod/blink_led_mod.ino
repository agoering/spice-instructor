#include <Pinball.h>


void setup() {
  
  pinMode(12, OUTPUT);

}


void loop() {

  digitalWrite(12, 1);
  delay(100);
  digitalWrite(12, 0);
  delay(1000);  

}

