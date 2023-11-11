#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

void wdt_init() {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
}

int main() {
  wdt_init();
  buzzer_init();
  switch_init();
  //buzzer_set_period(1000);	/* start buzzing!!! 2MHz/1000 = 2kHz*/

    or_sr(0x18);          // CPU off, GIE on
}

int secondCount = 0;
char sound_sequence_state = 3;

void
__interrupt_vec(WDT_VECTOR) WDT ()
{
  /* secondCount ++;
  if(secondCount >= 40) {
    state_advance_song();
    secondCount = 0;
    }*/
  
  switch(sound_sequence_state) {
  case 0:
    secondCount ++;
    if(secondCount >= 40) {
      state_advance_song();
      secondCount = 0;
    }
    break;
  case 1:
    buzzer_set_period(1000);	// start buzzing!!! 2MHz/1000 = 2kHz
    break;
  case 2:
    buzzer_set_period(1000);	// start buzzing!!! 2MHz/1000 = 2kHz
    break;
  case 3:
    buzzer_set_period(1000);	// start buzzing!!! 2MHz/1000 = 2kH
    break;
  }
}

/* Switches on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
  }
}
