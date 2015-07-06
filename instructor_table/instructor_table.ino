#include <Pinball.h>

#include "arrays.h"

int servo_pin = 2;                   // Servo control pin 3
int servo_length = 5;                // Number of pulses (any duration) required to turn by 90 degrees 
int spkr_pin = 13;
Pb_speaker spkr(spkr_pin);           // Speaker pin 13
Pb_outputs shregs(10, 12, 11, 5);    // Shift registers (data, clk, latch, number of registers)
Pb_scoreboard myboard(8, 9);         // Scoreboard (clock, data)

byte serdata[5];                     // For the five shift registers
// serdata[4,3] are sideboard LEDs
// serdata[2,1] are FSR cable LEDs
// serdata[0] = 0b L3, L2, L1, Null, R1, R2, R3, R4
// R1, R2, R3, R4 are resistor bands. L1, L2, L3 are lives

int RGB_R = 7, RGB_B = 6, RGB_G = 5;              // RGB pins
int ir_pin = A0, piezo_pin = A6, fsr_pin = A7;    // IR, Piezo, FSR pins
int red_pin = 17, green_pin = 18, blue_pin = 19;  // RGB switch pins (A3, A4, A5)
int nail_pin = 15, roll_pin = 16, drain_pin = 4;  // nail, roller, drain switch pins (A6, A7, 4)

// Switches for RGB, nail, roller, and drain
Pb_switch red_sw(50), green_sw(50), blue_sw(50), nail_sw(50), roll_sw(50), drain_sw(50);

// Flags for the same
int red_flag, green_flag, blue_flag, nail_flag, roll_flag, drain_flag;

// Game specific global variables
int ii, num_lives = 3, score = 0, score_flag, rgb_tracking[3], rgb_flag;
int fsr_val, fsr_oldval = 0, fsr_flag = 0, fsr_delay = 200, ir_delay = 1000;
int ir_thresh = 800, piezo_thresh = 800, ir_val, piezo_val, piezo_delay = 1000;
int ir_flag = 0, piezo_flag = 0;
int max_score = 1000;

// Timed events
Pb_timedevent sideLEDflash(sideflash);
Pb_timedevent scoreflash(flashscore);
Pb_timedevent rgb_off(turnoffrgb);
Pb_timedevent resistorLEDflash(resistorLEDcolors);
Pb_timedevent fsr_servo(turntheservo);
Pb_timedevent runservo(servofunc);
Pb_timedevent playfunky(funkyelem); // Timed array to play long tunes

// Stopwatch for fsr, ir, and piezo debounce
Pb_stopwatch mywatch, mywatch_ir, mywatch_piezo;   

void update_music_and_events() {
  
  spkr.update();
  sideLEDflash.update();
  scoreflash.update();
  rgb_off.update();
  resistorLEDflash.update();
  fsr_servo.update();
  runservo.update();
  playfunky.update();
  
}



void setup() {
  // put your setup code here, to run once:

  pinMode(red_pin, INPUT); pinMode(green_pin, INPUT); pinMode(blue_pin, INPUT);
  pinMode(nail_pin, INPUT); pinMode(roll_pin, INPUT); pinMode(drain_pin, INPUT); 
  // Enable pullup resistors on digital input pins
  digitalWrite(red_pin, HIGH); digitalWrite(green_pin, HIGH); digitalWrite(blue_pin, HIGH);
  digitalWrite(nail_pin, HIGH); digitalWrite(roll_pin, HIGH); digitalWrite(drain_pin, HIGH); 
  
  pinMode(servo_pin, OUTPUT); digitalWrite(servo_pin, LOW);

  for(ii = 0; ii < 5; ii++) {
    serdata[ii] = 0b00000000;
  }
  serdata[0] = 0b11100000;               // For lives
  shregs.update(serdata);

  rgb_tracking[0] = 0; rgb_tracking[1] = 0; rgb_tracking[2] = 0;
  delay(50);
  spkr.loopstart(beep_vals, beep_time, beep_len);
  myboard.showdisplay(score);
  sideLEDflash.loopstart(beep_vals, beep_time, beep_len-1);
//  sideLEDflash.loopstart(sideflashloop,slideflashtime, 2);
  spkr.start(startup_vals, startup_time, startup_len);
  sideLEDflash.start(startup_vals, startup_time, startup_len);
  
}



