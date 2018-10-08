#include "project.h"
#include "ports.h"

#include "led.h"

/* DELAY in ms */
void Led_Init() {
  LED_PORT_DIRECTION |= RED_LED_PIN + GREEN_LED_PIN;
  LED_PORT |= RED_LED_PIN;
  LED_PORT &= ~GREEN_LED_PIN;
}

void Led_Update() {
  LED_PORT ^= RED_LED_PIN + GREEN_LED_PIN;
}
