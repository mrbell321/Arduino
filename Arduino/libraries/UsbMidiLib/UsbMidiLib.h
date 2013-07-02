/*
 UsbMidiLib.h - Library header for communicating MIDI over USB
 Created by Tyler J. Bell, Sunday, June 30, 2013
*/
  
#ifndef UsbMidiLib_h
#define UsbMidiLib_h
  
#include "Arduino.h"
  
class UsbMidi {
public:
  enum CN {
    ZERO = 0x0,
    ONE = 0x1,
    TWO = 0x2,
    THREE = 0x3,
    SIXTEEN = 0xF
  };
  
  enum CIN {
    MiscFnCdReserved = 0x0, // Size: 1,2,3 
    CableEventReserved = 0x1, // Size: 1,2,3
    TwoByteSysCommonMsg = 0x2, // Size: 2
    ThreeByteSysCommonMsg = 0x3, // Size: 3
    SysExStart = 0x4, // Size: 3
    SingleByteSysCommonMsg = 0x5, // Size: 1
    SysExEndsTwoBytes = 0x6, // Size: 2
    SysExEndsThreeBytes = 0x7, // Size: 3
    NoteOff = 0x8, // Size: 3
    NoteOn = 0x9, // Size: 3
    PolyKeyPress = 0xA, // Size: 3
    ControlChange = 0xB, // Size: 3
    ProgramChange = 0xC, // Size: 2
    ChannelPressure = 0xD, // Size: 2
    PitchBendChange = 0xE, // Size: 3
    SingleByte = 0xF // Size: 1,2,3
  };
  
  union EventPacket {
      byte CnCin;
      byte Midi_0;
      byte Midi_1;
      byte Midi_2;
  };
  
  enum Commands {
    CTRLCHG = 0xB0,
    NOTEON = 0x90,
    NOTEOFF = 0x80
  };
  
  typedef union {
    struct {
      uint8_t command;
      uint8_t channel;
      uint8_t data2;
      uint8_t data3;
    } msg;
    uint8_t raw[4];
  } Message;

  static void SendMessage(Message msg) {
    Serial.write(msg.raw, sizeof(msg));
  }
};
#endif //UsbMidiLib_h
