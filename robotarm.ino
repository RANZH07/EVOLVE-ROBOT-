#include <Servo.h> // Include the Servo library

// Create Servo objects for 4 servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Assign potentiometer pins
int pot1Pin = A5; // Potentiometer 1 connected to A0
int pot2Pin = A4; // Potentiometer 2 connected to A1
int pot3Pin = A3; // Potentiometer 3 connected to A2
int pot4Pin = A2; // Potentiometer 4 connected to A3

// Assign servo signal pins
int servo1Pin = 4; // Servo 1 connected to Pin 3
int servo2Pin = 5; // Servo 2 connected to Pin 5
int servo3Pin = 6; // Servo 3 connected to Pin 6
int servo4Pin = 7; // Servo 4 connected to Pin 9

// Variables to store potentiometer values and servo angles
int potValue1, potValue2, potValue3, potValue4;
int servoAngle1, servoAngle2, servoAngle3, servoAngle4;

// Delay times (in milliseconds) for each servo
int delay1 = 50;  // Delay for servo 1
int delay2 = 50;  // Delay for servo 2
int delay3 = 50;  // Delay for servo 3
int delay4 = 50;  // Delay for servo 4

void setup() {
  // Attach servos to their respective pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Read potentiometer values
  potValue1 = analogRead(pot1Pin);
  potValue2 = analogRead(pot2Pin);
  potValue3 = analogRead(pot3Pin);
  potValue4 = analogRead(pot4Pin);

  // Map potentiometer values to servo angles (0-180 degrees)
  servoAngle1 = map(potValue1, 0, 1023, 0, 180);
  servoAngle2 = map(potValue2, 0, 1023, 0, 180);
  servoAngle3 = map(potValue3, 0, 1023, 0, 180);
  servoAngle4 = map(potValue4, 0, 1023, 0, 100);

  // Write angles to the servos and add different delays
  servo1.write(servoAngle1);
  delay(delay1);

  servo2.write(servoAngle2);
  delay(delay2);

  servo3.write(servoAngle3);
  delay(delay3);

  servo4.write(servoAngle4);
  delay(delay4);

  // Print values for debugging
  Serial.print("Servo 1 Angle: "); Serial.print(servoAngle1);
  Serial.print(" | Servo 2 Angle: "); Serial.print(servoAngle2);
  Serial.print(" | Servo 3 Angle: "); Serial.print(servoAngle3);
  Serial.print(" | Servo 4 Angle: "); Serial.println(servoAngle4);
}



