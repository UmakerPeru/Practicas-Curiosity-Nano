/*
 * File:   main.c
 * Author: Jose
 * 
 * TIMER1 -> TEMPORIZADOR DE 16 BITS
 * Created on 22 de abril de 2021, 04:08 PM
 */


#include <xc.h>
#include "config.h"

/*Declaracion de Funciones*/

void TIMER1_Config(void);
uint16_t count;
void main(void) {
    /**/
    TRISFbits.TRISF1=0;
    ANSELFbits.ANSELF1=0;
    LATFbits.LATF1=0;
    
    TIMER1_Config();
    while(1){
        count=(TMR1H<<8)+TMR1L;
        if(count==65535){
            TMR1H=0X0B;
            TMR1L=0XDC;
            LATFbits.LATF1^=(1<<0);
        }
    }
    return;
}

void TIMER1_Config(void)
{
    /*Registro T1CON*/
    T1CONbits.CKPS=0b11;           //Temporizador de entrada Reloj Selección de preescalador 1:8
    T1CONbits.RD16=1;              // Modo 16 bits
    T1CONbits.ON=1;                //Enables Timer
    T1CONbits.NOT_SYNC=1;
    
    /*Registro T1GCON*/
    T1GCONbits.GTM=0;           //El modo Timer Gate Toggle está deshabilitado y Toggle flip-flop está desactivado
    
    /*Registro T1CLK*/
    T1CLKbits.CS=0b0010;        //Selección de la fuente del reloj del temporizador
    /*Deshabilitar Interrupciones*/
    INTCON0bits.GIE=0;
    TMR1H=0X0B;
    TMR1L=0XDC;
}
