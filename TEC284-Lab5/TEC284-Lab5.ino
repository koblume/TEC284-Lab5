#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);

long duration;
long distance;
//long leftCount=0;

void setup() {
  AFMS.begin();
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  //forwards();
  //delay(500);
  //turnLeft();
  //delay(500);
  //turnRight();
  //delay(500);
  //backwards();
  //delay(500);

  autoDriver();
}

void forwards(){
  rightMotor->setSpeed(255);
  leftMotor->setSpeed(255);

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void backwards(){
  rightMotor->setSpeed(255);
  leftMotor->setSpeed(255);
  
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
}

void turnLeft(){
  rightMotor->setSpeed(120);
  leftMotor->setSpeed(255);

  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

void turnRight(){
  rightMotor->setSpeed(255);
  leftMotor->setSpeed(152);

  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

long distanceTest(){
  digitalWrite(7,LOW);
  //delayMicroseconds(2);
  digitalWrite(7, HIGH);
  //delayMicroseconds(10);
  digitalWrite(7, LOW);
  duration = pulseIn(8, HIGH);
  distance = duration * 0.0133 /2;
  Serial.print("Distance = ");
  Serial.println(distance);
  return distance;
  
}

void autoDriver(){
  distanceTest();
  if(distance >= 5){
    backwards();
  }
  else if(distance<5){
    forwards();
    delay(50);
    turnRight();
    delay(25);
    //delay(10);
  }
  else{
    forwards();
    delay(1000);
    turnRight();
    delay(50);
    //delay(10);
    
  }
}

