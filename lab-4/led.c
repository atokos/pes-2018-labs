#include "project.h"
#include "ports.h"

#include "led.h"
#include "uart.h"
#include "switch.h"

tWord blink_State_G;

/* DELAY in ms */
void Led_Init() {
  LED_PORT_DIRECTION |= RED_LED_PIN + GREEN_LED_PIN;
  LED_PORT |= RED_LED_PIN;
  LED_PORT &= ~GREEN_LED_PIN;
  blink_State_G = TRUE;
}

void Led_Update() {
  /* Check if switch is pressed */
  if(isPressed() == TRUE){
    if(blink_State_G == TRUE){
      blink_State_G = FALSE;
      UART_Write("Blink off\n\r");
    }
    else{
      blink_State_G = TRUE;
      UART_Write("Blink on\n\r");
    }
  }
  if(blink_State_G == TRUE){
    LED_PORT ^= RED_LED_PIN + GREEN_LED_PIN;
    UART_Write("Blinking\n\r");
  }
}
