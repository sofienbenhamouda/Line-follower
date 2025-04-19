#include <DualMAX14870MotorShield.h>
#include <QTRSensors.h>

// PID constants for line tracking
float Kp = 0.035;
float Kd = 0.003;

// Sensor configuration
const int NUM_SENSORS = 16;
const int TIMEOUT = 2500;
const int NUM_SENSORS1 = 6;
const int TIMEOUT1 = 2500;

// Speed settings for different track sections
float MaxSpeed = 450;  // Maximum speed for straight sections
float MaxSpeed1 = 120; // Reduced maximum speed for turns
float BaseSpeed = 200; // Default speed
float MinSpeed1 = 50;  // Minimum speed to avoid stalling
float MinSpeed = -400; // Minimum speed for reverse correction
float IntermediateSpeed = 400; // Intermediate speed limit

// Timing periods for speed adjustments (in milliseconds)
long period = 3000;   // Time to increase speed after start
long periodx = 1900;  // First speed adjustment for zone 1
long period2 = 10800; // Transition to zone 2 after 10.8 seconds
long period3 = 20000; // Transition to zone 3 after 20 seconds

#define LED 13  // LED for status indication
#define START_BUTTON 53  // Start button for competition

unsigned long startMillis;
unsigned long currentMillis;

// Sensor arrays
QTRSensorsRC qtrrc((unsigned char[]){
                     A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, 16, 17 },
                   NUM_SENSORS, TIMEOUT, QTR_NO_EMITTER_PIN);

QTRSensorsRC qtrrc1((unsigned char[]){
                      A7, A8, A9, A10, A11, A12 },
                    NUM_SENSORS1, TIMEOUT1, QTR_NO_EMITTER_PIN);

unsigned int sensors[16];
unsigned int sensors1[6];

// Motor shield
DualMAX14870MotorShield motors;

// State machine for zones
enum RobotState { ZONE1, ZONE2, ZONE3 };
RobotState state = ZONE1;

void setup() {
  Serial.begin(9600);

  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  // Calibrate sensors
  for (int i = 0; i < 140; i++) {
    qtrrc.calibrate();
    qtrrc1.calibrate();
    delay(20);
  }

  // Wait for start button press
  while (!digitalRead(START_BUTTON)) {
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
  startMillis = millis();
}

void loop() {
  currentMillis = millis();
  int position, error, lastError;

  if (state == ZONE1) {
    position = qtrrc.readLine(sensors);
    Serial.print("Zone 1 Position: ");
    Serial.println(position);

    // Check if line is lost
    if (position == 0 && sensors[0] == 0 && sensors[15] == 0) {
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      Serial.println("Error: Line lost!");
      while (true); // Stop the robot
    }

    error = -position + 7500;
    int motorSpeed = Kp * error + Kd * (error - lastError);
    lastError = error;

    int rightMotorSpeed = BaseSpeed + motorSpeed;
    int leftMotorSpeed = BaseSpeed - motorSpeed;
    setMotors(rightMotorSpeed, leftMotorSpeed);

    if (currentMillis - startMillis >= periodx) {
      digitalWrite(LED, HIGH);
      MaxSpeed = 500; MaxSpeed1 = 350; BaseSpeed = 350; MinSpeed1 = 0; MinSpeed = -250;
    }
    if (currentMillis - startMillis >= period) {
      digitalWrite(LED, HIGH);
      MaxSpeed = 500; MaxSpeed1 = 350; BaseSpeed = 350; MinSpeed1 = 0; MinSpeed = -250;
    }
    if (currentMillis - startMillis >= period2) {
      digitalWrite(LED, HIGH);
      MaxSpeed = 450; MaxSpeed1 = 120; BaseSpeed = 350; MinSpeed1 = 50; MinSpeed = -400;
      state = ZONE2;
    }
  }
  else if (state == ZONE2) {
    position = qtrrc1.readLine(sensors1);
    Serial.print("Zone 2 Position: ");
    Serial.println(position);

    if (position == 0 && sensors1[0] == 0 && sensors1[5] == 0) {
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      Serial.println("Error: Line lost!");
      while (true);
    }

    error = -position + 2500;
    int motorSpeed = Kp * error + Kd * (error - lastError);
    lastError = error;

    int rightMotorSpeed = BaseSpeed + motorSpeed;
    int leftMotorSpeed = BaseSpeed - motorSpeed;
    setMotors(rightMotorSpeed, leftMotorSpeed);

    if (currentMillis - startMillis >= period3) {
      digitalWrite(LED, LOW);
      MaxSpeed = 500; MaxSpeed1 = 170; BaseSpeed = 250; MinSpeed1 = 100; MinSpeed = -320;
      state = ZONE3;
    }
  }
  else if (state == ZONE3) {
    position = qtrrc.readLine(sensors);
    Serial.print("Zone 3 Position: ");
    Serial.println(position);

    if (position == 0 && sensors[0] == 0 && sensors[15] == 0) {
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      Serial.println("Error: Line lost!");
      while (true);
    }

    error = -position + 7500;
    int motorSpeed = Kp * error + Kd * (error - lastError);
    lastError = error;

    int rightMotorSpeed = BaseSpeed + motorSpeed;
    int leftMotorSpeed = BaseSpeed - motorSpeed;
    setMotors(rightMotorSpeed, leftMotorSpeed);
  }
}

void setMotors(int leftMotorSpeed, int rightMotorSpeed) {
  if (leftMotorSpeed > MaxSpeed) leftMotorSpeed = MaxSpeed1;
  if (leftMotorSpeed > IntermediateSpeed && leftMotorSpeed < MaxSpeed) leftMotorSpeed = IntermediateSpeed;
  if (rightMotorSpeed > MaxSpeed) rightMotorSpeed = MaxSpeed1;
  if (rightMotorSpeed > IntermediateSpeed && rightMotorSpeed < MaxSpeed) rightMotorSpeed = IntermediateSpeed;
  if (leftMotorSpeed < MinSpeed1) leftMotorSpeed = MinSpeed;
  if (rightMotorSpeed < MinSpeed1) rightMotorSpeed = MinSpeed;
  motors.setM1Speed(rightMotorSpeed);
  motors.setM2Speed(leftMotorSpeed);
}