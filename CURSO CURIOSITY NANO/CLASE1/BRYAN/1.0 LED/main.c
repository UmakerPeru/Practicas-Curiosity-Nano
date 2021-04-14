/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 13 de abril de 2021, 07:06 PM
 */


#include <xc.h>
#include "config.h"
#include "reloj.h"

void configuracionPuertos(void);
void parpadeoLed(void);

void main(void) {
    configuracionPuertos();
    while(1){
        parpadeoLed();
    }
    return;
}

void configuracionPuertos(){
    TRISFbits.TRISF3=0;
}

void parpadeoLed(){
    LATFbits.LATF3=0;
    __delay_ms(1000);
    LATFbits.LATF3=1;
    __delay_ms(1000);
}

