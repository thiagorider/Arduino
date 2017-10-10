/*MISSION IMPOSSIBLE

Done by: André Thomas
24.01.2014

Taken out from a poker program I have written last year
Idea for the 2-Tone same Speaker didn´t came from me.

"Mission Impossible" theme made for Arduino by me, note by note. 
------------------------------------------------------------------
For compiling you need Tone() from here
http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation  

Go into the Tone Directory and change tone.cpp header (includes) to this:


#include <avr/interrupt.h>
//#include <avr/pgmspace.h>
//#include <wiring.h>
#include <Arduino.h>


so it will compile.
------------------------------------------------------------------


*/


#include <Tone.h>
#include "frequenzen.h"
#include <avr/pgmspace.h>

#define OUT1 7
#define OUT2 8

//Sound Vars
Tone notePlayer[2];
unsigned int Counts[] = { 0, 0};
unsigned long stopTimeNote1 = 0;
unsigned long stopTimeNote2 = 0;
int value;
int value2;
int dur;
int dur2;

//Mission Impossible // Game Finale Melodie
int mimp[]  PROGMEM = {
  NOTE_DS5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,
  NOTE_D5,NOTE_DS5,NOTE_D5,NOTE_DS5,
  NOTE_D5,NOTE_DS5,NOTE_F5,NOTE_FS5,NOTE_G5, // Upswing 5
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0,NOTE_G2,0,NOTE_AS2,0,NOTE_C3,0,
  NOTE_G2,0,NOTE_G2,0,NOTE_F2,0,NOTE_FS2,0,
  
  NOTE_G2,0
  
  ,-1
};

int mimpDur [] PROGMEM = {

  50,50,50,50,50,50,50,50,50,50,
  50,50,50,50,50,50,50,50,50,50,
  50,50,50,50,50,50,50,50,50,50,
  50,50,50,50,
  50,50,50,50,50,50,
  
  200,400,200,400,200,200,200,200,              //2000  
  200,400,200,400,200,200,200,200,  
  
  200,400,200,400,200,200,200,200,              //2000 
  200,400,200,400,200,200,200,200,
  
  200,400,200,400,200,200,200,200,              
  200,400,200,400,200,200,200,200,  
  
  200,400,200,400,200,200,200,200,              
  200,400,200,400,200,200,200,200,
  
  200,400,200,400,200,200,200,200,           
  200,400,200,400,200,200,200,200,  
  
  200,400,200,400,200,200,200,200,       
  200,400,200,400,200,200,200,200,
  
  200,400,200,400,200,200,200,200,          
  200,400,200,400,200,200,200,200,  
  
  200,400,200,400,200,200,200,200,              
  200,400,200,400,200,200,200,200,
  
  400,-1
};

int mimp2 [] PROGMEM  = {
  NOTE_G3,
  
  NOTE_G3,0,NOTE_G3,0,NOTE_AS3,0,NOTE_C4,0,
  NOTE_G3,0,NOTE_G3,0,NOTE_F3,0,NOTE_FS3,0,
  
  NOTE_G3,0,NOTE_G3,0,NOTE_AS3,0,NOTE_C4,0,
  NOTE_G3,0,NOTE_G3,0,NOTE_F3,0,NOTE_FS3,0,
 
  NOTE_AS5,0,NOTE_G5,0,NOTE_D5,0,   
  NOTE_AS5,0,NOTE_G5,0,NOTE_CS5,0,
  NOTE_AS5,0,NOTE_G5,0,NOTE_C5,0,   
  NOTE_AS4,0,NOTE_C5,0,
 
  NOTE_AS4,NOTE_G4,NOTE_FS5,0,   
  NOTE_AS4,NOTE_G4,NOTE_F5,0,
  NOTE_AS4,NOTE_G4,NOTE_E5,0,    
  NOTE_DS5,NOTE_D5,0,
  
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0,    
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_CS5,NOTE_F5,NOTE_AS5,NOTE_CS5,NOTE_F5,NOTE_AS5,NOTE_CS5,NOTE_F5,0    ,
  NOTE_DS5,NOTE_G5,NOTE_C6,NOTE_DS5,NOTE_G5,NOTE_C6,NOTE_DS5,NOTE_G5,0,
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_GS4,NOTE_C5,NOTE_F5,NOTE_GS4,NOTE_C5,NOTE_F5,NOTE_GS4,NOTE_C5,0     ,
  NOTE_A4,NOTE_CS5,NOTE_FS5,NOTE_A4,NOTE_CS5,NOTE_FS5,NOTE_A4,NOTE_CS5,0,

  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_CS5,NOTE_F5,NOTE_AS5,NOTE_CS5,NOTE_F5,NOTE_AS5,NOTE_CS5,NOTE_F5,0    ,
  NOTE_DS5,NOTE_G5,NOTE_C6,NOTE_DS5,NOTE_G5,NOTE_C6,NOTE_DS5,NOTE_G5,0,
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0    ,
  NOTE_GS4,NOTE_C5,NOTE_F5,NOTE_GS4,NOTE_C5,NOTE_F5,NOTE_GS4,NOTE_C5,0     ,
  NOTE_A4,NOTE_CS5,NOTE_FS5,NOTE_A4,NOTE_CS5,NOTE_FS5,NOTE_A4,NOTE_CS5,0,
  
  NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_AS4,NOTE_D5,0,-1

};

