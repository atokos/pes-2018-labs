#include <msp430.h>

int main(void) {

  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Set P1.0 and P1.6 direction to output */
  P1DIR |= 0x01;
  P1DIR |= 0x40;

  /* Set P1.0 output high*/
  P1OUT |= 0x01;

  /* Set P1.6 output low*/
  P1OUT &= 0x40;
  
  /* Superloop */
  while(1) {

    /* Volatile to prevent optimization by the compiler*/
    volatile unsigned int i;

    /* Software delay, roughly 1 second */
    i = 60000;
    do i--;
    while(i != 0);

    /* Toggle between P1.0 and P1.6 */
    P1OUT ^= 0x41;
  }
}
