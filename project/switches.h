#ifndef switches_included
#define switches_included


#define SW1 BIT0 // switch 1 is at p2.0
#define SW2 BIT1 // swtich 2 is at p2.1
#define SW3 BIT2 // swtich 3 is at p2.3
#define SW4 BIT3 // switch 4 is at p2.3

#define SWITCHES (SW1 | SW2 | SW3 | SW4) //all port 2 switches

void switch_init();
void switch_interrupt_handler();

extern int sw1Down, sw2Down, sw3Down, sw4Down;
extern int oddPress1, oddPress2, oddPress3, oddPress4;

#endif
