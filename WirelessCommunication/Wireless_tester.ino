#include <WirelessCom.h>


int count;
String locationData;
WirelessCom wiCom (9600);
void setup() {
  wiCom.wireless_Setup();
}

void loop() {
  count++;
  locationData = "L:" + (String)count;
  wiCom.data_Transmit (locationData);
}


