// Store songs, soundeffects, and timed-event arrays here.

// Side LEDs flashing in loop throughout the game
//int sideflashloop[] = {1, 0};
//int sideflashtime[] = {1000, 1000};

// Side LEDs flashing fast when a life is lost
int sidelifeflash[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
int sidelifetime[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

// Side and top LEDs when game is over
int deathLED[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
int deathtime[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};

// Scoreflash at end game
int scflashvals[] = {1, 0};
int scflashtime[] = {500, 500};

// RGB turn off after some time timed event
int rgboffvals[] = {0, 1};
int rgbofftime[] = {1900, 10};

// Score up coin_sound timing array, use sidelifeflash[] array for side LED vals
int scoreuptime[] = {50, 50, 250, 50, 50, 50, 250, 50, 50, 50, 250, 50, 50, 50, 250, 50, 50, 50, 250, 50};

// Flash LED resistor color code vals array, use sidelifetime[] for timing
int colorLEDvals[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 0};

// FSR stuff
int fsr_max = 800;    // This is the maximum expected analog readout of fsr
int fsrarraylen = 8;
int fsrarrayvals[] = {0, 1, 2, 1, 2, 1, 2, 3}; // 0 starts servo and music, 1 & 2 blink base LEDs, 3 turns servo off
int fsrarraytime[] = {250, 250, 250, 250, 250, 250, 250, 250};

// Shift register pattern
int shiftpatvals[] = {1, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19};
int shiftpattime[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};





// Songs and sound effects (temporary placeholder notes and array lengths, Please replace with actual)
// Mr. Roboto, length needs to be longer by one, Arduino memory problems
//int roboto_len = 8;
//int roboto_vals[] = {NOTE_C3, NOTE_C4, NOTE_A2, NOTE_A3, NOTE_GS2, NOTE_AS3, 0};
//int roboto_time[] = { 200, 200, 200, 200, 200, 200, 1000};

int roboto_len = 64;
int roboto_vals[] = {\
\
  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//int roboto_time[] = {\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//100};


// Funky Town

// These ones are used by playfLvals
//int funky_intro_len = 24; //intro
//int funky_intro_beat = 100;
//int funky_intro_note[] = {NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, \
//                            NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0};
//
//int funky_gotta_len = 32; // town thats right for me
//int funky_gotta_beat = 100;
//int funky_gotta_note[] = {NOTE_C3, NOTE_C3, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, \
//                          NOTE_E3, NOTE_E3, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, \
//                          NOTE_G3, NOTE_G3, NOTE_G3, 0, NOTE_G3, 0, NOTE_E4, 0, 0, 0, NOTE_D4, 0, 0, NOTE_C4};
//                          
//int funky_talk_len = 35; // talk about it
//int funky_talk_beat = 100;
//int funky_talk_note[] = {NOTE_C4, 0, NOTE_C4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0,\
//                         NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, 0};
//
//int funky_intromod_len = 25; // lowered intro
//int funky_intromod_beat = 100;
//int funky_intromod_note[] = {NOTE_G3, NOTE_G3, NOTE_G3, 0, NOTE_G3, 0, NOTE_F3, 0, NOTE_G3, 0, 0, 0, NOTE_D3, 0, 0, 0, \
//                            NOTE_D3, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_B3, 0, NOTE_G3, 0};
//          
//int funky_talk2_len = 33; // talk about movin
//int funky_talk2_beat = 100;
//int funky_talk2_note[] = {NOTE_D4, 0, 0, 0, NOTE_D4, 0, NOTE_D4, 0, 0, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0,\
//  NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, 0, 0, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3};
//
//int funky_moveon_len = 26; // channel (after talk about movin)
//int funky_moveon_beat = 100;
//int funky_moveon_note[] = {NOTE_C4, 0, 0, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, \
//                          NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0};
//
//int funky_bridge_len = 40;
//int funky_bridge_beat = 100;
//int funky_bridge_note[] = {0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_E3, 0, 0, 0, \
//                              NOTE_E3, 0, 0, 0, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, \
//                            NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3};

// These ones are used by playfSvals and playfLvals
//int funky_a_chorus_len = 12;
//int funky_bcde_chorus_len = 10;
//int funky_f_chorus_len = 24;
//int funky_a_chorus_beat = 50;
//int funky_bcdef_chorus_beat = 100;
int funky_a_chorus_note[] = {NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2,  0, NOTE_G2, NOTE_G2, NOTE_G2, 0, 0};
int funky_b_chorus_note[] = {NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0};
int funky_c_chorus_note[] = {NOTE_AS3, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0};
int funky_d_chorus_note[] = {NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0};
int funky_e_chorus_note[] = {NOTE_AS3, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_DS3, NOTE_DS3, NOTE_DS3, 0};
int funky_f_chorus_note[] = {0, 0, 0, 0, NOTE_G4, NOTE_G4, NOTE_G4, 0, NOTE_G4, 0, NOTE_F4, 0, NOTE_DS4, 0,\
                             NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4};


int playfSlen = 15;
int playfSvals[] = {11, 12, 11, 13, 11, 14, 11, 15, 11, 12, 11, 13, 11, 14, 16}; // Array of cases
int playfStime[] = {600, 1000, 600, 1000, 600, 1000, 600, 1000, 600, 1000, 600, 1000, 600, 1000, 2400};// Array of times              
// Long funkytown
//int playfLlen = 20+15;                   
//int playfLvals[] = {0, 1, 0, 2, 3, 5, 0, 2, 3, 5, 0, 5, 4, 6, 7, 8, 0, 1, 9, 10,\
//                   11, 12, 11, 13, 11, 14, 11, 15, 11, 12, 11, 13, 11, 14, 16}; // Array of cases
//int playfLtime[] = {funky_intro_beat*funky_intro_len, 800,\
//                   funky_intro_beat*funky_intro_len, 600,\
//                   funky_gotta_beat*funky_gotta_len, 200,\
//                   funky_intro_beat*funky_intro_len, 600,\
//                   funky_gotta_beat*funky_gotta_len, 200,\
//                   funky_intro_beat*funky_intro_len, 200,\
//                   funky_talk_beat*funky_talk_len,\
//                   funky_intromod_beat*funky_intromod_len, 700,\
//                   funky_talk2_beat*funky_talk2_len,\
//                   funky_moveon_beat*funky_moveon_len, 800,\
//                   funky_intro_beat*funky_intro_len, 800,\
//                   funky_bridge_beat*funky_bridge_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_a_chorus_beat*funky_a_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_bcde_chorus_len,\
//                   funky_bcdef_chorus_beat*funky_f_chorus_len};// Array of times
                   
//int funk_len = 34;
//int funk_vals[] = {NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_D3, 0, NOTE_F3, 0, NOTE_E3, 0,\
//  NOTE_AS2, 0, NOTE_A2, 0, NOTE_DS3, 0, NOTE_D3, NOTE_GS3, NOTE_G3, NOTE_FS3, \
//  NOTE_C4, NOTE_B3, NOTE_AS3, 0, NOTE_F3, 0, NOTE_CS3, 0, NOTE_C3, 0, NOTE_B2, 0, NOTE_AS2, 0};
//int funk_time[] = {100, 100, 100, 200, 250, 200, 250, 200, 250,			 \
//  200, 250, 200, 250, 200, 250, 100, 100, 100, 100, \
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 3000};
  
// Beep Boop // Arduino is ignoring first two notes. Don't know why.
//int beep_len = 6;
//int beep_vals[] = {NOTE_A2, 0, NOTE_D3, 0, NOTE_A2, 0};
//int beep_time[] = {100, 900, 100, 900, 100, 900};

int beep_len = 12;
int beep_vals[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E4, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_C3, 0};
int beep_time[] = {200, 200, 400, 200, 300, 200, 400, 200, 300, 200, 400, 200, 1200};

// Death track
//int death_len = 8;
//int death_vals[] = {NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_A2, 0};
//int death_time[] = {100, 50, 100, 50, 100, 50, 1000, 10};

int death_len = 17;
int death_vals[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E3, 0, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_AS3, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_G3, 0};
int death_time[] = {10, 200, 400, 200, 300, 200, 300, 400, 400, 400, 400, 400, 400, 150, 150, 1200, 1000};

// Life lost 
//int life_len = 3;
//int life_vals[] = {NOTE_C3, NOTE_A2, 0};
//int life_time[] = {125, 500, 10};
int life_len = 39;
int life_vals[] = {\
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
  // time is same as startup_time


// Coin sound
int coin_vals[] = {NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0};
int coin_time[] = {125, 250, 10, 125, 250, 10, 125, 250, 10, 125, 250, 10, 125, 250, 10};

// +1 score sound
int scoreone_len = 3;
int scoreone_vals[] = {NOTE_DS4, NOTE_GS4, 0};
int scoreone_time[] = {125, 250, 10};

// oneup sound
//int oneup_len = 18;
//int oneup_vals[] = {NOTE_C2, 0, NOTE_C2, 0, NOTE_C2, 0, NOTE_GS2, 0, NOTE_GS2, 0, NOTE_GS2, 0, NOTE_A2, 0, NOTE_A2, 0, NOTE_A2, 0}; 
//int oneup_time[] = {100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10};
int oneup_len = 8;
int oneup_vals[] = {0, NOTE_E3, NOTE_G3, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G4, 0};
int oneup_time[] = {10, 200, 200, 200, 200, 200, 200, 10};

// Startup sound
//int startup_len = 8;
//int startup_vals[] = {NOTE_A2, 0, NOTE_A2, 0, NOTE_A2, 0, NOTE_C3, 0};
//int startup_time[] = {100, 50, 100, 50, 100, 50, 1000, 10};
int startup_len = 39;
int startup_vals[] = {\
  0, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2,\
  NOTE_E2,NOTE_F2,NOTE_FS2,NOTE_G2,\
  NOTE_GS2,NOTE_A2,NOTE_AS2,NOTE_B2,\
  NOTE_C3,NOTE_CS3,NOTE_D3,NOTE_DS3,\
  NOTE_E3,NOTE_F3,NOTE_FS3,NOTE_G3,\
  NOTE_GS3,NOTE_A3,NOTE_AS3,NOTE_B3,\
  NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,\
  NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,\
  NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4, NOTE_C5, 0};
  
int startup_time[] = {\
  500, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 500, 1000};
  
  
int levelupnotes[] = {0,\
  NOTE_G2, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, 0,\
  NOTE_GS2, NOTE_C3, NOTE_DS3, NOTE_GS3, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_DS4, 0,\
  NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_AS3, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5, 0}; 

int leveluptimes[] = {125,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 125, 125, 125, 925, 825};
  
int leveluplength = 31;

