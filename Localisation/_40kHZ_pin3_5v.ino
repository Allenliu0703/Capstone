
const byte LED = 3;  // Timer 2 "B" output: OC2B

const long frequency = 40000L;  // Hz

void setup() 
{
  pinMode (LED, OUTPUT);

  TCCR2A = _BV (WGM20) | _BV (WGM21) | _BV (COM2B1); // fast PWM, clear OC2B on compare
  TCCR2B = _BV (WGM22) | _BV (CS21);         // fast PWM, prescaler of 8
  OCR2A =  ((F_CPU / 8) / frequency) - 1;    // zero relative  
  OCR2B = ((OCR2A + 1) / 2) - 1;             // 50% duty cycle
  }  // end of setup

void loop() { }
