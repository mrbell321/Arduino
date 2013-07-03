#ifndef DigiSparkB_h
#define DigiSparkB_h
#include <Arduino.h>

namespace DigiSparkB {
  typedef enum {
    LED = 1,
    PWM1 = 0,
    I2C_SCK = 2,
    AnalogX1 = 2,
    AnalogIn1 = 3,
    USBPos = 3,
    PWM2 = 4,
    AnalogX2 = 4,
    AnalogIn2 = 5
  } ePins;
 

  namespace Utils {
    void blinkPin(byte num, ePins pin) {  // Basic blink function
      for (byte i=0;i<num;i++) {
        digitalWrite(pin, HIGH);
        delay(100);
        digitalWrite(pin, LOW);
        delay(100);
      }
    }
    void blinkLed(byte num) {  // Basic blink function
      blinkPin(num, LED);
    }
    void LedOff() {
      digitalWrite(LED, LOW);
    }
    void LedOn(int ms) {
      digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
      if( ms > 0 ) {
        delay(ms);               // wait for a second
        LedOff();   // turn the LED on (HIGH is the voltage level)
      }
    }
  }
}

#endif // DigiSparkB_h

