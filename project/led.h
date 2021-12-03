#ifndef led_included
#define led_included

#define LED_RED BIT0    //p1.0
#define LED_GREEN BIT6  //p1.6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void red_on(int on);
void green_on(int on);
void leds_on(int on);
void alternate(int on);

#endif
