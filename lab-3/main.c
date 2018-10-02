#include "project.h"
#include "ports.h"

#include "uart.h"
#include "led.h"
#include "traffic.h"
#include "switch.h"
#include "timer.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Init tasks */
  UART_Init();
  Led_Init(1000);
  Traffic_Init();
  Timer_Init();
  Switch_Init();

  /* Enable interrupts */
  __enable_interrupt();

  /* Superloop */
  while(1) {
    LPM1; // Enter low power mode
  }
}
