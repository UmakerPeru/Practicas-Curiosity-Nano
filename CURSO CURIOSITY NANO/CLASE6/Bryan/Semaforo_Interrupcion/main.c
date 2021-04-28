/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 27 de abril de 2021, 08:12 PM
 */


#include <xc.h>
#include "config.h"


void configPuertos(void);
void configInterrup(void);

void main(void) {
    
    configPuertos();
    configInterrup();
    
    while (1) {
        LATFbits.LATF0 = 1;
        __delay_ms(2000);
        LATFbits.LATF0 = 0;
        LATFbits.LATF1 = 1;
        __delay_ms(2000);
        LATFbits.LATF1 = 0;
        LATFbits.LATF2 = 1;
        __delay_ms(2000);
        LATFbits.LATF2 = 0;
    }
    return;
}

void configPuertos(void) {
    ANSELF = 0;
    TRISF = 0;
    LATF = 0;
    
    ANSELB = 0;
    TRISB = 0b00000001;
    WPUBbits.WPUB0 = 1;
}

void configInterrup(void) {
    INTCON0 = 0b10000000; //Habilitar interrupciones
    PIE1 = 1; //Definir interrupciones
    PIR1bits.INT0IF = 0;
}

void __interrupt(irq(default), base(0x3008)) DEFAULT_ISR(void) {
    LATFbits.LATF2 = 1;
    LATFbits.LATF1 = 0;
    LATFbits.LATF0 = 0;
    __delay_ms(3000);
    LATFbits.LATF2 = 0;
    PIR1bits.INT0IF = 0;
}
