#include "pitches.h" 
#include <toneAC.h>                                         // I used this library because it produces less crackles and sounds clearer than the normal tone.

int threshold = 29;                                         // This is so the potentiometers can tell when it is being touched 

void setup() {
  Serial.begin(115200);
  pinMode(7, OUTPUT); 
  delay(1);
}

void loop() {
  int pot0 = analogRead(A0); 
  int pot1 = analogRead(A1);

  int freq1 = map(pot1, 1023, 30, NOTE_C4, NOTE_C5);         // Assigns the potentiometer's to the notes. 
  int freq0 = map(pot0, 1023, 30, NOTE_E4, NOTE_E5);

  if (pot1 > threshold){                                     // If pot is touched: Play Note
    toneAC(freq1);
  }
  else if (pot0 > threshold){
    toneAC(freq0);
  }
  else{                                                      // If not being touched: No Sound
    noToneAC();
  }
  //Serial.println(freq0);
}
