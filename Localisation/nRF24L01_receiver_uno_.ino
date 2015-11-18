/* 
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
   
/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe [4] = {0xE8E8F0F0E1LL,0xF0F0F0F0B4LL,0xF0F0F0F0A2LL,0xF0F0F0F0A1LL}; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
short data;
const long frequency = 40000L;  // Hz
int previous = 0;
void setup()   /****** SETUP: RUNS ONCE ******/
{
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);

  Serial.begin(9600);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe[1]);
  radio.startListening();;
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      // Fetch the data payload
      done = radio.read( &data, sizeof(data)  );
      
      Serial.print(" DATA = ");
      Serial.println(data);
      if (data == 1& previous == 0){
        Serial.println("1st beacon trasmitting");
        digitalWrite(7,HIGH);
        previous = 1;
        startTransducer();
        //delay(50);
        delay(1001);
        stopTransducer();
      }else if (data == 3& previous == 1){
        digitalWrite(7,LOW);
        break;
      }
      else{
        previous = 0;
        digitalWrite(7,LOW);
      }
      
    }
    
  }
  else
  {    
      Serial.println("No radio available");
  }

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/
void startTransducer()
{
  TCCR2A = _BV (WGM20) | _BV (WGM21) | _BV (COM2B1); // fast PWM, clear OC2B on compare
  TCCR2B = _BV (WGM22) | _BV (CS21);         // fast PWM, prescaler of 8
  OCR2A =  ((F_CPU / 8) / frequency) - 1;    // zero relative  
  OCR2B = ((OCR2A + 1) / 2) - 1;    
}
void stopTransducer()
{
  TCCR2A = 0;
  TCCR2B = 0;

}
//NONE
//*********( THE END )***********


