#include <Motor_Capdrone.h>
Motor motor;
void setup() {
  motor.motor_Setup();

}

void loop() {
  motor.move_Forward(256);

}
