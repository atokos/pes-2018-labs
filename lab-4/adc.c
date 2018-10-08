#include "project.h"
#include "adc.h"
#include "uart.h"

static tWord gADCLastVal = 0;

//initialize the ADC 
void ADC_Init(){
	
	ADC10CTL0 &= ENC; // Start conversion
	
	//ADC10CTL0 = ADC10ON +MSC +ADC10SHT_3;
	
	ADC10CTL0 = ADC10ON + ADC10SHT_3 + SREF_1 + REFON;
	// Turn adc on,MSC take multiple samples,adc10sht_3 sample and 
	// Hold for 64 clock cycles
	// ADC10CTL1 = INCH_10 + ADC10SSEL_3 + ADC10DIV_4;
	
	ADC10CTL1 = INCH_10 + ADC10DIV_3;
	// inch_10 channel 4, ADC10SSEL_3 clock source select,adc10DIV_4 clock divider  
	
}

void ADC_Read(void) { 
	tWord count = 32000;
	ADC10CTL0 |= ENC + ADC10SC; //sampling and conversion start
	
	while((ADC10CTL1 & ADC10BUSY) && --count);
	if (!count) UART_Write("ADC timeout error");
	
	gADCLastVal = ADC10MEM; //conversion memory register
	// current value is stored in the gADCLastVal variable
	
	//shut off the conversion
	ADC10CTL0 &= ~ENC;
}

void ADC_Write(void) {
    char str[20];
    sprintf(str, "Temp: %d\n\r", (int) gADCLastVal);
    char *temperature = str;
    UART_Write(str);
}

void integerToString(char* string, int number) {

    if(number == 0) {
         string[0] = '0'; return; 
    }

    int divide = 0;
    int modResult;
    int  length = 0;
    int isNegative = 0;
    int  copyOfNumber;
    int offset = 0;
    copyOfNumber = number;

    if( number < 0 ) {
        isNegative = 1;
        number = 0 - number;
        length++;
    }
    while(copyOfNumber != 0) { 
        length++;
        copyOfNumber /= 10;
    }

    for(divide = 0; divide < length; divide++) {
        modResult = number % 10;
        number    = number / 10;
        string[length - (divide + 1)] = modResult + '0';
    }
    if(isNegative) { 
    string[0] = '-';
    }
    string[length] = '\0';
}