#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

int main() {
    configureClocks();
 
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
  switch(sound_sequence_state) {
  case 0:
    if(secondCount == 250) {
      state_advance_song();
      secondCount = 0;
    }
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  }
}
