#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h" // Configuracion de Perifericos
#include "reloj.h"

void configuracion (void);

void main(int argc, char ** argv) {
    
    configuracion();
    
    TMR0L = 0;
    while (1){
        LATF = TMR0L;
        __delay_ms(150);
        if (TMR0L == 15){
            TMR0L = 0;
        }
    }
    
    return;
}

void configuracion (void){
    
    // CONF TIMER0 CONTADOR
    
    ANSELA = 0;
    T0CON0bits.EN = 1;
    T0CON0bits.MD16 = 0;
    T0CON0bits.OUTPS = 0000;
    
    T0CON1bits.CS = 000;
    T0CON1bits.CKPS = 0000;
    T0CON1bits.ASYNC = 0;
            
    INTCON0bits.GIE = 0;
    
    //LEDS
    
    ANSELF = 0;
    TRISF = 0;
    
}
