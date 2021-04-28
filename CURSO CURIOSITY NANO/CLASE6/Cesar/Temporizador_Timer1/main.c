/*
 * File:   main.c
 * Author: Cesar Sanchez
 *
 * Created on 22 de abril de 2021, 09:44 AM
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
    ANSELC = 0; // PULSADOR COMO DIGITAL
    
    //CONFIG TIMER1 
    T1CONbits.ON = 1;  // habilitar timer 1
    T1CONbits.CKPS = 0b00; // prescaler 1 a 1
    T1CONbits.RD16 = 0; // modo de 8 bits
    T1CONbits.NOT_SYNC = 0; // sincronizar reloj externo con reloj del sistema
    
    T1CLKbits.CS = 0b00000; // seleccionaar el pin T1CKIPPS
    
    T1GCONbits.GE = 0; // timer en modo contador
    
    T1GATEbits.GSS = 0b000000; // seleccion puerta  T1GPPS
    
    INTCON0bits.GIE = 0; // deshabilitar interrupciones
//    T1GCONbits.GTM = 0;
//    T1GCONbits.GPOL = 1;
//    T1GCONbits.GSPM = 0;
//    T1GCONbits.GGO = 0;
    //-------------------------
    TMR1L = 0;
    while(1)
    {
        LATF = TMR1L;
        __delay_ms(500);
        if(TMR1L == 15)
        {
           TMR1L = 0; 
        }
    }
    return;
}
