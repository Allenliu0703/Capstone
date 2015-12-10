/*
  Compass_Capdrone.cpp
*/

#include "Arduino.h"
#include "Compass_Capdrone.h"
#include <Wire.h>

Compass :: Compass() {
    #define address 0x1E
    #define MagnetcDeclination 4.43
    #define offsetX 55
    #define offsetY -130
    #define offsetZ 0
}



void Compass :: compass_setup(){
    Serial.begin(9600);
    Wire.begin();
 
    //Put the HMC5883 IC into the correct operating mode
    Wire.beginTransmission(address); //open communication with HMC5883r
    Wire.write(0x00); //select configuration register A
    Wire.write(0x70); //0111 0000b configuration
    Wire.endTransmission();
     
    Wire.beginTransmission(address);
    Wire.write(0x02); //select mode register
    Wire.write(0x00); //set continuous measurement mode:0x00,single-measurement mode:0x01
    Wire.endTransmission();
}

int Compass :: compass_calculateOrientation(){
    int16_t x,y,z;
    int orientation;
    compass_getRawData(&x,&y,&z);
    /* Print values for debugging */
    // Serial.print("x: ");
    // Serial.print(x);
    // Serial.print("  y: ");
    // Serial.print(y);
    // Serial.print("  z: ");
    // Serial.print(z);
    orientation = compass_calculateHeading(&x,&y,&z);
    // Serial.print(" angle(x,y): ");
    // Serial.println(orientation);
    return orientation;
}

    
void Compass :: compass_getRawData(int16_t* x ,int16_t* y,int16_t* z){
    //Tell the HMC5883L where to begin reading data
    Wire.beginTransmission(address);
    Wire.write(0x03); //select register 3, X MSB register
    Wire.endTransmission();
    //Read data from each axis, 2 registers per axis
    Wire.requestFrom(address, 6);
    if(6<=Wire.available()){
        *x = Wire.read()<<8; //X msb
        *x |= Wire.read(); //X lsb
        *z = Wire.read()<<8; //Z msb
        *z |= Wire.read(); //Z lsb
        *y = Wire.read()<<8; //Y msb
        *y |= Wire.read(); //Y lsb
    }
}

int Compass :: compass_calculateHeading(int16_t* x ,int16_t* y,int16_t* z){
    float headingRadians = atan2((double)((*y)-offsetY),(double)((*x)-offsetX));
    // Correct for when signs are reversed.
    if(headingRadians < 0)
        headingRadians += 2*PI;

    int16_t headingDegrees = headingRadians * 180/M_PI;
    headingDegrees += MagnetcDeclination; //the magnetc-declination angle 

    // Check for wrap due to addition of declination.
    if(headingDegrees > 360)
        headingDegrees -= 360;

    return headingDegrees;
}