void loop() {
  // put your main code here, to run repeatedly:

  if (num_lives > 0) {
    readinputs();
    dologic();
    writeoutputs();
  }
  
  update_music_and_events();   

}




void readinputs() {
  
  red_flag = 0; green_flag = 0; blue_flag = 0;
  nail_flag = 0; roll_flag = 0; drain_flag = 0; 
  
  red_flag = red_sw.pushed(digitalRead(red_pin));
  green_flag = green_sw.pushed(digitalRead(green_pin));
  blue_flag = blue_sw.pushed(digitalRead(blue_pin));  
  nail_flag = nail_sw.pushed(digitalRead(nail_pin));
  roll_flag = roll_sw.pushed(digitalRead(roll_pin));
  drain_flag = drain_sw.pushed(digitalRead(drain_pin));
  
  fsr_val = map(analogRead(fsr_pin), 0, fsr_max, 0, 16);
  ir_val = analogRead(ir_pin);
  piezo_val = analogRead(piezo_pin);
  
}



void dologic() {
  
  score_flag = 0; rgb_flag = 0;
  
  if (red_flag + green_flag + blue_flag > 0) {
    rgb_flag = 1;
    rgb_tracking[0] = rgb_tracking[0] + red_flag * (1 - rgb_tracking[0]);
    rgb_tracking[1] = rgb_tracking[1] + green_flag * (1 - rgb_tracking[1]);
    rgb_tracking[2] = rgb_tracking[2] + blue_flag * (1 - rgb_tracking[2]);    
    if (rgb_tracking[0] + rgb_tracking[1] + rgb_tracking[2] < 3) {
      score = score + 1; score_flag = 1;
    } else { 
      score = score + 5; score_flag = 2; 
    }
  }
  
  if (nail_flag == 1) { score = score + 1; score_flag = 3; }
  
  if (fsr_val == 16) {
     if (fsr_flag == 0) { // fsr_flag is being used to prevent double counting
      score = score + 100; score_flag = 4;
      fsr_flag = 1;
      if (num_lives < 3) { num_lives = num_lives + 1; }
      mywatch.start();
     } 
  } else if (fsr_flag > 0) {
     if (mywatch.time() > fsr_delay) { 
       fsr_flag = 0;
       mywatch.stop();
     } 
  }
  
  if (ir_val > ir_thresh) { 
    if (ir_flag == 0) {
      score = score + 1; score_flag = 5; 
      ir_flag = 1;
      mywatch_ir.start();
    }
  } else if (ir_flag > 0) {
    if (mywatch_ir.time() > ir_delay) {
      ir_flag = 0;
      mywatch_ir.stop();
    }
  }
  
  if (piezo_val > piezo_thresh) { 
    if (piezo_flag == 0) {
      score = score + 1; score_flag = 6; 
      piezo_flag = 1;
      mywatch_piezo.start();
    }
  } else if (piezo_flag > 0) {
    if (mywatch_piezo.time() > piezo_delay) {
      piezo_flag = 0;
      mywatch_piezo.stop();
    }
  }
  
  if (roll_flag == 1) { score = score + 1; score_flag = 7; }
  
  if (drain_flag == 1) { num_lives = num_lives - 1; }
  
}



