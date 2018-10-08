#include "project.h"
#include "ports.h"

#include "uart.h"
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "eos.h"
#include "adc.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Init tasks */
  UART_Init();
  Led_Init();
  SCH_Init();
  Timer_Init();
  Switch_Init();
  ADC_Init();

  SCH_AddTask(Led_Update, 0, 100);
  SCH_AddTask(ADC_Read, 10, 300);
  SCH_AddTask(ADC_Write, 20, 300);

  UART_Write("Starting up\n\r");

  /* Superloop */
  while(1) {
    SCH_Dispatch();
  }
}
