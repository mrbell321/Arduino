#include "Arduino.h"
#include "Morse.h"

const byte Morse::chars[] = { B01000010, //A	".-"
                       B10000100, //B	"-..."
		       B10100100, //C	"-.-."
		       B10000011, //D	"-.."
		       B00000001, //E	"."
		       B00100100, //F	"..-."
		       B11000011, //G	"--."
		       B00000100, //H	"...."
		       B00000010, //I	".."
		       B01110100, //J	".---"
		       B10100011, //K	"-.-"
		       B01000100, //L	".-.."
		       B11000010, //M	"--"
		       B10000010, //N	"-."
		       B11100011, //O	"---"
		       B01100100, //P	".--."
		       B11010100, //Q	"--.-"
		       B01000011, //R	".-."
		       B00000011, //S	"..."
		       B10000010, //T	"-"
		       B00100011, //U	"..-"
		       B00010100, //V	"...-"
		       B01100011, //W	".--"
		       B10010100, //X	"-..-"
		       B10110100, //Y	"-.--"
		       B11000100, //Z   "--.."
                     };

void Morse::translate(const char* msg) {
  const char first = 'A';
  const char last = 'Z';
  const byte dist = last - first;

  for(int i = 0; msg[i] != '\0'; i++) {
    char c = toupper(msg[i]);
    byte idx = c - first;
    if( idx >= 0 && idx <= dist ) {
      code2Light(chars[idx]);
    }
    else if( c == ' ' ) {
      delay(spaceLength);
    }
  }
}

void Morse::code2Light(byte code) {
  static const byte lenMask = B00001111;
  static const byte codeMask = B10000000;
  byte len = (lenMask & code);

  for(int i=0; i < len; i++) {
    byte bit = codeMask & code;
    code <<= 1;
    if( bit == codeMask ) {
       dash();
    } else {
       dot();
    }
  }
}

void Morse::dot() {
  digitalWrite(1, HIGH);
  delay(dotLength);
  digitalWrite(1, LOW);
  delay(dashLength);
}

void Morse::dash() {
  digitalWrite(1, HIGH);
  delay(dashLength);
  digitalWrite(1, LOW);
  delay(dashLength);
}

