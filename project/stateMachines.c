#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "notes.h"

static int toggle_red = 0;
static int toggle_green=0;

void redDim25(){
  switch (toggle_red){
  case 0:
    red_on(0);
    toggle_red++;
  case 1:
    toggle_red++;
  case 2:
    toggle_red++;
    break;
  case 3:
    red_on(1);
    toggle_red = 0;
    break;
  default:
    break;
  }
}

void redDim50(){
  switch(toggle_red){
  case 0:
    red_on(0);
    toggle_red++;
    break;
  case 1:
    red_on(0);
    toggle_red++;
    break;
  case 2:
    toggle_red++;
    break;
  case 3:
    red_on(1);
    toggle_red = 0;
  default:
    break;
  }
}

void redDim75(){
  switch (toggle_red){
  case 0:
    red_on(0);
    toggle_red++;
    break;
  case 1:
    toggle_red++;
    break;
  case 2:
    toggle_red++;
    break;
  case 3:
    red_on(1);
    toggle_red = 0;
    break;
  default:
    break;
  }
}


void greenDim25(){
  switch(toggle_green){
  case 0:
    green_on(0);
    toggle_green++;
  case 1:
    toggle_green++;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green = 0;
    break;
  default:
    break;
  }
}


void greenDim50(){
  switch(toggle_green){
  case 0:
    green_on(1);
    toggle_green++;
    break;
  case 1:
    green_on(0);
    toggle_green++;
    break;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green++;
  default:
    break;
  }
}

void greenDim75(){
  switch (toggle_green){
  case 0:
    green_on(0);
    toggle_green++;
    break;
  case 1:
    toggle_green++;
    break;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green = 0;
    break;
  default:
    break;
  }
}
/*
void dim_sequence(){
  static int dimState = 0;

  switch (dimState){
  case 0:
    redDim50();
    greenDim50();
    dimState = 1;
    break;
  case 1:
    redDim75();
    greenDim25();
    dimState = 2;
    break;
  case 2:
    redDim75();
    greenDim25();
    dimState = 0;
    break;
  default:
    break;
  }
}
*/
// Il vento d'oro
void playSong(){
  static char currNote =0;
  int notes[26] = {FSH, 0, 0, D, 0, 0, D, E, F, E, 0, D, CSH, D, E, FSH, 0, B, B4, CSH, D, E, D, CSH, A, G};
  int n = 26;
  if (currNote < n){
    buzzer_set_period(notes[currNote]);
    currNote++;
  }
  else{
    currNote = 0;
  }
}
//halo
void playSong2(){
  static char currNote = 0;
  //notes of song as list, 0 denotes a rest

  int notes[29] = {E4, 0, 0, FSH4, G4, FSH4, A4, G4, FSH4, 0, E4, 0, 0, B4, CSH, D4, 0, 0, CSH, A4, CSH, B4, 0, D4, E4, G4, A4, FSH4};
  int n = 29;

  if (currNote < n){
    buzzer_set_period(notes[currNote]);
    currNote++;
  }
  else {
    currNote = 0;
  }
  
}
//dishonored
void playSong3(){
  static char currNote = 0;


  switch(currNote){
  case 0:
    buzzer_set_period(C2);
    alternate(1);
    currNote++;
    break;
  case 1:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 2:
    buzzer_set_period(GSH2);
    alternate(1);
    currNote++;
    break;
  case 3:
    buzzer_set_period(C2);
    alternate(0);
    currNote++;
    break;
  case 4:
    buzzer_set_period(F2);
    alternate(1);
    currNote++;
    break;
  case 5:
    buzzer_set_period(GSH2);
    alternate(0);
    currNote++;
    break;
  case 6:
    buzzer_set_period(C2);
    alternate(1);
    currNote++;
    break;
  case 7:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 8:
    buzzer_set_period(C2);
    alternate(1);
    currNote++;
    break;
  case 9:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 10:
    buzzer_set_period(GSH2);
    alternate(1);
    currNote++;
    break;
  case 11:
    buzzer_set_period(C2);
    alternate(0);
    currNote++;
    break;
  case 12:
    buzzer_set_period(F2);
    alternate(1);
    currNote++;
    break;
  case 13:
    buzzer_set_period(GSH2);
    alternate(0);
    currNote++;
    break;
  case 14:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 15:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 16:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 17:
    buzzer_set_period(GSH2);
    alternate(0);
    currNote++;
    break;
  case 18:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 19:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 20:
    buzzer_set_period(E2);
    alternate(1);
    currNote++;
    break;
  case 21:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 22:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 23:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 24:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 25:
    buzzer_set_period(GSH2);
    alternate(0);
    currNote++;
    break;
  case 26:
    buzzer_set_period(G2);
    alternate(1);
    currNote++;
    break;
  case 27:
    buzzer_set_period(F2);
    alternate(0);
    currNote++;
    break;
  case 28:
    buzzer_set_period(DSH2);
    alternate(1);
    currNote++;
    break;
  case 29:
    buzzer_set_period(CSH2);
    alternate(0);
    currNote++;
    break;
  case 30:
    buzzer_set_period(C2);
    alternate(1);
    currNote++;
    break;
  case 31:
    buzzer_set_period(ASH1);
    alternate(0);
    currNote++;
    break;
  case 32:
    buzzer_set_period(0);
    leds_on(0);
    currNote = 0;
    break;
  default:
    currNote++;
    break;
  }
} // end of song3

