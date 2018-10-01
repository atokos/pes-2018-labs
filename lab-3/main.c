#include "project.h"
#include "ports.h"

#include "led.h"
#include "traffic.h"
#include "switch.h"
#include "timer.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Init tasks */
  Led_Init(1000);
  Traffic_Init();
  Timer_Init();
  Switch_Init();

  __enable_interrupt();

  /* Superloop */
  while(1) {
    LPM1; // Enter low power mode
  }
}
