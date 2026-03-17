#include <Servo.h>

Servo hookServo;      // Servo 1: Ball Collection Hook
Servo gateServo;      // Servo 2: Storage Release Gate

bool hookActive = false;
bool gateActive = false;

int pad1_y = 511;     // Forward/Backward
int pad2_x = 511;     // Left/Right
int slider_value = 0; // PWM Speed

void setup() {
  Serial.begin(9600);

  // Motor Pins
  pinMode(3, OUTPUT); pinMode(4, OUTPUT); // Left Motor
  pinMode(5, OUTPUT); pinMode(6, OUTPUT); // Right Motor
  pinMode(11, OUTPUT); pinMode(12, OUTPUT); // Enable Pins (PWM)

  hookServo.attach(8);
  gateServo.attach(9);
  hookServo.write(0); 
  gateServo.write(0);
}

void loop() {
  if (Serial.available()) {
    char data_in = Serial.read();

    if (data_in == 'V') slider_value = Serial.parseInt();

    // Pad 1: Movement (Vertical Axis)
    if (data_in == 'A') {
      while (true) {
        if (Serial.available()) {
          data_in = Serial.read();
          if (data_in == 'Y') pad1_y = Serial.parseInt();
          if (data_in == 'B') break;
        }
      }
    }

    // Pad 2: Steering (Horizontal Axis)
    if (data_in == 'C') {
      while (true) {
        if (Serial.available()) {
          data_in = Serial.read();
          if (data_in == 'X') pad2_x = Serial.parseInt();
          if (data_in == 'D') break;
        }
      }
    }

    // Manual Servo Control (As described in README)
    if (data_in == 'E') { 
      hookActive = !hookActive;
      hookServo.write(hookActive ? 90 : 0);
    }
    if (data_in == 'F') { 
      gateActive = !gateActive;
      gateServo.write(gateActive ? 90 : 0);
    }
  }

  // --- Differential Drive Logic ---
  if (pad1_y < 511) {      // Forward
    moveRobot(1, 0, 0, 1); 
    if (pad2_x < 511) moveRobot(1, 0, 0, 0); // Left
    if (pad2_x > 511) moveRobot(0, 0, 0, 1); // Right
  } 
  else if (pad1_y > 511) { // Backward
    moveRobot(0, 1, 1, 0);
    if (pad2_x < 511) moveRobot(0, 1, 0, 0); // Left
    if (pad2_x > 511) moveRobot(0, 0, 1, 0); // Right
  } 
  else {                   // Stop
    moveRobot(0, 0, 0, 0);
  }

  analogWrite(11, slider_value);
  analogWrite(12, slider_value);
}

// Helper function to clean up the code
void moveRobot(int p3, int p4, int p5, int p6) {
  digitalWrite(3, p3); digitalWrite(4, p4);
  digitalWrite(5, p5); digitalWrite(6, p6);
}
