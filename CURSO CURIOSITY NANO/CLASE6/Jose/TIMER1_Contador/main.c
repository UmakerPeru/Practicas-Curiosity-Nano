/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 21 de abril de 2021, 07:15 PM
 */


#include <xc.h>
#include "config.h"
#include <stdio.h>
/*Declaracion de Funciones*/
void TIMER_Config(void);
void GPIO_Config (void);

void main(void) {
    GPIO_Config();
    TIMER_Config();
    
    while(1){
        
        LATF=TMR1L;
        __delay_ms(200);
        if(TMR1L==15){
            TMR1L=0;
        }   
    }
    return;
}


void TIMER_Config(void){
    /*Registro T1CON*/
    T1CONbits.CKPS=0;           //Temporizador de entrada Reloj Selección de preescalador 1:1
    T1CONbits.RD16=0;       
    T1CONbits.ON=1;             //Enables Timer
    T1CONbits.NOT_SYNC=1;
    
    /*Registro T1GCON*/
    T1GCONbits.GTM=0;           //El modo Timer Gate Toggle está deshabilitado y Toggle flip-flop está desactivado
    
    /*Registro T1CLK*/
    T1CLKbits.CS=0b0000;        //Selección de la fuente del reloj del temporizador
    /*Deshabilitar Interrupciones*/
    INTCON0bits.GIE=0;
}

void GPIO_Config (void){
    /*PIN RC0 -> T1CKIPPS*/
    TRISCbits.TRISC0=1;
    ANSELC=0;               //Pin Digital
    
    ANSELF=0;
    TRISF=0;
    LATF=0;
}
