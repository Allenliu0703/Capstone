#ifndef Communication_Capdrone_h
#define Communication_Capdrone_h

#include "Arduino.h"

class WirelessCommunication
{
    public :
      WirelessCommunication (int baudRate);
      void wireless_Setup ( );
      void data_Transmit (int x, int y);
      String data_Convert (int x, int y);
      //void data_Receive ( );
      //void decode ( ) ;
    private :
      int _baudRate;
};
#endif