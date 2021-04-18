/*
 * File:   main.c
 * Author: Cesar Sanchez
 *
 * Created on 17 de abril de 2021, 11:38 PM
 */


#include <xc.h>
#include "config.h"

void main(void) 
{
    //leds
    PORTF = 0;
    LATF = 0;
    ANSELF = 0; // TODO DIGITAL
    TRISF = 0;
    ANSELA = 0; // PULSADOR COMO DIGITAL
    
    //CONFIG TIMER0 CONTADOR
    INTCON0bits.GIE = 0; //desabilitar interrupciones
    
    T0CON0bits.EN = 1;
    T0CON0bits.MD16 = 0; // modo de 8 bits
    T0CON0bits.OUTPS = 0000; // sin postcaler
    
    T0CON1bits.CS = 000; // entrada no inversora
    T0CON1bits.CKPS = 0000; //relacion del presaler 1 a 1
    T0CON1bits.ASYNC = 0; // sincronizar con FOSC/4
    //-------------------------
    TMR0L = 0;
    while(1)
    {
        LATF = TMR0L;
        __delay_ms(150);
        if(TMR0L == 15)
        {
           TMR0L = 0; 
        }
    }
    return;
}

