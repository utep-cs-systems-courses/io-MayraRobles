#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

enum State {RED, GREEN};
static enum State cur_state = RED;

void main(void) 
{  
  configureClocks();

  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */

  or_sr(0x18);  // CPU off, GIE on
} 


/* this function was modified to toggle between green and red when button pressed*/
void
switch_interrupt_handler()
{
  char p1val = P1IN;/* switch is in P1 */

  /* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  /* up=keep same, down=change */
  if (p1val & SW1) { /* Pressed */
    if (cur_state == RED) {
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
      cur_state = GREEN;
    } else if (cur_state == GREEN) {
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      cur_state = RED;
    }
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


/* This is the orignal switch_interrupt_handler*/
/*
void
switch_interrupt_handler()
{
  char p1val = P1IN;		// switch is in P1 

// update switch interrupt sense to detect changes from current buttons 
  P1IES |= (p1val & SWITCHES);	// if switch up, sense down 
  P1IES &= (p1val | ~SWITCHES);	// if switch down, sense up 

// up=red, down=green 
  if (p1val & SW1) {  // if this condition is true, it means button is pressed
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
  } else {   // button is not pressed
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  }
}
*/
