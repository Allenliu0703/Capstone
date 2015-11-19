#include <WirelessCom.h>


int count;
String locationData;
WirelessCom wiCom (9600);
void setup() {
  wiCom.wireless_Setup();
}

void loop() {
  count++;
  delay(1000);
  locationData = "X:" + (String)count +"\t"+ "Y:" + (String)(32767-count);
  wiCom.data_Transmit (locationData);
}


