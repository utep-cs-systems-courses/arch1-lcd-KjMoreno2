#include <msp430.h>
#include "switches.h"

//turn on p2

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) { // check for button interrupt
    P2IFG &= ~SWITCHES; //clear switch interrupts
    switch_interrupt_handler(); //handler for all switches
  }
}
