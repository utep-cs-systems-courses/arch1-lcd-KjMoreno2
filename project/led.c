#include <msp430.h>
#include "led.h"
#include "switches.h"


void led_init(){
  // P!DIR points to specific bits
  P1DIR |= LEDS; // bits that are stored in leds become output
  led_update(); 
}

void led_update(){
  //P1OUT outputs a byte
  //LEDS initialized to off
  P1OUT &= ~LEDS;
}

void red_on(int on){
  //Red LED powered is boolean, 0 false 1 true
  switch(on){
  case 0:
    P1OUT &= ~LED_RED;
    break;
  case 1:
    P1OUT |= LED_RED;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void green_on(int on){
  //Green LED powered is boolean, 0 false, 1 true
  switch(on){
  case 0:
    P1OUT &= ~LED_GREEN;
    break;
  case 1:
    P1OUT |= LED_GREEN;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void leds_on(int on){
  //0- off, 1- on
  switch(on){
  case 0:
    P1OUT &= ~LEDS;
    break;
  case 1:
    P1OUT |= LEDS;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void alternate(int on){
  // 1 - Red on, green off
  // 0 - Green on Red off
  switch(on){
  case 0:
    red_on(1);
    green_on(1);
    break;
  case 1:
    red_on(0);
    green_on(1);
    break;
  default:
    leds_on(0);
    break;
  }
}
