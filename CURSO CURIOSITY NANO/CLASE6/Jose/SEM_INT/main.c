/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 27 de abril de 2021, 07:05 PM
 */

#include "config.h"
#include <xc.h>

/*Declaracion de Funciones*/
void SEM (void);
void INT_Config(void);
void main(void) {
    TRISA=0;
    LATA=0;
    
    ANSELBbits.ANSELB0=0;   //PIN DIGITAL
    TRISBbits.TRISB0=1;
    WPUBbits.WPUB0=1;
    
    INT_Config();
    while(1){
        SEM();
    }
    
    
    
    return;
}

void SEM (void){
    
    LATAbits.LATA0=1;
    __delay_ms(2000);
    LATAbits.LATA0=0;
    LATAbits.LATA1=1;
    __delay_ms(500);
    LATAbits.LATA1=0;
    LATAbits.LATA2=1;
    __delay_ms(1000);
    LATAbits.LATA2=0;
    
}
void INT_Config(void){
    /*Registro INTCON0*/
    INTCON0bits.GIE=1;
    INTCON0bits.IPEN=0;
    INTCON0bits.INT0EDG=0;
    /*Registro PIE1 -> Interrupcion externa*/
    PIE1bits.INT0IE=1;
    /*Registro */
    PIR1bits.INT0IF=0;
}

void __interrupt (irq(default),base(0X3008)) DEFAULT_ISR(void){
    PIR1bits.INT0IF=0;
    LATA=0;
    LATAbits.LATA0=1;
    __delay_ms(100);
    SEM();
}
