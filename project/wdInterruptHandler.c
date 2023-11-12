#include <msp430.h>
#include "stateMachines.h"

int secondCount = 0;
char sound_sequence_state = 3;

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  secondCount ++;
  switch(sound_sequence_state) {
  case 0:
    if(secondCount >= 40) {
      state_advance_song();
      secondCount = 0;
    }
    break;
  case 1:
    buzzer_set_period(1000);// start buzzing!!! 2MHz/1000 = 2kHz
    break;
  case 2:
    buzzer_set_period(1000);// start buzzing!!! 2MHz/1000 = 2kHz
    break;
  case 3:
    buzzer_set_period(1000);// start buzzing!!! 2MHz/1000 = 2kH
    break;
  }
}
