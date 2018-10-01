#ifndef _LED_H
#define _LED_H

#include "project.h"

void Led_Init(tWord DELAY);

void Led_Update();

void Led_OFF();

void Led_Reset();

void Led_Enable(tByte state);

void Led_Blink();


#endif
