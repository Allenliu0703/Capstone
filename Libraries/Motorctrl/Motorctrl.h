/*
  motorctrl.h - Library for control the chassis.
*/
#ifndef Motorctrl_h
#define Motorctrl_h

#include "Arduino.h"

class Motorctrl
{
  public:
    Motorctrl(void);
    void motor_Setup(void);
    void move_Forward(unsigned int x);
    void move_Backward(unsigned int x);
    void turn_Right(unsigned int x);
    void turn_Left(unsigned int x);
    void freeze();
  private:
    int M1A;
};

#endif