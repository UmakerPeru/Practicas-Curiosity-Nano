/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 27 de abril de 2021, 05:43 PM
 */


#include <xc.h>
#include "config.h"

void TIMER_config(void);

uint16_t contador = 0;

void main(void) {
    ANSELF = 0;
    TRISF = 0;
    LATF = 0;
    TIMER_config();
    while(1){
        contador = TMR0L;
        if(contador == 255){
            TMR0L = 0xB;
            LATFbits.LATF3 ^= (1 << 0);
        }
    }
    return;
}

void TIMER_config(void){
    //TIMER 0
    //CON 0
    T0CON0bits.EN = 1; //Habilitar el timer 0
    T0CON0bits.MD16 = 0; //Habilitar modo de 8 bits
    T0CON0bits.OUTPS = 0b0000; //Colocar un valor de postcaler (1:1)
    //CON 1
    T0CON1bits.CS = 0b010; //Frecuencia de reloj del timer 0 (Fosc/4)
    T0CON1bits.ASYNC = 1; //Habilitar asincrono
    T0CON1bits.CKPS = 0b1001; //Seleccionar prescaler 1:512
    //60: valor de TMR0 calculado para temporizador de 0.5s, 0X3C
    TMR0L = 0xB;
}
