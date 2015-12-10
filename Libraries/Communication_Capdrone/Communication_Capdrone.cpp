#include "Arduino.h"
#include "Communication_Capdrone.h"

WirelessCommunication :: WirelessCommunication (int baudRate){
	_baudRate = baudRate;
}


void WirelessCommunication :: wireless_Setup ( ){
	Serial.begin(_baudRate);
}

String WirelessCommunication :: data_Convert(int x, int y){
	String temp = "X:" + (String)x +"\t"+ "Y:" + (String)y;
	return temp;
}

void WirelessCommunication :: data_Transmit ( int x, int y ){
	Serial.println(data_Convert(x,y));
	delay(50);
}
