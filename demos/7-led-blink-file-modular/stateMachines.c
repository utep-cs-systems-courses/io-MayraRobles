#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

/* Modified to count to three using the red and green lights */
void state_advance()		/* alternate between toggling red & green */
{  
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

  led_changed = 1;
  led_update();
}

