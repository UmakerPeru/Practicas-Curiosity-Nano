/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 13 de abril de 2021, 08:05 PM
 */


#include <xc.h>
#include "config.h"

void configuracionTimer(void);
void configuracionPuertos(void);

void main(void) {
    configuracionPuertos();
    configuracionTimer();
    while(1){
        LATF=TMR0L;
        __delay_ms(150);
        if(TMR0L==15){
            TMR0L=0;
        }
    }
    return;
}

void configuracionTimer(){
    //T0CON0
    T0CON0bits.EN=1;
    T0CON0bits.MD16=0;
    T0CON0bits.OUTPS=0000;
    //T0CON1
    T0CON1bits.CS=000;
    T0CON1bits.CKPS=0000;
    T0CON1bits.ASYNC=0;
    //INTCON0
    INTCON0bits.GIE=0;
    //TMR0L
    TMR0L=0;
}

void configuracionPuertos(){
    //Puerto de salida
    PORTF=0;
    LATF=0;
    ANSELF=0;
    TRISF=0;
    //Puerto de entrada
    ANSELA=0;
}
