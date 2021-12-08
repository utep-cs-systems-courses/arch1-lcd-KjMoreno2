#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcddraw.h"
#include "lcdutils.h"
#include "lcdtypes.h"

int oddPress1 = 0;
int oddPress2 = 0;
int oddPress3 = 0;
int oddPress4 = 0;
//some starting positions
static unsigned char colS = 20;
static unsigned char rowS = 20;
static unsigned char startC = screenHeight / 2;
static unsigned char startR = screenWidth / 2;

// colors for hot pink
static char blue = 128, green = 71, red = 127;

short redrawScreen = 0;

void wdt_c_handler(){
  static int clockCount = 0;

  clockCount++;
  if(clockCount >= 63 && oddPress1 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
    
  }
  if(clockCount >= 63 && oddPress2 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
  }
  if(clockCount >= 63 && oddPress3 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
  }
  if(clockCount >= 63 && oddPress4 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
  }
}

int main(void) {
  red_on(1);
  green_on(1);
  configureClocks(); /* setup master oscillator, CPU and peripharel clocks */
  lcd_init();
  led_init();
  buzzer_init();
  switch_init();
  
  enableWDTInterrupts();
  or_sr(0x8); /* CPU off, GIE on*/


  clearScreen(COLOR_ORANGE);
  while(1){
    if(redrawScreen) {
      //button move left1
      if(oddPress1){
	if(startC == 0){ startC = screenHeight / 2;}
	else{ startC -= 5;}
	drawTriForce(startC, startR);
      }
      //button2 move right
      else if(oddPress2){
	if(startC + colS == screenHeight){ startC = 0;}
	else{ startC += 5;}
	drawTriForce(startC, startR);
      }
      //button3 TODO FIGURE OUT BUTTON 3 move up?
      else if(oddPress3){
	playSong();
      }
      //button4 show message 
      else if(oddPress4){
	drawString5x7(10, 20, "Thanks Link! You're\nthe hero of\nHyrule.", COLOR_RED, COLOR_BLACK);
	drawTriForce(startC, startR);
      }
      redrawScreen = 0;
    } // end of if redraw
    green_on(0);
    or_sr(0x10);
    green_on(1);
  }// end of while
} // end of main
void drawTriForce(u_char beginCol, u_char beginRow){
  clearScreen(COLOR_DARK_GREEN);
  for(int row =0; row <= 30; row++){
    int col1 = row;
    int col2 = -row;
    for(int col = col2; col <= col1; col++){
      drawPixel(col + beginCol, row + beginRow, COLOR_GOLD);
      drawPixel(col+beginCol+30, row+beginRow+30, COLOR_GOLD);
      drawPixel(col+beginCol-30, row+beginRow+30, COLOR_GOLD);
    }
  }
}
