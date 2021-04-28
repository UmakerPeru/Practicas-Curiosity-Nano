/*
 * File:   main.c
 * Author: Cesar Sanchez
 *
 * Created on April 27, 2021, 8:17 PM
 */


#include <xc.h>
#include "config.h"
#include <pic18f57q43.h>

void main(void) 
{
    ANSELA = 0;
    TRISA = 0;
    LATA = 0;
    
    // resistencia pull up 
    ANSELB = 0;
    TRISB = 0b00000001;
    WPUB = 1;
    
    INTCON0 = 0b10000000;//habilitar las interrupciones globales
    PIE1 = 1; // definir innterrupcion externa
    PIR1bits.INT0IF = 0; // Limpiar la bandera
    while(1)
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
void __interrupt (irq(default), base(0x3008)) DEFAULT_ISR(void)
{
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 0;
    LATAbits.LATA2 = 0;
    __delay_ms(200);
    PIR1bits.INT0IF = 0;
}