int mimp2Dur [] PROGMEM  = {

  2025,    //+25 for the delayed melody
  
  200,400,200,400,200,200,200,200,            
  200,400,200,400,200,200,200,200,  
 
  200,400,200,400,200,200,200,200,              
  200,400,200,400,200,200,200,200,
  
  150,50,150,50,800,800,   
  150,50,150,50,800,800,
  150,50,150,50,800,800,   
  150,50,400,1400,
  
  200,200,600,1000,   
  200,200,600,1000,
  200,200,600,1000,   
  200,400,1400,
  
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,180, 
  25,25,25,25,25,25,25,25,180,          // - 20 pause for arduino arpeggio, remind me of the good old 8-bit stuff ;)     
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,180, 
  25,25,25,25,25,25,25,25,180,       

  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,180, 
  25,25,25,25,25,25,25,25,180,                    
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,380,    
  25,25,25,25,25,25,25,25,180, 
  25,25,25,25,25,25,25,25,180,       
  
  25,25,25,25,25,25,25,25,300, 0
};


int led = 13;   //Just a LED

void setup()
{   
      pinMode(led, OUTPUT);                         // Set pinmode
      notePlayer[0].begin(OUT1);                    // Voice 1
      notePlayer[1].begin(OUT2);                    // Voice 2
      digitalWrite(led, LOW);                       // Turn off LED
}


void loop() {
  
  
        
        playTune(mimp, mimpDur, mimp2 , mimp2Dur ,0);  //Play the tune
                              
        
        
  
}



void playTune(int melody[],  int melDurations[], int harmony[],  int harmDurations[], boolean repeat )
{   
    value    = pgm_read_word(&melody[Counts[0]]); 
    value2   = pgm_read_word(&harmony[Counts[1]]);  
    dur      = pgm_read_word(&melDurations[Counts[0]]);  
    dur2     = pgm_read_word(&harmDurations[Counts[1]]);
  
    if(value == -1 || value2 == -1) {
            notePlayer[0].stop();
            notePlayer[1].stop();
   
            if(repeat == 1) {
            value=0;value2=0;dur=0;dur2=0;Counts[0]=0;Counts[1]=0;
            }
            return;  
    }
       
    if ( millis()>stopTimeNote1 ) {
          if(value==0) { 
            if(notePlayer[0].isPlaying()) notePlayer[0].stop();  
            digitalWrite(led, LOW); // Just a visual check if it´s doin something  
            }
            else{
              notePlayer[0].play(value);
              digitalWrite(led, HIGH); // Just a visual check if it´s doin something
            }
              stopTimeNote1 = millis() + dur;
              if(value != -1 ) {Counts[0]++;}
          
    }
        
    if ( millis()>stopTimeNote2 ) {
        if(value2==0) { if(notePlayer[1].isPlaying()) notePlayer[1].stop();    }
        else{
          notePlayer[1].play(value2);
        }
          stopTimeNote2 = millis() + dur2;
          if(value2 != -1 ) {Counts[1]++;}
      

    }
    return;
}

void resetTone() {
    Counts[0] = 0;
    Counts[1] = 0;
    stopTimeNote1 = 0;
    stopTimeNote2 = 0;
    notePlayer[0].stop();
    notePlayer[1].stop();
    value=0;
    value2=0;
    dur=0;
    dur2=0;
}






