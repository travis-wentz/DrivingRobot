/*
Travis Wentz
 Driving Robot version 2.0 includes AFMotor library for funduino motor controller
 */

#include <AFMotor.h>

int rightButtonState = 0;
int leftButtonState = 0;
// attach right button to pin 2
int rightButton = 2;
// attach left button to pin 13
int leftButton = 13;

//setting each motor
AF_DCMotor rightFront(1);
AF_DCMotor leftFront(2);
AF_DCMotor leftBack(3);
AF_DCMotor rightBack(4);

void setup() {
  //buttons will give input
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);

  // Turn on all 4 motors
  rightFront.setSpeed(500);
  rightFront.run(RELEASE);
  leftFront.setSpeed(500);
  leftFront.run(RELEASE);
  leftBack.setSpeed(500);
  leftBack.run(RELEASE);
  rightBack.setSpeed(500);
  rightBack.run(RELEASE);
}


void loop() {
  //delay(100000);
  rightFront.run(FORWARD);
  leftFront.run(FORWARD);
  leftBack.run(FORWARD);
  rightBack.run(FORWARD);

  //if right button is bumped, reverse, turn left and go forward
  //if left button is bumped, reverse, turn right and go forward
  rightButtonState = digitalRead(rightButton);
  leftButtonState = digitalRead(leftButton);
  if(rightButtonState == HIGH){
    rightFront.run(BACKWARD);
    leftFront.run(BACKWARD);
    leftBack.run(BACKWARD);
    rightBack.run(BACKWARD);
    delay(1000);
    rightFront.run(FORWARD);
    rightBack.run(FORWARD);
    leftFront.run(BACKWARD);
    leftBack.run(BACKWARD);
    delay(1000);
  } 
  else if(leftButtonState == HIGH){
    rightFront.run(BACKWARD);
    leftFront.run(BACKWARD);
    leftBack.run(BACKWARD);
    rightBack.run(BACKWARD);
    delay(1000);
    rightFront.run(BACKWARD);
    rightBack.run(BACKWARD);
    leftFront.run(FORWARD);
    leftBack.run(FORWARD);
    delay(1000);
  }
}




