//#include <Pinball.h>


int melody1[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0};
int timing1[] = { 250, 125, 125, 250, 250, 250, 250, 250, 10};

int coinnotes[] = {NOTE_DS4, NOTE_GS4, 0};
int cointimes[] = {125, 250, 10};
int coinlength = 3;

int beepboopnotes[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E4, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_C3, 0};
int beepbooptimes[] = {200, 200, 400, 200, 300, 200, 400, 200, 300, 200, 400, 200, 1200};
int beepbooplength = 12;

int arpeggionotes[] = {0, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, 0};
int arpeggiotimes[] = {10, 100, 100, 100, 600, 1000};
int arpeggiolength = 6;

int oneupnotes[] = {0, NOTE_E3, NOTE_G3, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G4, 0};
int oneuptimes[] = {10, 200, 200, 200, 200, 200, 200, 10};
int oneuplength = 8;

int levelupnotes[] = {0,\
  NOTE_G2, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, 0,\
  NOTE_GS2, NOTE_C3, NOTE_DS3, NOTE_GS3, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_DS4, 0,\
  NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_AS3, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5, 0}; 

int leveluptimes[] = {125,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 125, 125, 125, 925, 825};
  
int leveluplength = 31;

int gameovernotes[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E3, 0, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_AS3, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_G3, 0};
int gameovertimes[] = {10, 200, 400, 200, 300, 200, 300, 400, 400, 400, 400, 400, 400, 150, 150, 1200, 1000};
int gameoverlength = 17;

int batmannotes[] = {NOTE_G3, NOTE_G3, NOTE_FS3, NOTE_FS3, NOTE_F3, NOTE_F3, NOTE_FS3, NOTE_FS3, NOTE_G3, 0, NOTE_G3, 0};
int batmantimes[] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 1000, 10};

// A sliding upward tone

int slideupnotes[] = {\
  0, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2,\
  NOTE_E2,NOTE_F2,NOTE_FS2,NOTE_G2,\
  NOTE_GS2,NOTE_A2,NOTE_AS2,NOTE_B2,\
  NOTE_C3,NOTE_CS3,NOTE_D3,NOTE_DS3,\
  NOTE_E3,NOTE_F3,NOTE_FS3,NOTE_G3,\
  NOTE_GS3,NOTE_A3,NOTE_AS3,NOTE_B3,\
  NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,\
  NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,\
  NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4,NOTE_C5,0};
  
// A sliding downward tone; use with slidetimes and slidelength

int slidedownnotes[] = {\
  0, NOTE_C5, NOTE_B4, NOTE_AS4, \
  NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, \
  NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_D4,\
  NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_AS3,\
  NOTE_A3, NOTE_GS3, NOTE_G3, NOTE_FS3,\
  NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_D3,\
  NOTE_CS3, NOTE_C3, NOTE_B2, NOTE_AS2,\
  NOTE_A2, NOTE_GS2, NOTE_G2, NOTE_FS2,\
  NOTE_F2, NOTE_E2, NOTE_DS2, NOTE_D2,\
  NOTE_CS2, NOTE_C2, 0};
  
int slidetimes[] = {\
  500, 100, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 500, 1000};
  
int slidelength = 39;


int marionotes2[] = { \
\
  NOTE_C3, NOTE_C4, NOTE_A2, NOTE_A3, NOTE_GS2, NOTE_AS3, 0,\
  NOTE_C3, NOTE_C4, NOTE_A2, NOTE_A3, NOTE_GS1, NOTE_AS3, 0,\
\
  NOTE_G2, NOTE_G3, NOTE_E2, NOTE_E3, NOTE_F2, NOTE_F3, 0,\
  NOTE_G2, NOTE_G3, NOTE_E2, NOTE_E3, NOTE_F2, NOTE_F3, 0,\
\
  NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_D3, 0, NOTE_F3, 0, NOTE_E3, 0,\
  NOTE_AS2, 0, NOTE_A2, 0, NOTE_DS3, 0, NOTE_D3, NOTE_GS3, NOTE_G3, NOTE_FS3, \
  NOTE_C4, NOTE_B3, NOTE_AS3, 0, NOTE_F3, 0, NOTE_CS3, 0, NOTE_C3, 0, NOTE_B2, 0, NOTE_AS2, 0};
  
int mariotimes2[] = { \
\
  200, 200, 200, 200, 200, 200, 1000,           \
  200, 200, 200, 200, 200, 200, 1000,           \
\
  200, 200, 200, 200, 200, 200, 1000,           \
  200, 200, 200, 200, 200, 200, 1000,           \
\
  100, 100, 100, 200, 250, 200, 250, 200, 250,           \
  200, 250, 200, 250, 200, 250, 100, 100, 100, 100, \
  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 3000};


int mariolength2 = 61;

//void robototune(int robotochorusnotes, int robotochorustimes, int robotochoruslength) {
//  int robotonotes[] = {};
//  int robototimes[] = {};
//  int robotolength = 0;
//  
//  for(int i = 0; i<2; i++){
//    robotonotes += robotochorusnotes;
//    robototimes += robotochorustimes;
//    robotolength += robotochoruslength;
//  }
//}
//    
//
//int robotochorusnotes[] = {\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
//  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//0};
//
//int robotochorustimes[] = {\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//100};
//
//int robotochoruslength = 4*16+1;
//  
//
////int robotonotes[] = { \
////\
////  0, NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
////\
////  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
////\
////  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
////  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
////\
////  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_C4,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0,\
////\
////  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
////  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
////\
////  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
////  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
////  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
////0};
////
////int robototimes[] = { \
////\
////  100, 200, 600, 200, 600, 200, 600,\
////  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 400,\
////\
////  200, 600, 200, 600, 200, 600,\
////  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 400,\
////\
////  200, 600, 200, 600, 200, 600,\
////  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 400,\
////\
////  200, 600, 200, 600, 400,\
////  300, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////100};
//  
//int robotolength = 3*26+18+12+8*16;
//
////400 quarter note, 200 eighth note, 100 sixteenth note
////All vals for first part are 100
//

