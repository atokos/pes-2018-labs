#include "project.h"
#include "ports.h"

#include "led.h"
#include "switch.h"
#include "timer.h"

int main(void) {
  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;
  Led_Init(1000);
  Timer_Init();
  Switch_Init();

  /* Superloop */
  while(1) {

    /* Check if switch is pressed */
    if(isPressed() == TRUE){
      Led_Enable(OFF);
    }
    else{
      Led_Enable(ON);
    }
  }
}
