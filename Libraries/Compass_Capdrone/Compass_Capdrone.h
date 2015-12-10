/*
  Compass_Capdrone.h 
*/
#ifndef Compass_Capdrone_h
#define Compass_Capdrone_h

#include "Arduino.h"
#include <Wire.h>

class Compass
{
  public:
    Compass(void);
    void compass_setup (void);
    void compass_getRawData(int16_t* x ,int16_t* y,int16_t* z);
    int compass_calculateHeading(int16_t* x ,int16_t* y,int16_t* z);
    int compass_calculateOrientation(void);
};

#endif