#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


/*-----( Import needed libraries )-----*/
#include <SPI.h>

/*-----( Declare Constants and Pin Numbers )-----*/

#define CE_PIN   9
#define CSN_PIN 10


// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe [4] = {0xE8E8F0F0E1LL,0xF0F0F0F0B4LL,0xF0F0F0F0A2LL,0xF0F0F0F0A1LL}; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
short data;  // 2 element array holding Joystick readings
void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe[1]);
  delay(2000);
  
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  for (int i =0; i<=10;i++){
    data = 0;
    radio.write( &data, 1);
  }
  //delay(50);
  delay(1000);
  for (int i =0; i<=10;i++){
    data = 1;
    radio.write( &data, sizeof(data));
  }
  //delay(50);
  delay(1000);
  for (int i =0; i<=10;i++){
    data = 2; 
    radio.write( &data, sizeof(data));
  }
  //delay(50);
  delay(1000);
  for (int i =0; i<=10;i++){
    data =3;
    radio.write( &data, sizeof(data));
  }
  //delay(50);
  delay(1000);
  for (int i =0; i<=10;i++){
    data = 4;
    radio.write( &data, sizeof(data));
  }
  //delay(50);
  delay(1000);


  
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/



