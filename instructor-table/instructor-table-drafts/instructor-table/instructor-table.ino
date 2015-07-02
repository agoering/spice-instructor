#include <Pinball.h>

#include "tunelibrary.h"

//_________________________________________PIN DEFINITIONS_______

// Pinball scoreboard
int clkpin = 8, diopin = 9;

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);

// Use speaker object
Pb_speaker spkr(13);

// Sensors and switches
int redswitch = A3, greenswitch = A4, blueswitch = A5, nailswitch = A6, rollswitch = A7, drainswitch = 4;


// Use buttons as switches
Pb_switch mysw0(100), mysw1(100), mysw2(100), mysw3(100), mysw4(100), mysw5(100);

// Use shift registers to control LEDs (except RGB LEDs)
Pb_outputs shregs(10, 11, 12, 5); // (datapin, clkpin, latchpin, numreg)

// Use timed events to avoid using delay
Pb_timedevent songlights(lednotes);

// Pins for RGB LEDs
int redled = 7;
int greenled = 6;
int blueled = 5;





//_________________________________________________FLAGS________

// Flags to keep track of button presses and song number
int redflag, greenflag, blueflag, nailflag, rollflag, drainflag, startup;

// These are from Jukebox
int num, songvar;

//_________________________________________ANALOG SENSORS_______

//There are no analog sensors in a jukebox! But you could add a FSR volume control...

//// Use sensorValue0 to keep track of analog sensor
//int sensorPin0 = A2;
//int sensorValue0 = 0;
//// Record the minimum and maximum values of analog sensor
//int Min0 = 10;
//int Max0 = 1023;

//_____________________________________________SETUP___________

void setup() {
  
  // This step is important for digital switches
  pinMode(redswitch, INPUT); 
  digitalWrite(redswitch, 1);
  pinMode(greenswitch, INPUT); 
  digitalWrite(greenswitch, 1);     
  pinMode(blueswitch, INPUT); 
  digitalWrite(blueswitch, 1);
  pinMode(nailswitch, INPUT); 
  digitalWrite(nailswitch, 1);
  pinMode(rollswitch, INPUT);
  digitalWrite(rollswitch, 1);
  pinMode(drainswitch, INPUT);
  digitalWrite(drainswitch, 1);
  
 // Initial values
  redflag = 0; greenflag = 0; blueflag = 0; nailflag = 0; rollflag = 0; drainflag = 0;
  startup = 1;

// From Jukebox
  num = 0; songvar = 0;
  
 
  myboard.showdisplay(num);  // Initialize scoreboard to 0
  spkr.update();
  lednotes(0);
//  slideuplights();
//  songlights.start(slideupnotes, slidetimes, slidelength); // Game start lights
}

//____________________________________________THE LOOP___________

void loop() {
  readinputs();   // Read all the inputs
  dologic();    // Figure out what to do based on inputs
  writeoutputs();  // Control all output components
}

//____________________________________________INPUTS___________

void readinputs() {

  redflag = 0; greenflag = 0; blueflag = 0; nailflag = 0; rollflag = 0;
  
  // Use flags to record which switches have been pushed
  redflag = mysw0.pushed( digitalRead(A3) );
  greenflag = mysw1.pushed( digitalRead(A4) );
  blueflag = mysw2.pushed( digitalRead(A5) );  
  nailflag = mysw3.pushed( digitalRead(A6) );    
  rollflag = mysw4.pushed( digitalRead(A7) );  
  drainflag = mysw5.pushed( digitalRead(4) );
}

//____________________________________________LOGIC___________

void dologic() {
  if (startup == 1) {
    spkr.start(slideupnotes, slidetimes, slidelength); // Game start tune
    startup = 0;
  }
  if (drainflag == 1) {   // If switch 0 has been pushed, decrease number
    num = num - 1;
    if (num < 0) {    // Don't let num go below zero
      num = 0;
    }
  }
  
  
  if (blueflag == 1) {  // If switch 2 has been pushed, increase number
    num = num + 1;
    if (num > 99) {   // Don't let num go above 99
      num = 99;
    }      
  }
}

//___________________________________________OUTPUT___________

void writeoutputs() {

  

  // Update the speaker and lights
  spkr.update();
  songlights.update();
  
  // Update the and scoreboard only if needed  
  if ( (redflag + blueflag) > 0 ) {  
    myboard.showdisplay(num);      // Output the number to the scoreboard
  }
  
  if (greenflag == 1) {
    playsong(num);                   // Play the correct song
  }
  
  
  if (nailflag == 1) {
//      spkr.stop();                   // Stop the song and lights
//      songlights.stop();
//    for(int i = 0; i < 2; i++){
      playsong(num); // Play songs twice
      playsong(num);
//    }
  
  }
  
  
}



