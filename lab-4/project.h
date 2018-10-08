#ifndef _MAIN_H
#define _MAIN_H

#include "msp430.h"

#define DCO_FREQ 16*1e6
/* interval in ms */
#define TIMER_INTERVAL 10
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
#define RED_LED 0
#define GREEN_LED 1

typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;
typedef enum {RED, RED_GREEN, GREEN, GREEN_RED, AMBER} tLight_State;

#endif
