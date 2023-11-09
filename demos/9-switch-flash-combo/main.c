/* This file was modified to implement the suggested activity of implementing
   different blink sequences where each button press changes it */
#include <msp430.h>
#include "libTimer.h"

#define LED_GREEN BIT0             // P1.0
#define LED_RED BIT6               // P1.6
#define LEDS (LED_RED | LED_GREEN)

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

void switch_init() {
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
}

void led_init() {
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
}

void wdt_init() {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
}

void main(void) 
{  
  switch_init();
  led_init();
  wdt_init();
    
  or_sr(0x18);  // CPU off, GIE on
} 

enum State {RED, GREEN, BOTH};
static enum State cur_state = RED; /* this destermines the blink sequence to implement */
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};
unsigned char red_on = 0, green_on = 0;
static unsigned char binary_count = 0;

void
switch_interrupt_handler()
{
  char p1val = P1IN;    /* switch is in P1 */
  
  P1IES |= (p1val & SWITCHES);  /* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);  /* if switch down, sense up */
  
  if (p1val & SW1) {    /* button pressed */
    /* Every time a button pressed, change sequence state */
    cur_state = (cur_state + 1) % 3;
  } 
 }


/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  static int blink_count = 0;
  switch(cur_state) {
  case RED: /* red LED blinking sequence*/
    P1OUT &= ~LED_GREEN;
    switch (blink_count) { 
     case 6: 
       blink_count = 0;
       P1OUT |= LED_RED;
       break;
     default:
       blink_count ++;
       P1OUT &= ~LED_RED;
    }
    break;
  case GREEN: /* green LED blinking sequence*/
    P1OUT &= ~LED_RED;
    switch (blink_count) {
    case 6:
      blink_count = 0;
      P1OUT |= LED_GREEN;
      break;
    default:
      blink_count ++;
      P1OUT &= ~LED_GREEN;
    }
    break;
  case BOTH: /* Counts to 3 in binary */
    switch (blink_count) {
    case 125:
      blink_count = 0;
      static int binary_count = 0;
      binary_count = (binary_count + 1) % 4; // Increment binary count and take modulo
      switch (binary_count) {
      case 0:
	red_on = 0;
	green_on = 0;
	break;
      case 1:
	red_on = 0;
	green_on = 1;
	break;
      case 2:
	red_on = 1;
	green_on = 0;
	break;
      case 3:
	red_on = 1;
	green_on = 1;
	break;
      }
      char ledFlags = redVal[red_on] | greenVal[green_on];
      P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
      P1OUT |= ledFlags;     // set bit for on leds
    break;
    }
  default:
    blink_count ++;
  } 
}
