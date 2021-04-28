/*
 * File:   main.c
 * Author: Cesar Sanchez
 *
 * Created on 27 de abril de 2021, 07:01 PM
 */

#include <xc.h>
#include "config.h"

void main(void) 
{
    ANSELA = 0;
    TRISA = 0;
    LATA = 0;
    
    // resistencia pull up 
    ANSELB = 0;
    TRISB = 0b00000001;
    WPUB = 1;
   
    if(PORTBbits.RB0 == 0)
    {
        RA2 = 1;
        RA1 = 0;
        RA0 = 0;
        __delay_ms(600);
        RA2 = 0;
        RA1 = 1;
        RA0 = 0;
        __delay_ms(600);
        RA2 = 0;
        RA1 = 0;
        RA0 = 1;
        __delay_ms(600);
    }
    
    return;
}
