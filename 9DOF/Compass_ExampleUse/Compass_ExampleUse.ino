#include <Compass_Capdrone.h>
#include <Wire.h>
Compass compass;

void setup() {
  compass.compass_setup();
  int x = compass.compass_calculateOrientation();
  Serial.println(x);
  
}
void loop() {

}
