#include "GyroAcc_Capdrone.h"
#include <Wire.h>
GyroAcc mygyro = GyroAcc();
void setup() {
  mygyro.gyroacc_setup();

}

void loop() {
  float degree = mygyro.gyroacc_getAngle();
  Serial.println(degree);
  delay(60);
}
