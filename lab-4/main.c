#include "project.h"
#include "ports.h"

#include "uart.h"
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "eos.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Init tasks */
  UART_Init();
  Led_Init();
  SCH_Init();
  Timer_Init();
  Switch_Init();

  SCH_AddTask(Led_Update, 0, 100);

  UART_Write("Starting up\n\r");

  /* Superloop */
  while(1) {
    SCH_Dispatch();
  }
}
