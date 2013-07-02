#include <Morse.h>

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A
}

// the loop routine runs over and over again forever:
void loop() {
 Morse::translate("Morse code is neat");
 delay(5000);
}

