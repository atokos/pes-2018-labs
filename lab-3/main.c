#include "project.h"
#include "ports.h"

#include "led.h"
#include "traffic.h"
#include "switch.h"
#include "timer.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;
  Led_Init(1000);
  Traffic_Init();
  Timer_Init();
  Switch_Init();

  /* Superloop */
  while(1) {
  }
}
