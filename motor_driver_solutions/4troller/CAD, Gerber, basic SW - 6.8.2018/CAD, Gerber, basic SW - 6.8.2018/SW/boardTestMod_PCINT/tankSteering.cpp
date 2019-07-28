/*
  tankSteering - Library for driving tank RC models.
  Created by Hrastovc, March 4, 2016.
*/
#include "Arduino.h"
#include "tankSteering.h"

Tank::Tank(int _chPulse_min1, int _chPulse_max1, int _chPulse_min2, int _chPulse_max2, byte _eps){
  chPulse_min[1] = _chPulse_min1;
  chPulse_max[1] = _chPulse_max1;
  chPulse_min[2] = _chPulse_min2;
  chPulse_max[2] = _chPulse_max2;
  eps = _eps;
}

Tank::Tank(){
  chPulse_min[1] = 1000;
  chPulse_max[1] = 2000;
  chPulse_min[2] = 1000;
  chPulse_max[2] = 2000;
  eps = 10;
}

void Tank::calc(){
  PWMch[1] = constrain(map(ch[1], chPulse_min[1], chPulse_max[1], -255, 255), -255, 255);
  PWMch[2] = constrain(map(ch[2], chPulse_min[2], chPulse_max[2], -255, 255), -255, 255);
  PWMabs[1] = abs(PWMch[1]);
  PWMabs[2] = abs(PWMch[2]);
  backward_A = constrain(((PWMabs[1]-PWMabs[2]-133) *2), 0, 255);
  backward_B = constrain(((PWMabs[1]-PWMabs[2]) *2), 0, 255);

  if(PWMch[1]>-eps && PWMch[1]<eps && PWMch[2]>-eps && PWMch[2]<eps){
    val_left_motor = 0;
    val_right_motor = 0;
  }
  if(PWMch[1]<eps && PWMch[1]>-eps && PWMch[2]>eps){
    val_left_motor = PWMabs[2];
    val_right_motor = PWMabs[2];
  }
  if(PWMch[1]<eps && PWMch[1]>-eps && PWMch[2]<-eps){
    val_left_motor = -PWMabs[2];
    val_right_motor = -PWMabs[2];
  }
  if(PWMch[1]>eps && PWMch[2]<eps && PWMch[2]>-eps){
    val_left_motor = -PWMabs[1];
    val_right_motor = PWMabs[1];
  }
  if(PWMch[1]<-eps && PWMch[2]<eps && PWMch[2]>-eps){
    val_left_motor = PWMabs[1];
    val_right_motor = -PWMabs[1];
  }
  if(PWMch[1]>eps && PWMch[2]>eps && PWMabs[1]>PWMabs[2]+eps){
    val_left_motor = -PWMabs[1]-PWMabs[2];
    val_right_motor = PWMabs[1];
  }
  if(PWMch[1]>eps && PWMch[2]>eps && PWMabs[1]+eps<PWMabs[2]){
    val_left_motor = PWMabs[2]-PWMabs[1];
    val_right_motor = PWMabs[2];
  }
  if(PWMch[1]>eps && PWMch[2]>eps && PWMabs[1]-PWMabs[2]<2*eps && PWMabs[2]-PWMabs[1]<2*eps){
    val_left_motor = 0;
    val_right_motor = PWMabs[2];
  }
  if(PWMch[1]<-eps && PWMch[2]>eps && PWMabs[1]>PWMabs[2]+eps){
    val_left_motor = PWMabs[1];
    val_right_motor = -PWMabs[1]-PWMabs[2];
  }
  if(PWMch[1]<-eps && PWMch[2]>eps && PWMabs[1]+eps<PWMabs[2]){
    val_left_motor = PWMabs[2];
    val_right_motor = PWMabs[2]-PWMabs[1];
  }
  if(PWMch[1]<-eps && PWMch[2]>eps && PWMabs[1]-PWMabs[2]<2*eps && PWMabs[2]-PWMabs[1]<2*eps){
    val_left_motor = PWMabs[1];
    val_right_motor = 0;
  }
  if(PWMch[1]>eps && PWMch[2]<-eps && PWMabs[1]>PWMabs[2]+eps && PWMabs[2]<85){
    val_left_motor = -backward_A;
    val_right_motor = backward_A;
  }
  if(PWMch[1]>eps && PWMch[2]<-eps && PWMabs[1]>PWMabs[2]+eps && PWMabs[2]>170){
    val_left_motor = backward_B;
    val_right_motor = -backward_B;
  }
  if(PWMch[1]>eps && PWMch[2]<-eps && PWMabs[1]+eps<PWMabs[2]){
    val_left_motor = -PWMabs[1];
    val_right_motor = -PWMabs[2];
  }
  if(PWMch[1]>eps && PWMch[2]<-eps && PWMabs[1]-PWMabs[2]<2*eps && PWMabs[2]-PWMabs[1]<2*eps){
    val_left_motor = 0;
    val_right_motor = -PWMabs[2];
  }
  if(PWMch[1]<-eps && PWMch[2]<-eps && PWMabs[1]>PWMabs[2]+eps && PWMabs[2]<85){
    val_left_motor = backward_A;
    val_right_motor = -backward_A;
  }
  if(PWMch[1]<-eps && PWMch[2]<-eps && PWMabs[1]>PWMabs[2]+eps && PWMabs[2]>170){
    val_left_motor = -backward_B;
    val_right_motor = backward_B;
  }
  if(PWMch[1]<-eps && PWMch[2]<-eps && PWMabs[1]+eps<PWMabs[2]){
    val_left_motor = -PWMabs[2];
    val_right_motor = -PWMabs[1];
  }
  if(PWMch[1]<-eps && PWMch[2]<-eps && PWMabs[1]-PWMabs[2]<2*eps && PWMabs[2]-PWMabs[1]<2*eps){
    val_left_motor = -PWMabs[2];
    val_right_motor = 0;
  }
}

void Tank::setValues(byte i, int val){
  i = constrain(i, 1, 2);
  ch[i] = constrain(val, 1000, 2000);
}

int Tank::leftMotor(){
  return val_left_motor;
}

int Tank::rightMotor(){
  return val_right_motor;
}
