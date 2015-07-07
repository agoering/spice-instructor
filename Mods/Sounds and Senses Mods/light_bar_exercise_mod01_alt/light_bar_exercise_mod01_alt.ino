#include <Pinball.h>

int clkpin = 8;    // Scoreboard clock pin
int diopin = 9;    // Scoreboard data pin

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);    

int shclk = 12;     // Shift registers clock pin
int shlatch = 11;    // Shift registers latch pin
int shdata = 10;     // Shift registers data pin
int numreg = 2;     // Number of shift registers in series

// Declare shift registers object named shregs 
Pb_outputs shregs(shdata, shclk, shlatch, numreg);

byte serdata[2];    // Array for shift register data

int aval;           // Variable for analog sensor value
int oldval;         // Variable to keep track of previous value
int apin = A0;      // Analog input sensor pin
int jj;

int temp;

void setup() {
  
  serdata[0] = 0b00000000; serdata[1] = 0b00000000;
  shregs.update(serdata);
  myboard.blankdisplay(); delay(250);
  
}

void loop() {
  
  readinputs();       // Read all the input sensors
  dologic();          // Perform logical operations
  writeoutputs();     // Control all output components
  
}


void readinputs() {
  
  aval = analogRead(apin);  

}

void dologic() {
  temp = (aval-60)/57;

  if (oldval != temp) {
    if (temp < 16) { 
//    tone(spkr_pin, a*100, 50); 
  }

    oldval = temp;
    if (temp < 9) {
      serdata[0] = 0b00000000;
      for (jj = 0; jj < 8; jj++) {
        if (jj < temp) {
          bitWrite(serdata[1], jj, 1);
        } else {
          bitWrite(serdata[1], jj, 0);        
        }
      }
    } else {
      serdata[1] = 0b11111111;
      for (jj = 0; jj < 8; jj++) {
        if (jj < temp - 8) {
          bitWrite(serdata[0], jj, 1);
        } else {
          bitWrite(serdata[0], jj, 0);        
        }
      }
    }
  }

}

void writeoutputs() {

  shregs.update(serdata);  
//  myboard.showdisplay(aval);  // To see raw analog value  
  myboard.showdisplay(temp);    // To see modified distance value

}
