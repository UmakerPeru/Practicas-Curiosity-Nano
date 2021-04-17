/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 16 de abril de 2021, 08:25 PM
 */


#include <xc.h>
#include "config.h"
#include "reloj.h"

void configPuertos(void);
void configTimer1(void);

void main(void) {
    configPuertos();
    configTimer1();
    while(1){
        LATF = TMR1L; //Puerto de salida del TIMER1
        __delay_ms(500);
        if(TMR1L == 15){
            TMR1L = 0;
        }
    }
    return;
}

void configTimer1(){
    //T1CON
    T1CONbits.ON = 1; //Activa el TIMER1
    T1CONbits.CKPS = 0b00; //Activa un prescaler 1:1
    T1CONbits.NOT_SYNC = 1; //La entrada de reloj externo no esta sincronizada
    T1CONbits.RD16 = 0; //La lectura/escritura se realizara en dos operaciones de 8 bits

    //T1GCON
    T1GCONbits.GE = 0; //Deshailitar GATE del TIMER1
    T1GCONbits.GTM = 0;

    //T1CLK
    T1CLKbits.CS = 0b00000;

    //Inhabilitacion de interrupcion
    INTCON0bits.GIE = 0;
}

void configPuertos(){
    //Puerto de salida
    PORTF = 0;
    LATF = 0;
    ANSELF = 0;
    TRISF = 0;
    //Puerto de entrada
    ANSELC = 0; //Puerto de entrada para interrupcion de TIMER1
}
