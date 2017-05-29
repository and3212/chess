/* Author: Liam Lawrence
 * Date: 5.28.17
 * Motor functions
 */

// Global motor variables
int stp = 2;
int dir = 3;
int MS1 = 4;
int MS2 = 5;
int EN = 6;
int SLP = 7;

char user_input;
int x;
int y;
int state;
  
// Initialize pins for controlling the stepper motors
void stepperMotorInit() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(SLP, OUTPUT);
  resetEDPins();
}

//Reset Easy Driver pins to default states
void resetEDPins() {
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
  digitalWrite(SLP, HIGH);
}

// Saves battery and disables motors
void motorSleep() {
  digitalWrite(SLP, LOW);
}

// Enables motors
void motorWake() {
  digitalWrite(SLP, HIGH);
}

// Step forward by x amount
void stepF(int x) {
  motorWake();
  
  digitalWrite(dir, LOW); // Pull direction pin low to move "forward"
  for(int i = 1; i < x; i++) {
    digitalWrite(stp,HIGH); // Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); // Pull step pin low so it can be triggered again
    delay(1);
  }
  motorSleep();
}

// Small step forward by x amount
void smallStepF(int x) {
  motorWake();
  
  digitalWrite(dir, LOW); // Pull direction pin low to move "forward"
  digitalWrite(MS1, HIGH); // Pull MS1, and MS2 high to set logic to 1/8th microstep resolution
  digitalWrite(MS2, HIGH);
  for(int i = 1; i < x; i++) {
    digitalWrite(stp, HIGH); // Trigger one step forward
    delay(1);
    digitalWrite(stp, LOW); // Pull step pin low so it can be triggered again
    delay(1);
  }
  motorSleep();
}

// Step backwards by x amount
void stepB(int x) {
  motorWake();

  digitalWrite(dir, HIGH); // Pull direction pin high to move in "reverse"
  for(int i = 1; i < x; i++) { 
    digitalWrite(stp,HIGH); // Trigger one step
    delay(1);
    digitalWrite(stp,LOW); // Pull step pin low so it can be triggered again
    delay(1);
  }
  motorSleep();
}

// Small step backwards by x amount
void smallStepB(int x) {
  motorWake();
  
  digitalWrite(dir, HIGH); // Pull direction pin low to move "forward"
  digitalWrite(MS1, HIGH); // Pull MS1, and MS2 high to set logic to 1/8th microstep resolution
  digitalWrite(MS2, HIGH);
  for(int i = 1; i < x; i++) {
    digitalWrite(stp, HIGH); // Trigger one step forward
    delay(1);
    digitalWrite(stp, LOW); // Pull step pin low so it can be triggered again
    delay(1);
  }
  motorSleep();
}
