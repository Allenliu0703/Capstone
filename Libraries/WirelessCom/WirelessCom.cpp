#include "Arduino.h"
#include "wirelessCom.h"

WirelessCom :: WirelessCom (int baudRate)
{
  _baudRate = baudRate;
}


void WirelessCom :: wireless_Setup ( )
{
  Serial.begin(_baudRate);
}

void WirelessCom :: data_Transmit ( String data )
{
  Serial.println(data);
  delay(50);
}
