#include <MIDI.h>

#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define BUTTON_3_PIN 4
#define BUTTON_4_PIN 5
#define BUTTON_5_PIN 6
#define BUTTON_6_PIN 7
#define BUTTON_7_PIN 8
#define BUTTON_8_PIN 9

#define PROGRAM_1 0x01
#define PROGRAM_2 0x02
#define PROGRAM_3 0x04
#define PROGRAM_4 0x08
#define EFFECT_MODULATION 0x10
#define EFFECT_DELAY      0x20
#define EFFECT_REVERB     0x40
#define EFFECT_BOOST      0x80

#define PROGRAM_BUTTONS 4
#define EFFECT_BUTTONS 4


int[] BUTTON_PINS = ( BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN, BUTTON_4_PIN, 
                      BUTTON_5_PIN, BUTTON_6_PIN, BUTTON_7_PIN, BUTTON_8_PIN };
button1Pressed(){
  
}

checkButtons(){
  if (digitalRead(BUTTON_1_PIN) == LOW){
    button1Pressed();
  }
}
void setup() {
  // start midi
  MIDI.begin(MIDI_CHANNEL_OFF);

  // set button pins to known state (HIGH)
  for (int i = 0; i < PROGRAM_BUTTONS + EFFECT_BUTTONS; i++){
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  // set controller to known state
  button1Pressed();
  
}

void loop() {
  checkButtons();
}
