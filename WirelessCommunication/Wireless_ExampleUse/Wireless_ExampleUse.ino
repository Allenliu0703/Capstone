#include <Communication_Capdrone.h>
int count;
WirelessCommunication wiCom (9600);
void setup() {
  wiCom.wireless_Setup();
}

void loop() {
  count++;
  delay(1000);
  wiCom.data_Transmit ( count, 32767-count );

}


