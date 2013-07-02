#ifndef Morse_h
#define Morse_h
#include <Arduino.h>

class Morse
{
public:
  static void translate(const char* msg);

private:
  static const int dotLength = 100;
  static const int dashLength = dotLength * 3;
  static const int spaceLength = dotLength * 7;
  static const byte chars[];
  static void code2Light(byte code);
  static void Error(const char c);
  static void dot();
  static void dash(); 
};

#endif // Morse_h
