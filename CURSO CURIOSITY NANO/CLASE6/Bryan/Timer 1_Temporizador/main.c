/* 
 * File:   main.c
 * Author: Bryan
 *
 * Created on 22 de abril de 2021, 12:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000 //Sirve para utilizar la funcion __delay_ms()

void configPuertos(void);
void configTimer1(void);

uint16_t contador = 0;
/*
 * 
 */

int main(int argc, char** argv) {
    configPuertos();
    configTimer1();
    while(1){
        contador = (TMR1H << 8) + TMR1L;
        if(contador == 65535){
            TMR1H = 0x0B;
            TMR1L = 0xDC;
            LATFbits.LATF1 ^= (1 << 0);
        }
    }
    return (EXIT_SUCCESS);
}

void configTimer1(){
    //T1CON
    T1CONbits.ON = 1; //Activa el TIMER1
    T1CONbits.CKPS = 0b11; //Activa un prescaler 1:8
    T1CONbits.NOT_SYNC= 1; //La entrada de reloj externo no esta sincronizada
    T1CONbits.RD16 = 1; //La lectura/escritura se realizara en dos operaciones de 8 bits

    //T1GCON
    T1GCONbits.GE = 0; //Deshabilitar GATE del TIMER1
    T1GCONbits.GTM = 0;
    T1GCONbits.GPOL = 1;
    T1GCONbits.GSPM = 1;
    
    //T1CLK
    T1CLKbits.CS = 0b00010;

    //Inhabilitacion de interrupcion
    INTCON0bits.GIE = 0;
    INTCON0bits.IPEN = 0;
    
    //3036: valor de TMR1 calculado para temporizador de 0.5s, 0X0BDC
    TMR1H = 0x0B;
    TMR1L = 0xDC;
}

void configPuertos(){
    //Puerto de salida
    PORTF = 0;
    LATF = 0;
    ANSELF = 0;
    TRISF = 0;
}
