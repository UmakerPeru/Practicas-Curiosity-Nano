/*
 * File:   main.c
 * Author: Jose
 *
 * TIMER0 -> TEMPORIZADOR DE 8 BITS
 * 
 * Created on 21 de abril de 2021, 10:53 PM
 */


#include <xc.h>
#include "config.h"
#include <stdio.h>
#include <stdlib.h>

/*Declaracion de Funciones*/
void TIMER0_Config(void);

uint8_t count;
void main(void) {
    ANSELF=0;
    TRISF=0;
    LATF=0;
    TIMER0_Config();
    
    while(1){
        count=TMR0L;
        if(count==255){
            TMR0L=0XE1;
            LATF ^=(1<<0) ;   
        }
    }
    return;
}


void TIMER0_Config(void){
    
    /*Registro T0CON0*/
    T0CON0bits.EN=1;
    T0CON0bits.MD16=0;
    T0CON0bits.OUTPS=0b0000;
    
    /*Registro T0CON1*/
    T0CON1bits.CS=0b010;
    T0CON1bits.ASYNC=1;
    T0CON1bits.CKPS=0b1100;         //Prescaler 1:4096    
    TMR0L=0XE1;                     //500 ms
}
