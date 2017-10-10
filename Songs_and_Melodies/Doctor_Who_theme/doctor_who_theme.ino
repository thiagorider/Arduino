// Adafruit Circuit Playground - Melody    
//   2017-01-29 Version 1.3  by Kristopher Ellis
//   Adapted from melody by Tom Igoe on arduino.cc
// Uses the CircuitPlayground library to easily use the full functionality of the board
 
#include <Adafruit_CircuitPlayground.h>
#include "pitches.h"
 
const int numNotes = 57;                     // number of notes we are playing
int melody[] = {                            // specific notes in the melody
 NOTE_B3, NOTE_C5, NOTE_B5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_B5, NOTE_G4, NOTE_B4, NOTE_D4, NOTE_C4, NOTE_B4, NOTE_C5, NOTE_B5, 0, NOTE_C5, NOTE_B5, NOTE_G4, NOTE_B5, NOTE_FS4, NOTE_G4, NOTE_A5, NOTE_B5, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G3, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_B5, NOTE_G4, NOTE_B5, NOTE_FS4, NOTE_G4, NOTE_A5, NOTE_B5, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G3, NOTE_B4, NOTE_A4 };
 
int noteDurations[] = {     // note durations: 4 = quarter note, 8 = eighth note, etc.:
  4, 1, 4, 4, 4, 1, 4, 4, 2, 2, 8, 1, 8, 3, 2, 4, 1, 4, 4, 3, 8, 9, 1, 4, 4, 5, 8, 8, 4, 4, 4, 8, 8, 3, 8, 1, 4, 1, 4, 4, 3, 8, 9, 1, 4, 4, 5, 8, 8, 4, 4, 4, 8, 8, 3, 8, 1 };
 
void setup() {
  CircuitPlayground.begin();  // initialize the CP library
}
 
void loop() {
  if(CircuitPlayground.rightButton()) {   // play when we press the right button
    for (int thisNote = 0; thisNote < numNotes; thisNote++) { // play notes of the melody
      
      int noteDuration = 1000 / noteDurations[thisNote];
      CircuitPlayground.playTone(melody[thisNote], noteDuration);
 
      
      int pauseBetweenNotes = 50;
      delay(pauseBetweenNotes);
    }
  }
}﻿