// FunkyTown
// These ones are used by playfLvals
int funky_intro_len = 24; //intro
int funky_intro_beat = 100;
int funky_intro_note[] = {NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, \
                            NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0};

int funky_gotta_len = 32; // town thats right for me
int funky_gotta_beat = 100;
int funky_gotta_note[] = {NOTE_C3, NOTE_C3, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, \
                          NOTE_E3, NOTE_E3, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, \
                          NOTE_G3, NOTE_G3, NOTE_G3, 0, NOTE_G3, 0, NOTE_E4, 0, 0, 0, NOTE_D4, 0, 0, NOTE_C4};
                          
int funky_talk_len = 35; // talk about it
int funky_talk_beat = 100;
int funky_talk_note[] = {NOTE_C4, 0, NOTE_C4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0,\
                         NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, 0};

int funky_intromod_len = 25; // lowered intro
int funky_intromod_beat = 100;
int funky_intromod_note[] = {NOTE_G3, NOTE_G3, NOTE_G3, 0, NOTE_G3, 0, NOTE_F3, 0, NOTE_G3, 0, 0, 0, NOTE_D3, 0, 0, 0, \
                            NOTE_D3, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_B3, 0, NOTE_G3, 0};
          
int funky_talk2_len = 33; // talk about movin
int funky_talk2_beat = 100;
int funky_talk2_note[] = {NOTE_D4, 0, 0, 0, NOTE_D4, 0, NOTE_D4, 0, 0, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0,\
  NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, 0, 0, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3};

int funky_moveon_len = 26; // channel (after talk about movin)
int funky_moveon_beat = 100;
int funky_moveon_note[] = {NOTE_C4, 0, 0, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, \
                          NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0};

int funky_bridge_len = 40;
int funky_bridge_beat = 100;
int funky_bridge_note[] = {0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_E3, 0, 0, 0, \
                              NOTE_E3, 0, 0, 0, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, \
                            NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3};

// These ones are used by playfSvals and playfLvals
int funky_a_chorus_len = 12;
int funky_bcde_chorus_len = 10;
int funky_f_chorus_len = 24;
int funky_a_chorus_beat = 50;
int funky_bcdef_chorus_beat = 100;
int funky_a_chorus_note[] = {NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2,  0, NOTE_G2, NOTE_G2, NOTE_G2, 0, 0};
int funky_b_chorus_note[] = {NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0};
int funky_c_chorus_note[] = {NOTE_AS3, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0};
int funky_d_chorus_note[] = {NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0};
int funky_e_chorus_note[] = {NOTE_AS3, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_DS3, NOTE_DS3, NOTE_DS3, 0};
int funky_f_chorus_note[] = {0, 0, 0, 0, NOTE_G4, NOTE_G4, NOTE_G4, 0, NOTE_G4, 0, NOTE_F4, 0, NOTE_DS4, 0,\
                             NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4};


// CHORUS: 
//A, B, 
//A, C, 
//A, D, 
//A, E,
//A, B, 
//A, C, 
//A, D, 
//F

// A
//  NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2,  0, NOTE_G2, NOTE_G2, NOTE_G2, 0, 0, \
//  300, 50,  50, 100, 100, \
// B
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
  
// C
//  NOTE_AS3, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0,\
//  100, 100,100, 100, 100, 100, 300, 100,\

// D
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\

// E
//  NOTE_AS3, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_DS3, NOTE_DS3, NOTE_DS3, 0,\
//  100, 100, 100, 100, 100, 100, 300, 100,\

// F
//  0, 0, 0, 0, NOTE_G4, NOTE_G4, NOTE_G4, 0, NOTE_G4, 0, NOTE_F4, 0, NOTE_DS4, 0, \
//  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, \
//  400, 300, 100, 100, 100, 100, 100, 100, 100, 1000,\



//int funkynotes2[] = {
//\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, \
//  300, 50,  50, 100, 100, \
  
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//    
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0,\
//  300, 50,  50, 100, 100,\
  
//  NOTE_AS3, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, 0,\
//  100, 100,100, 100, 100, 100, 300, 100,\
  
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, \
//  300, 50,  50, 100, 100,\
  
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
  
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, \
//  300, 50,  50, 100, 100,\
//  
//  NOTE_AS3, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_DS3, 0,\
//  100, 100, 100, 100, 100, 100, 300, 100,\
\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, \
//  300, 50,  50, 100, 100, \
//  
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//    
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0,\
//  300, 50,  50, 100, 100,\
//  
//  NOTE_AS3, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, 0,\
//  100, 100,100, 100, 100, 100, 300, 100,\
//  
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, \
//  300, 50,  50, 100, 100,\
//  
//  NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\  
  
//  0, NOTE_G4, 0, NOTE_G4, 0, NOTE_F4, 0, NOTE_DS4, 0, NOTE_C4,\
//  400, 300, 100, 100, 100, 100, 100, 100, 100, 1000,\
//0
//3000};
  
//int funkytimes2[] = {
//\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//\
//  300, 50, 50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//\
//  400, 300, 100, 100, 100, 100, 100, 100, 100, 1000,\
//\
//3000};

