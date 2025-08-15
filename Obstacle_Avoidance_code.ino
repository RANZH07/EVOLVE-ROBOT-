// Motor pins
int motor1pin1 = 9;
int motor1pin2 = 10;
int motor2pin3 = 5;
int motor2pin4 = 6;

// Ultrasonic sensor pins
int trigPin = 11;
int echoPin = 12;

// Variables
long duration;
int distance;

void setup() {
  // Set motor pins as outputs
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  pinMode(motor2pin4, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Begin Serial communication
  Serial.begin(9600);
  Serial.println("Obstacle Avoiding Robot Started");
}

void loop() {
  // Get distance from ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    // Obstacle detected: reverse and turn
    stopMotors();
    delay(300);
    reverseMotors();
    delay(600);
    turnLeft();
    delay(500);
  } else {
    // Clear: move forward
    moveForward();
  }

  delay(100);
}

// Motor control functions
void moveForward() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
}

void stopMotors() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
}

void reverseMotors() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, HIGH);
}

void turnLeft() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
}