void writeoutputs() {
  
  int shreg_flag = 0, jj;
  
  if (fsr_flag == 1) {
    bitWrite(serdata[0], 8 - num_lives, 1);
  }   
 
 
  if (fsr_oldval != fsr_val) {
    if (fsr_val < 16) { tone(spkr_pin, fsr_val*100, 50); }
    shreg_flag = 1; 
    fsr_oldval = fsr_val;
    if (fsr_val < 9) {
      serdata[1] = 0b00000000;
      for (jj = 0; jj < 8; jj++) {
        if (jj < fsr_val) {
          bitWrite(serdata[2], jj, 1);
        } else {
          bitWrite(serdata[2], jj, 0);        
        }
      }
    } else {
      serdata[2] = 0b11111111;
      for (jj = 0; jj < 8; jj++) {
        if (jj < fsr_val - 8) {
          bitWrite(serdata[1], jj, 1);
        } else {
          bitWrite(serdata[1], jj, 0);        
        }
      }
    }
    if (fsr_flag == 1) { 
      fsr_servo.start(fsrarrayvals, fsrarraytime, fsrarraylen); 
      scoreflash.start(fsrarrayvals, fsrarraytime,fsrarraylen);
      spkr.start(oneup_vals, oneup_time, oneup_len);
    }
  }
  
  switch (score_flag) {
    case 1:
      spkr.start(coin_vals, coin_time, 3);
      break;
    case 5:
//      sideLEDflash.start(roboto_vals, roboto_time, roboto_len);   
      spkr.startbeat(roboto_vals, 100, roboto_len);
//        spkr.start(roboto_vals, roboto_time, roboto_len);
      break;
    case 6:
//      sideLEDflash.start(playfSvals, playfStime, playfSlen);
//      spkr.loopstop();
      playfunky.start(playfSvals, playfStime, playfSlen); // Using beats
//      sideLEDflash.start(funk_vals, funk_time, funk_len);    
//      spkr.start(funk_vals, funk_time, funk_len);
      break;
  }
  
  if (drain_flag == 1) {
    shreg_flag = 1;
    bitWrite(serdata[0], 7 - num_lives, 0);
    spkr.start(life_vals, startup_time, life_len);     
    if (num_lives > 0) {
      sideLEDflash.start(sidelifeflash, sidelifetime, 20);   
    } else {
      sideLEDflash.loopstop();   
      sideLEDflash.start(deathLED, deathtime, 33);
      scoreflash.loopstart(scflashvals, scflashtime,2);
      spkr.loopstop();
      spkr.start(death_vals, death_time, death_len); 
    }
  }
  

  if (nail_flag > 0) {
    resistorLEDflash.start(colorLEDvals, sidelifetime, 17);
    spkr.start(scoreone_vals, scoreone_time, scoreone_len);
  }  
  
  if (roll_flag > 0) {
    sideLEDflash.start(shiftpatvals, shiftpattime, 17);
    spkr.start(scoreone_vals, scoreone_time, scoreone_len);
  }
  
  if (rgb_flag > 0) { 
    digitalWrite(RGB_R, rgb_tracking[0]);
    digitalWrite(RGB_G, rgb_tracking[1]);
    digitalWrite(RGB_B, rgb_tracking[2]);    
    if (score_flag == 2) { 
      rgb_off.start(rgboffvals, rgbofftime, 2); 
      spkr.start(coin_vals, coin_time, 15);      
      sideLEDflash.start(sidelifeflash, scoreuptime, 20);
    } else {
      sideLEDflash.start(sidelifeflash, scoreuptime, 4);
    }
  }
  
  if (shreg_flag > 0) { shregs.update(serdata); }
  if (score_flag > 0) { myboard.showdisplay(score); }    
  
  if (score >= max_score) { 
     num_lives = 0; 
     sideLEDflash.loopstop();   
     sideLEDflash.start(levelupnotes, leveluptimes, leveluplength);
     scoreflash.loopstart(scflashvals, scflashtime,2);
     spkr.loopstop();
     spkr.start(levelupnotes, leveluptimes, leveluplength); 
  }
  
}


void sideflash(int val) {
 
  if (val < 2) {
    if (val == 0) { serdata[3] = 0b00000000; serdata[4] = 0b00000000; }
    else { serdata[3] = 0b11111111; serdata[4] = 0b11111111; }  
  }
  else if (val < 35) {
    if (val == 2) {
      serdata[1] = 0b11111111; serdata[2] = 0b11111111; serdata[3] = 0b11111111; serdata[4] = 0b11111111;
    } else if (val < 11) {
      bitWrite(serdata[1], 10 - val, 0);    
    } else if (val < 19) {
      bitWrite(serdata[2], 18 - val, 0);
    } else if (val < 27) {
      bitWrite(serdata[3] , 26 - val, 0);
    } else { bitWrite(serdata[4], 34 - val, 0); }
  } else {
    if (serdata[3] == 0b00000000) { serdata[3] = 0b11111111; }
    else { serdata[3] = 0b00000000; }
    if (serdata[4] == 0b00000000) { serdata[4] = 0b11111111; }
    else { serdata[4] = 0b00000000; }
  }
  shregs.update(serdata);
  
}


void flashscore(int val) {
 
  if (val == 1) { myboard.blankdisplay(); }
  else { myboard.showdisplay(score); }
  
}


