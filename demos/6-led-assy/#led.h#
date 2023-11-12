#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void greenControl(int on);
void oncePerSecond();
extern int blinkLimit;   //  state var representing reciprocal of duty cycle
                         //  extern to tell the compiler that the variable exists but
                         //  will be defined in another file

#endif // included
