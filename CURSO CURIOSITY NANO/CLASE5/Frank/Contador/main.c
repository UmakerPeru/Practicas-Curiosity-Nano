/*
 * File:   main.c
 * Author: FHuaylinos
 *
 * Created on 13 de abril de 2021, 08:39 PM
 */


#include <xc.h>
#include "config.h"

void main(void) {
    
    //LEDS
    PORTF = 0;
    LATF = 0;
    ANSELF = 0;
    TRISF = 0;
    //CONFIG TIMER0 CONTADOR
    INTCON0bits.GIE = 0;
    
    T0CON0bits.EN = 1;
    T0CON0bits.MD16 = 0;
    T0CON0bits.OUTPS = 0000;
    
    T0CON1bits.CS = 000;
    T0CON1bits.CKPS = 0000;
    T0CON1bits.ASYNC = 0;
    
    //Programa principal
    TMR0L = 0;
    while(1) {
        LATF = TMR0L;
        __delay_ms(500);
        if(TMR0L == 15) {
            TMR0L = 0;
        }
    }
    
    return;
}
