#include <Pinball.h>

//_________________________________________PIN DEFINITIONS_______
// These are the button pins
int button0 = 4;
int button1 = 5;
int button2 = 6;
int button3 = 7;

// Pinball scoreboard
int clkpin = 8;
int diopin = 9;

//_________________________________________SPECIAL OBJECTS_______

// Define buttons as switches
Pb_switch mysw0(100), mysw1(100), mysw2(100), mysw3(100);

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);

// Use timed events to avoid using delay
Pb_timedevent scoreboard(changenum);
int val[] = { 0 };
int timing[] = { 250 };

//_________________________________________________FLAGS________

// Flags to keep track of button presses
int flag0, flag1, flag2, flag3;
// Use num as flag to keep track of some number
int num, num2;


//_________________________________________ANALOG SENSORS_______

// Use sensorValue0 to keep track of analog sensor
int sensorPin0 = A2;
int sensorValue0 = 0;
// Record the minimum and maximum values of analog sensor
int Min0 = 10;
int Max0 = 1023;

//_____________________________________________SETUP___________

void setup() {
  
  // This step is important for digital switches
  pinMode(button0, INPUT); 
  digitalWrite(button0, 1);
  pinMode(button1, INPUT); 
  digitalWrite(button1, 1);     
  pinMode(button2, INPUT); 
  digitalWrite(button2, 1);
  pinMode(button3, INPUT); 
  digitalWrite(button3, 1);
  
  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0;

// Put decimal partition at location 2
  myboard.setpartition(2);
  myboard.blankpredisplay();
  myboard.blankpostdisplay(); 
  
  // Initial number flag values
  num = 0;
  num2 = 0;
  
  scoreboard.loopstart(val, timing, 1);

}

//____________________________________________THE LOOP___________

void loop() {
  
  // Read all the inputs
  readinputs();
  
  // Figure out what to do based on inputs
  dologic();
  
  // Write to the outputs
  writeoutputs();

}

//____________________________________________INPUT STUFF___________

void readinputs() {

  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0;
  
  // Use flags to record which switches have been pushed
  flag0 = mysw0.pushed( digitalRead(button0) );
  flag1 = mysw1.pushed( digitalRead(button1) );
  flag2 = mysw2.pushed( digitalRead(button2) );  
  flag3 = mysw3.pushed( digitalRead(button3) );    
  
  // Use more flags to record the values of analog inputs
  sensorValue0 = analogRead(sensorPin0);
  
}

//____________________________________________LOGIC STUFF___________

void dologic(){
  rightpartition();
  leftpartition();
}

void leftpartition(){
    // map the sensor range to 99
  num2 = map(sensorValue0, Min0, Max0, 0, 99);
}
  
void rightpartition(){
  // Logic for right partition
    if (flag0 + flag1 + flag2 + flag3 > 0){
    // At least one button has been pressed
      if (num < 1000){

        if (flag0 == 1){
          num = num + 1;
        }
        if (flag1 == 1){
          num = num + 10;
        }
        if (flag2 == 1){
          num = num + 100;
        }
      }
      else{num = 0;}
    }
    else{
    // Don't do anything if there's nothing to do!
    }
}


//___________________________________________OUTPUT STUFF___________

void writeoutputs() {
  
  // Update the scoreboard
  scoreboard.update();    
}

void changenum(int ww) {

    myboard.postdisplay(num);
    myboard.predisplay(num2);
    
}  