void turnoffrgb(int val) {
 
  if (val == 1) { 
    rgb_tracking[0] = 0; rgb_tracking[1] = 0; rgb_tracking[2] = 0;
    digitalWrite(RGB_R, LOW);
    digitalWrite(RGB_G, LOW);
    digitalWrite(RGB_B, LOW);
  }
  
}

void resistorLEDcolors(int val) {
 
  switch(val) {
    case 0:
      bitWrite(serdata[0], 0, 0);
      bitWrite(serdata[0], 1, 0);
      bitWrite(serdata[0], 2, 0);
      bitWrite(serdata[0], 3, 0);
      break;      
    case 1:  
      bitWrite(serdata[0], 0, 1);
      bitWrite(serdata[0], 1, 0);
      bitWrite(serdata[0], 2, 0);
      bitWrite(serdata[0], 3, 0);
      break;      
    case 2:  
      bitWrite(serdata[0], 0, 0);
      bitWrite(serdata[0], 1, 1);
      bitWrite(serdata[0], 2, 0);
      bitWrite(serdata[0], 3, 0);
      break;
    case 3:  
      bitWrite(serdata[0], 0, 0);
      bitWrite(serdata[0], 1, 0);
      bitWrite(serdata[0], 2, 1);
      bitWrite(serdata[0], 3, 0);
      break;
    default:  
      bitWrite(serdata[0], 0, 0);
      bitWrite(serdata[0], 1, 0);
      bitWrite(serdata[0], 2, 0);
      bitWrite(serdata[0], 3, 1);
      break;      
  } 
  shregs.update(serdata);
  
}


void turntheservo(int val) {
  
  switch(val) {
    case 0:
      // Turn servo on here
      runservo.start(sidelifeflash, sidelifetime, servo_length*2);
      serdata[1] = 0b11111111; serdata[2] = 0b11111111;
      break;
    case 1:
      serdata[1] = 0b00000000; serdata[2] = 0b00000000;
      break;
    case 2:
      serdata[1] = 0b11111111; serdata[2] = 0b11111111;
      break;
    case 3:
      serdata[1] = 0b00000000; serdata[2] = 0b00000000;
      break;    
  }
  
  shregs.update(serdata);
  
}

void servofunc(int val) {
   
 digitalWrite(servo_pin, val); 
  
}

void funkyelem(int elem) {
 
 switch (elem) {
   // 0-10 are not actually used by playfSvals...
//   case 0: // intro
//     spkr.startbeat(funky_intro_note, funky_intro_beat, funky_intro_len);
//     break;
//   case 1: // long rest
//     spkr.startbeat(0, 800, 1);
//     break;
//   case 2: // short rest
//     spkr.startbeat(0, 600, 1);
//     break;
//   case 3: //gotta move to a town that's right for me
//     spkr.startbeat(funky_gotta_note, funky_gotta_beat, funky_gotta_len);
//     break;
//   case 4: // talk about it
//     spkr.startbeat(funky_talk_note, funky_talk_beat, funky_talk_len);
//     break;
//   case 5: //real short rest
//     spkr.startbeat(0, 200, 1);
//     break;
//   case 6: // modified intro
//     spkr.startbeat(funky_intromod_note, funky_intromod_beat, funky_intromod_len);
//     break;
//   case 7: //700rest
//     spkr.startbeat(0, 700, 1);
//     break;
//   case 8: // talk about moving
//     spkr.startbeat(funky_talk2_note, funky_talk2_beat, funky_talk2_len);
//     break;
//   case 9: // gotta move on
//     spkr.startbeat(funky_moveon_note, funky_moveon_beat, funky_moveon_len);
//     break;
//   case 10: // bridge
//     spkr.startbeat(funky_bridge_note, funky_bridge_beat, funky_bridge_len);
//     break;
   case 11: // funky a chorus
     spkr.startbeat(funky_a_chorus_note, 50, 12);
     break;
   case 12: // funky b chorus
     spkr.startbeat(funky_b_chorus_note, 100, 10);
     break;
   case 13: // funky c chorus
     spkr.startbeat(funky_c_chorus_note, 100, 10);
     break;
   case 14: // funky d chorus
     spkr.startbeat(funky_d_chorus_note, 100, 10);
     break;
   case 15: // funky e chorus
     spkr.startbeat(funky_e_chorus_note, 100, 10);
     break;
   case 16: // funky f chorus
     spkr.startbeat(funky_f_chorus_note, 100, 24);
     break;
 }
}
