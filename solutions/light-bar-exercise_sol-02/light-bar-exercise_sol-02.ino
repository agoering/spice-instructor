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

Pb_speaker spkr(13);  // Speaker on pin 13

int melody[] = {0, 0};     // melody array (start with zeros)
// First number is note, second is pause
// We will update note, live
int timing[] = {50, 1025}; // timing array 
// First number is length of note, second is length of pause
// We will update length of pause, live

int aval;           // Variable for analog sensor value

int apin = A0;      // Analog input sensor pin

int temp;

void setup() {
  
  serdata[0] = 0b00000000; serdata[1] = 0b00000000;
  shregs.update(serdata);
  myboard.blankdisplay(); delay(250);
  spkr.loopstart(melody, timing, 2);
  
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
  
  serdata[0] = 0b00000000; serdata[1] = 0b00000000;
  temp = (aval-60)/57;
  switch (temp) {  
    case 1:
            serdata[1] = 0b00000001; break;    
    case 2:
            serdata[1] = 0b00000011; break;    
    case 3:
            serdata[1] = 0b00000111; break;    
    case 4:
            serdata[1] = 0b00001111; break;    
    case 5:
            serdata[1] = 0b00011111; break;    
    case 6:
            serdata[1] = 0b00111111; break;    
    case 7:
            serdata[1] = 0b01111111; break;    
    case 8:
            serdata[1] = 0b11111111; break;    
    case 9:
            serdata[0] = 0b00000001; serdata[1] = 0b11111111; break;    
    case 10:
            serdata[0] = 0b00000011; serdata[1] = 0b11111111; break;    
    case 11:
            serdata[0] = 0b00000111; serdata[1] = 0b11111111; break;        
    case 12:
            serdata[0] = 0b00001111; serdata[1] = 0b11111111; break;        
    case 13:
            serdata[0] = 0b00011111; serdata[1] = 0b11111111; break;        
    case 14:
            serdata[0] = 0b00111111; serdata[1] = 0b11111111; break;        
    case 15:
            serdata[0] = 0b01111111; serdata[1] = 0b11111111; break;        
    case 16:
            serdata[0] = 0b11111111; serdata[1] = 0b11111111; break;        
  }
  
  melody[0] = aval*4;     // decrease multiplier for lower frequency range
  timing[1] = 1025-aval;  // changes time between notes
  // If you want to change length of note, change timing[0]
  spkr.loopstart(melody, timing, 2);  // Send the speaker function the new info


}

void writeoutputs() {
  spkr.update();                // make sure speaker is updated
  shregs.update(serdata);  
//  myboard.showdisplay(aval);  // To see raw analog value  
  myboard.showdisplay(temp);    // To see modified distance value
//  myboard.showdisplay(melody[0]);  // To see note being played
}
