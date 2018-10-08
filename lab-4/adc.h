#ifndef _ADC_H
#define _ADC_H

#include "project.h"

void ADC_Init();
void ADC_Read();
void ADC_Write();

void integerToString(char* string, int number);

#endif