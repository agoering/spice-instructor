/*
  Program to test the Pb_speaker beat track mechanism from Pinball.h
  Attach speaker to pin 13 and ground. Attache button (which shorts to ground 
  when pressed) to pin 4.
*/

#include <Pinball.h>

// Contains notes and timing array for some looped soundtrack
// See Pinball library folder for file contents
#include "tunelibrary.h"

// funky beat time needs to be an integer instead of an array
// This is meant to save space so redundant single value arrays are avoided


// Initializing speaker
Pb_speaker spkr(13);

int buttonpin = 4;
Pb_switch mysw(200);   // Using this to debounce button pushes


Pb_timedevent playfunky(funkyelem); // Timed array to play long tunes
int playfSlen = 15;
int playfSvals[] = {11, 12, 11, 13, 11, 14, 11, 15, 11, 12, 11, 13, 11, 14, 16}; // Array of cases
int playfStime[] = {funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_bcdef_chorus_beat*funky_f_chorus_len}; // Array of times              
// Long funkytown
int playfLlen = 20+15;                   
int playfLvals[] = {0, 1, 0, 2, 3, 5, 0, 2, 3, 5, 0, 5, 4, 6, 7, 8, 0, 1, 9, 10,\
                   11, 12, 11, 13, 11, 14, 11, 15, 11, 12, 11, 13, 11, 14, 16}; // Array of cases
int playfLtime[] = {funky_intro_beat*funky_intro_len, 800,\
                   funky_intro_beat*funky_intro_len, 600,\
                   funky_gotta_beat*funky_gotta_len, 200,\
                   funky_intro_beat*funky_intro_len, 600,\
                   funky_gotta_beat*funky_gotta_len, 200,\
                   funky_intro_beat*funky_intro_len, 200,\
                   funky_talk_beat*funky_talk_len,\
                   funky_intromod_beat*funky_intromod_len, 700,\
                   funky_talk2_beat*funky_talk2_len,\
                   funky_moveon_beat*funky_moveon_len, 800,\
                   funky_intro_beat*funky_intro_len, 800,\
                   funky_bridge_beat*funky_bridge_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_a_chorus_beat*funky_a_chorus_len,\
                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
                   funky_bcdef_chorus_beat*funky_f_chorus_len};// Array of times
                   
                   

void setup() {

  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
  
  spkr.loopstart(beepboopnotes, beepbooptimes, beepbooplength);
  // spkr.loopstop() is also defined
}

void loop() {

  spkr.update();    // This needs to be called every loop iteration
  playfunky.update();
  
  if ( mysw.pushed( digitalRead(buttonpin) ) ) {
    // This temporarily pauses loop to play sound effect, see mariotracks.h for definitions
    playfunky.start(playfLvals, playfLtime, playfLlen);
    //    spkr.startbeat(funkynotes, funkybeattime, funkylength);
    // spkr.beatstop() is also defined
  }
 
  
}

void funkyelem(int elem) {
 
 switch (elem) {
   case 0: // intro
     spkr.startbeat(funky_intro_note, funky_intro_beat, funky_intro_len);
     break;
   case 1: // long rest
     spkr.startbeat(0, 800, 1);
     break;
   case 2: // short rest
     spkr.startbeat(0, 600, 1);
     break;
   case 3: //gotta move to a town that's right for me
     spkr.startbeat(funky_gotta_note, funky_gotta_beat, funky_gotta_len);
     break;
   case 4: // talk about it
     spkr.startbeat(funky_talk_note, funky_talk_beat, funky_talk_len);
     break;
   case 5: //real short rest
     spkr.startbeat(0, 200, 1);
     break;
   case 6: // modified intro
     spkr.startbeat(funky_intromod_note, funky_intromod_beat, funky_intromod_len);
     break;
   case 7: //700rest
     spkr.startbeat(0, 700, 1);
     break;
   case 8: // talk about moving
     spkr.startbeat(funky_talk2_note, funky_talk2_beat, funky_talk2_len);
     break;
   case 9: // gotta move on
     spkr.startbeat(funky_moveon_note, funky_moveon_beat, funky_moveon_len);
     break;
   case 10: // bridge
     spkr.startbeat(funky_bridge_note, funky_bridge_beat, funky_bridge_len);
     break;
   case 11: // funky a chorus
     spkr.startbeat(funky_a_chorus_note, funky_a_chorus_beat, funky_a_chorus_len);
     break;
   case 12: // funky b chorus
     spkr.startbeat(funky_b_chorus_note, funky_bcdef_chorus_beat, funky_bcde_chorus_len);
     break;
   case 13: // funky c chorus
     spkr.startbeat(funky_c_chorus_note, funky_bcdef_chorus_beat, funky_bcde_chorus_len);
     break;
   case 14: // funky d chorus
     spkr.startbeat(funky_d_chorus_note, funky_bcdef_chorus_beat, funky_bcde_chorus_len);
     break;
   case 15: // funky e chorus
     spkr.startbeat(funky_e_chorus_note, funky_bcdef_chorus_beat, funky_bcde_chorus_len);
     break;
   case 16: // funky f chorus
     spkr.startbeat(funky_f_chorus_note, funky_bcdef_chorus_beat, funky_f_chorus_len);
     break;
 }
}
