#include <DigiSparkB.h>
#include <UsbMidiLib.h>
#include <Switch.h>

//Variables
// the format of the message to send Via serial 

void setup() {
  pinMode(DigiSparkB::LED, OUTPUT);
  pinMode(DigiSparkB::PWM1, INPUT);
  pinMode(DigiSparkB::PWM2, INPUT);
  Serial.begin(115200);

  DigiSparkB::Utils::blinkLed(3);
}

void loop() {

  UsbMidi::Message midiMsg1;  // MIDI message for Switch 1
  UsbMidi::Message midiMsg2;  //MIDI message for Swtich 2
  static SwitchMemory* sw1 = new SwitchMemory(DigiSparkB::PWM1, LOW);
  static SwitchMemory* sw2 = new SwitchMemory(DigiSparkB::PWM2, LOW);
  
  if (sw1->WasToggled()) {
    midiMsg1.msg.command = UsbMidi::CTRLCHG;
    midiMsg1.msg.channel = 1;
    midiMsg1.msg.data2   = 1;
    midiMsg1.msg.data3   = 0; /* Velocity */

    /* Send note on */
    UsbMidi::SendMessage(midiMsg1);                           
    DigiSparkB::Utils::blinkLed(2);
  }

  if (sw2->WasToggled()) {
    midiMsg2.msg.command = UsbMidi::CTRLCHG;
    midiMsg2.msg.channel = 2;
    midiMsg2.msg.data2   = 2;
    midiMsg2.msg.data3   = 0; /* Velocity */

    /* Send note on */
    UsbMidi::SendMessage(midiMsg2);                            
    DigiSparkB::Utils::blinkLed(2);
  } 
}



