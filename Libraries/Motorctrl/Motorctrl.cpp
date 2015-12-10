/*
  Motorctrl.cpp.cpp - Library for control chassis
*/

#include "Arduino.h"
#include "Motorctrl.h"




Motorctrl :: Motorctrl() {
    #define M1A 22
    #define M1B 23
    #define M2A 24
    #define M2B 25
    #define M3A 26
    #define M3B 27
    #define M4A 28
    #define M4B 29
    #define ENA 30
    #define ENB 31
    #define ENC 32
    #define END 33
}



void Motorctrl :: motor_Setup(){
    pinMode(M1A, OUTPUT);
    pinMode(M1B, OUTPUT);
    pinMode(M2A, OUTPUT);
    pinMode(M2B, OUTPUT);
    pinMode(M3A, OUTPUT);
    pinMode(M3B, OUTPUT);
    pinMode(M4A, OUTPUT);
    pinMode(M4B, OUTPUT);
}
void Motorctrl :: move_Forward(unsigned int x){
  if (x > 255)
   x=255;
   digitalWrite(M1A,HIGH);
   digitalWrite(M1B,LOW);
   analogWrite(ENA,x);
   digitalWrite(M2A,HIGH);
   digitalWrite(M2B,LOW);
   analogWrite(ENB,x);
   digitalWrite(M3A,HIGH);
   digitalWrite(M3B,LOW);
   analogWrite(ENC,x);
   digitalWrite(M4A,HIGH);
   digitalWrite(M4B,LOW);
   analogWrite(END,x);
}
void Motorctrl :: move_Backward(unsigned int x){
  if (x > 255)
    x=255;
   digitalWrite(M1A,LOW);
   digitalWrite(M1B,HIGH);
   analogWrite(ENA,x);
   digitalWrite(M2A,LOW);
   digitalWrite(M2B,HIGH);
   analogWrite(ENB,x);
   digitalWrite(M3A,LOW);
   digitalWrite(M3B,HIGH);
   analogWrite(ENC,x);
   digitalWrite(M4A,LOW);
   digitalWrite(M4B,HIGH);
   analogWrite(END,x);
}

void Motorctrl :: turn_Right(unsigned int x){
  if (x > 255)
    x=255;
   digitalWrite(M1A,HIGH);
   digitalWrite(M1B,LOW);
   analogWrite(ENA,x);
   digitalWrite(M2A,HIGH);
   digitalWrite(M2B,LOW);
   analogWrite(ENB,x);
   digitalWrite(M3A,LOW);
   digitalWrite(M3B,HIGH);
   analogWrite(ENC,x);
   digitalWrite(M4A,LOW);
   digitalWrite(M4B,HIGH);
   analogWrite(END,x);
}

void Motorctrl :: turn_Left(unsigned int x){
  if (x > 255)
    x=255;
   digitalWrite(M1A,LOW);
   digitalWrite(M1B,HIGH);
   analogWrite(ENA,x);
   digitalWrite(M2A,LOW);
   digitalWrite(M2B,HIGH);
   analogWrite(ENB,x);
   digitalWrite(M3A,HIGH);
   digitalWrite(M3B,LOW);
   analogWrite(ENC,x);
   digitalWrite(M4A,HIGH);
   digitalWrite(M4B,LOW);
   analogWrite(END,x);
}

void Motorctrl :: freeze(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  analogWrite(ENC,0);
  analogWrite(END,0);
}