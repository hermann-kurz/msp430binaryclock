// Patched (for using TIMER0) RTC library because we use MSP430G2452
// http://xv4y.radioclub.asia/2012/05/22/bibliotheque-rtc-pour-le-msp430/
#include <sRTCsec.h>
#include <legacymsp430.h>

// clean names for bits
#define minuteBits 6
#define M0 P1_5
#define M1 P1_4
#define M2 P1_3
#define M3 P1_2
#define M4 P1_1
#define M5 P1_0

#define hourBits 5
#define H0 P2_3
#define H1 P2_4
#define H2 P2_5
#define H3 P1_6
#define H4 P1_7

// Offset for startup
// TODO set offset manually
#define HO 16
#define MO 43

// Instantiate RTC
RealTimeClockSec myRTC;

// indirection level to simplify code
int hourPins[] = {
  H0, H1, H2, H3, H4
};

int minutePins[] = {
  M0, M1, M2, M3, M4, M5
};


byte currentMinute = 0;
byte currentHour = 0;

  
// the setup routine runs once when you press reset:
void setup() { 
// switch hourPins to output  
  for (int thisPin = 0; thisPin < hourBits; thisPin++)  {
    pinMode(hourPins[thisPin], OUTPUT);      
  }
//switch minutePins to output
  for (int thisPin = 0; thisPin < minuteBits; thisPin++)  {
    pinMode(minutePins[thisPin], OUTPUT);      
  };

}

void loop() {
// get current time from RTC

  currentMinute = myRTC.RTC_min;
  currentHour = myRTC.RTC_hr;
  
//display current time  
  writeMinute((currentMinute +MO) % 60);
  writeHour((currentHour +HO) % 24);
  sleep(100);
}

void writeMinute(byte minute){
  int bitMask = 1;
  for (int bitNo = 0; bitNo < minuteBits; bitNo ++) {
    if ((bitMask & minute) != 0){
      digitalWrite(minutePins[bitNo], HIGH);
    } else {
      digitalWrite(minutePins[bitNo], LOW);
    }
    bitMask = (bitMask << 1);
  }
};

void writeHour(byte hour){
  int bitMask = 1;
  for (int bitNo = 0; bitNo < hourBits; bitNo ++) {
    if ((bitMask & hour) != 0){
      digitalWrite(hourPins[bitNo], HIGH);
    } else {
      digitalWrite(hourPins[bitNo], LOW);
    }
    bitMask = (bitMask << 1);
  }
};


interrupt(TIMER0_A0_VECTOR) Tic_Tac(void) {
    myRTC.Inc_sec();            // Update secondes
};
