/*
  tankSteering.h - Library for driving tank RC models.
  Created by Hrastovc, March 4, 2016.
*/
#ifndef Tank_h
#define Tank_h

#include "Arduino.h"

class Tank
{
  public:
    Tank (int _chPulse_min1, int _chPulse_max1, int _chPulse_min2, int _chPulse_max2, byte _eps);
    Tank ();
    void setValues(byte i, int val);
    void calc();
    int leftMotor();
    int rightMotor();
  private:
    int backward_A;
    int backward_B;
    int PWMch[3];
    unsigned int PWMabs[3];
    unsigned int ch[3];
    int chPulse_min[3];
    int chPulse_max[3];
    byte eps;
    int val_left_motor;
    int val_right_motor;
};

#endif
