/*
  motorctrl.h - Library for control the chassis.
*/
#ifndef Motor_Capdrone_h
#define Motor_Capdrone_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(void);
    void motor_Setup(void);
    void move_Forward(unsigned int x);
    void move_Backward(unsigned int x);
    void turn_Right(unsigned int x);
    void turn_Left(unsigned int x);
    void freeze();

};

#endif