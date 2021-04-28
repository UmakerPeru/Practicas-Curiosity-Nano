/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 27 de abril de 2021, 07:08 PM
 */


#include <xc.h>
#include "config.h"

//Declaracion de funciones
void configPuertos(void);

void main(void) {
    configPuertos();
    while (1) {
        if (PORTDbits.RD3 == 0) {
            while (PORTDbits.RD3 == 0) {
                LATDbits.LATD2 = 1;   
            }
            __delay_ms(2000);
            LATDbits.LATD2 = 0;
        }
        LATDbits.LATD0 = 1;
        __delay_ms(2000);
        LATDbits.LATD0 = 0;
        if (PORTDbits.RD3 == 0) {
            while (PORTDbits.RD3 == 0) {
                LATDbits.LATD2 = 1;   
            }
            __delay_ms(2000);
            LATDbits.LATD2 = 0;
        }
        LATDbits.LATD1 = 1;
        __delay_ms(2000);
        LATDbits.LATD1 = 0;
        if (PORTDbits.RD3 == 0) {
            while (PORTDbits.RD3 == 0) {
                LATDbits.LATD2 = 1;   
            }
            __delay_ms(2000);
            LATDbits.LATD2 = 0;
        }
        LATDbits.LATD2 = 1;
        __delay_ms(2000);
        LATDbits.LATD2 = 0;

    }
    return;
}

void configPuertos() {
    PORTD = 0x00;
    LATD = 0x00;
    ANSELD = 0x00;
    TRISD = 0x08; //Definicion de pin de entrada y pines de salida
}
