/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 13 de abril de 2021, 08:39 PM
 */


#include <xc.h>
#include "config.h"
#include "reloj.h"

void main(void) {
    
    PORTF=0;
    LATF=0;
    ANSELF=0;
    TRISF=0;
    
    ANSELA=0;
    INTCON0bits.GIE=0;
    
    T0CON0bits.EN=1;
    T0CON0bits.MD16=0;
    T0CON0bits.OUTPS=0;

    T0CON1bits.CS=0;
    T0CON1bits.CKPS=0;
    T0CON1bits.ASYNC=0;
    TMR0L=0;
    while(1){
        
        LATF=TMR0L;
        __delay_ms(250);
        
        if(TMR0L==15){
            TMR0L=0;
            
        }
    }
    
    return;
}
