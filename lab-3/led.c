#include "project.h"
#include "ports.h"

#include "led.h"
#include "timer.h"

static tWord delay;
static tWord ledState;
static tWord ledTick = 0;
static tWord blinkState;

/* DELAY in ms */
void Led_Init(tWord DELAY) {
  delay = DELAY;
  /* Turn off both leds */
  Led_Set()
}

/* Check the state of the leds, if on and the delay is reached
 -> blink and reset the tick
 If the state is off, just return the current tick to the timer */
void Led_Update(void) {

  /* After button has been presseed, reset the tick */
  if((ledState == ON) && (blinkState == OFF)) {
    Led_Reset();
    ledTick = 0;
  }

  ledTick++; //count up to the delay
  if(ledTick == delay) {
    if(ledState == ON) {
      Led_Blink();
    }
    ledTick = 0;
  }
}

/* Initialize the led blinking sqeuence by
 turning one led on and the other off, in this case the green one */
void Led_Reset(void) {
  LED_PORT |= GREEN_LED_PIN;
  LED_PORT &= ~RED_LED_PIN;
  blinkState = ON;
}

/* Change the state of the led, used when the
 switch is pressed.*/
void Led_Enable(tByte state) {
  switch(state) {
    case ON:
      LED_PORT_DIRECTION |= RED_LED_PIN + GREEN_LED_PIN;
      ledState = ON;
      break;

    case OFF:
      LED_PORT_DIRECTION &= ~(RED_LED_PIN + GREEN_LED_PIN);
      ledState = OFF;
      blinkState = OFF;
      break;
  }
}

/* Alternate between the red and green leds */
void Led_Blink(void) {
  LED_PORT ^= RED_LED_PIN + GREEN_LED_PIN;
}

void Led_State(tByte LED, tByte STATE) {
  switch(LED) {
    case RED_LED:
      if(STATE == ON){
        LED_PORT_DIRECTION |= RED_LED_PIN;
        LED_PORT |= RED_LED_PIN;
      }
      else{
        LED_PORT_DIRECTION &= ~RED_LED_PIN;
        LED_PORT &= ~RED_LED_PIN;
      }
    case GREEN_LED:
    if(STATE == ON){
        LED_PORT_DIRECTION |= GREEN_LED_PIN;
        LED_PORT |= GREEN_LED_PIN;
      }
      else{
        LED_PORT_DIRECTION &= ~GREEN_LED_PIN;
        LED_PORT &= ~GREEN_LED_PIN;
      }
  }
}
