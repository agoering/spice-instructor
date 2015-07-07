// Store songs, soundeffects, and timed-event arrays here.

// LED effects

// LEDs flashing in loop throughout the game
int flashloop[] = {1, 0};
int flashtime[] = {1000, 1000};

// Shift register pattern
int shiftpatvals[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
int shiftpattime[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};

// LEDs flashing fast when a life is lost
int lifeflash[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
int lifetime[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

// Scoreflash when game is over
int scflashvals[] = {1, 0};
int scflashtime[] = {500, 500};





// Songs and sound effects 

// Beep Boop 
int beep_len = 6;
int beep_vals[] = {NOTE_A2, 0, NOTE_D3, 0, NOTE_A2, 0};
int beep_time[] = {100, 900, 100, 900, 100, 900};

// Startup sound
int startup_len = 8;
int startup_vals[] = {NOTE_A2, 0, NOTE_A2, 0, NOTE_A2, 0, NOTE_C3, 0};
int startup_time[] = {100, 50, 100, 50, 100, 50, 1000, 10};

// Coin sound
int coin_vals[] = {NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0, NOTE_DS4, NOTE_GS4, 0};
int coin_time[] = {125, 250, 10, 125, 250, 10, 125, 250, 10, 125, 250, 10, 125, 250, 10};

// +1 score sound
int scoreone_len = 2;
int scoreone_vals[] = {NOTE_DS4, NOTE_GS4, 0};
int scoreone_time[] = {125, 250, 10};

// oneup sound
int oneup_len = 18;
int oneup_vals[] = {NOTE_C2, 0, NOTE_C2, 0, NOTE_C2, 0, NOTE_GS2, 0, NOTE_GS2, 0, NOTE_GS2, 0, NOTE_A2, 0, NOTE_A2, 0, NOTE_A2, 0}; 
int oneup_time[] = {100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10, 100, 10};

// Life lost 
int life_len = 3;
int life_vals[] = {NOTE_C3, NOTE_A2, 0};
int life_time[] = {125, 500, 10};

// Death track
int death_len = 8;
int death_vals[] = {NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_A2, 0};
int death_time[] = {100, 50, 100, 50, 100, 50, 1000, 10};
