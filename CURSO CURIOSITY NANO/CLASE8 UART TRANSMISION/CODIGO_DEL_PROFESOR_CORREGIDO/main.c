

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 1000000

void UART1_Initialize(void);
void OSC_config(void);
void UART1_Write(uint8_t);
void main() {
    OSC_config();
    UART1_Initialize();
    LATF = 0;
    TRISF = 0;
    RF0PPS= 0x20;   
    while(1)
        {  
            printf("Hola\n");
            __delay_ms(1000);            
        } 
}
void UART1_Initialize(void)
{   U1CON0 = 0xB0; 
    U1CON1 = 0x80; //bit7 enable port uart
    U1BRGL = 0x19;
    U1BRGH = 0x00;
}
void OSC_config(void)
{   
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0b0010; //ENTRE 4
    OSCFRQbits.HFFRQ = 0b0010;  //4Mhz
}
void UART1_Write(uint8_t txData)
{       
    while (PIR4bits.U1TXIF == 0)
    {}
    U1TXB = txData;   
}
void putch(char txData)
{ 
    UART1_Write(txData);
}
