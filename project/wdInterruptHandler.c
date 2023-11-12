#include <msp430.h>
#include "buzzer.h"
#include "stateMachines.h"

int secondCount = 0;
char sound_sequence_state = -1;

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  secondCount ++;
  
  switch(sound_sequence_state) {
  case 0:
    if(secondCount >= 40) {
      canon_in_D_state_advance();
      secondCount = 0;
    }
    break;
  case 1:
    if(secondCount >= 25) {
      siren_state_advance();
      secondCount = 0;
    }
    break;
  case 2:
    buzzer_set_period(0);
    dim_green_state_advance();
    dim_red_state_advance();
    break;
  case 3:
    buzzer_set_period(0);
    break;
  }
}