//___________________________________________SPECIAL FUNCTIONS___________

//void changenum(int ww) {
//
//    myboard.showdisplay(num);
//    
//}  

void playsong(int n) {

  switch(n) {
  case 1:      // Game starts
    spkr.start(slideupnotes, slidetimes, slidelength);
    songlights.start(slideupnotes, slidetimes, slidelength);
    break;
  case 2:      // Score +1 song. Play 5 times if score 5 points.
    spkr.start(coinnotes, cointimes, coinlength);
    songlights.start(coinnotes, cointimes, coinlength);
    break;
  case 3:      // Drain switch song (except at end of game)
    spkr.start(slidedownnotes, slidetimes, slidelength);
    songlights.start(slidedownnotes, slidetimes, slidelength);
    break;    
  case 4:      // Play with "Transistor" system when extra ball drops
    spkr.start(oneupnotes, oneuptimes, oneuplength);
    songlights.start(oneupnotes, oneuptimes, oneuplength);
    break;
  case 5:      // Play arpeggio every 100 points
    spkr.start(arpeggionotes, arpeggiotimes, arpeggiolength);
    songlights.start(arpeggionotes, arpeggiotimes, arpeggiolength);
    break;
  case 6:      // Level up song (beat the game)
    spkr.start(levelupnotes, leveluptimes, leveluplength);
    songlights.start(levelupnotes, leveluptimes, leveluplength);
    break;    
  case 7:      // Game over
    spkr.start(gameovernotes, gameovertimes, gameoverlength);
    songlights.start(gameovernotes, gameovertimes, gameoverlength);
    break;
//  case 8:      // Mr. Roboto
//    spkr.start(shortrobotonotes, shortrobototimes, shortrobotolength);
//    songlights.start(shortrobotonotes, shortrobototimes, shortrobotolength);
//    break;
//  case 9:      // Funkytown
//    spkr.start(funkynotes, funkytimes, funkylength);
//    songlights.start(funkynotes, funkytimes, funkylength);
//    break;
  default:     // Stop playing song
    spkr.stop(); songlights.stop(); lednotes(0);
    break;
  }
}

void slideuplights(){
  // Turn on the lights from the bottom up
 byte serdata[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 } ;
  for(int i = 0; i <= 8; i++){
//    for(int j = 0; j<8; j++){
      bitWrite(serdata[0], i, 1);
      bitWrite(serdata[1], i, 1);
      shregs.update(serdata); 
//    bitWrite(serdata[i], 0,1);
//    bitWrite(serdata[i]
//    }
    
  }
}
void lednotes(int note) {
 // Makes LED light up based on note frequency!

 byte serdata[] = { 0b00000000, 0b00000000 } ;
 
 
 if ( note < NOTE_G2) { // do nothing 
 } 
 else if ( note < NOTE_C3 ) { bitWrite(serdata[1], 0, 1); }
 else if ( note < NOTE_DS3 ) { bitWrite(serdata[1], 1, 1); }
 else if ( note < NOTE_FS3 ) { bitWrite(serdata[1], 2, 1); }
 else if ( note < NOTE_B3 ) { bitWrite(serdata[1], 3, 1); }
 else if ( note < NOTE_C4 ) { bitWrite(serdata[1], 4, 1); }
 else if ( note < NOTE_CS4 ) { bitWrite(serdata[1], 5, 1); }
 else if ( note < NOTE_D4 ) { bitWrite(serdata[1], 6, 1); }
 else if ( note < NOTE_DS4 ) { bitWrite(serdata[1], 7, 1); }
 else if ( note < NOTE_E4 ) { bitWrite(serdata[0], 0, 1); }
 else if ( note < NOTE_F4 ) { bitWrite(serdata[0], 1, 1); }
 else if ( note < NOTE_FS4 ) { bitWrite(serdata[0], 2, 1); }
 else if ( note < NOTE_G4 ) { bitWrite(serdata[0], 3, 1); }
 else if ( note < NOTE_A4 ) { bitWrite(serdata[0], 4, 1); }
 else if ( note < NOTE_AS4 ) { bitWrite(serdata[0], 5, 1); }
 else if ( note < NOTE_B4 ) { bitWrite(serdata[0], 6, 1); }
 else  { bitWrite(serdata[0], 7, 1); }
 
 shregs.update(serdata); 
  
}
