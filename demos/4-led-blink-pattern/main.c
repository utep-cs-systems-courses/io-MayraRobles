//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state vars that control blinking
int blinkLimitGreen = 7;  // duty cycle = 1/blinkLimit
int blinkCountGreen = 0;  // cycles 0...blinkLimit-1
int secondCount = 0; // state var representing repeating time 0…1s

int blinkLimitRed = 0;
int blinkCountRed = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking for green LED
  blinkCountGreen ++;
  if (blinkCountGreen >= blinkLimitGreen) { // on for 1 interrupt period
    blinkCountGreen = 0;
    P1OUT |= LED_GREEN;
  } else		          // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_GREEN;

  //handle blinking fore red LED
  blinkCountRed ++;
  if (blinkCountRed >= blinkLimitRed) { // on for 1 interrupt period
    blinkCountRed = 0;
    P1OUT |= LED_RED;
  } else {                        // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_RED;
  }
  
  // measure a second
  secondCount ++;
  if (secondCount >= 500) {  // once each two seconds, to make brightness patterns chage slower
    secondCount = 0;
    blinkLimitGreen --;           // increase duty cycle, since we want to go from dim-to-bright
    if (blinkLimitGreen <= 0)     // but don't let duty cycle go below 1/7.
      blinkLimitGreen = 7;
    blinkLimitRed ++;             // decrease duty cycle
    if (blinkLimitRed >= 5)
      blinkLimitRed = 0;         // don't let duty cycle be more than 4 and no less than 1
  }
} 

