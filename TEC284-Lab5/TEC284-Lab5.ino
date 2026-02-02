#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);

void setup() {
  AFMS.begin();
}

void loop() {
  forwards();
  delay(500);
  turnLeft();
  delay(500);
  turnRight();
  delay(500);
  backwards();
  delay(500);
}

void forwards(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(100);

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void backwards(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(100);

  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
}

void turnLeft(){
  rightMotor->setSpeed(0);
  leftMotor->setSpeed(100);

  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

void turnRight(){
  rightMotor->setSpeed(100);
  leftMotor->setSpeed(0);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}


