/* This file was modified to implement the suggested activity of implementing
   different blink sequences where each button press changes it */
#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
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

static int buttonDown;
static int blink_sequence_state = 0; /* This destermines the blink sequence to implement*/

void
switch_interrupt_handler()
{
  char p1val = P1IN;    /* switch is in P1 */
  
  P1IES |= (p1val & SWITCHES);  /* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);  /* if switch down, sense up */
  
  if (p1val & SW1) {    /* button up */
    buttonDown = 0;
 } else {      /* button down */
    buttonDown = 1;
  }
  
  /* Every time there is a button pressed, change sequence state*/
  blink_sequence_state = (blink_sequence_state + 1);
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
  switch(blink_sequence_state) {
  case 0: /* Red LED blinking sequence*/
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
  case 1:
    break;
  case 2: /* Green LED blinking sequence*/
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
  case 3:
    blink_sequence_state = 0;
    break;
    // For later
    /*case 2: /* Both LEDS blinking sequence
    switch (blink_count) { 
     case 125: 
       blink_count = 0;
       P1OUT ^= LEDS; /* Toggle red and green LEDS
       break;
     default:
       blink_count ++;
    }
    break ;*/
  }
} 
