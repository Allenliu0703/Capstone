#ifndef WirelessCom_h
#define WirelessCom_h

#include "Arduino.h"

class WirelessCom
{
    public :
      WirelessCom (int baudRate);
      void wireless_Setup ( );
      void data_Transmit (String data );
      //void data_Receive ( );
      //void decode ( ) ;
    private :
      int _baudRate;
};
#endif