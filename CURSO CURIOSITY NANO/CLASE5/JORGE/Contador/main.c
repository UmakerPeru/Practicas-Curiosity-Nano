#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h" // Configuracion de Perifericos
#include "reloj.h"

void configuracionTIMER (void);
void configuracionPIN (void);

void main(int argc, char ** argv) {
    
    configuracionTIMER();
    configuracionPIN();
    
    TMR0L = 0;
    while (1){
        LATF = TMR0L;
        __delay_ms(500);
        if (TMR0L == 15){
            TMR0L = 0;
        }
    }
    
    return;
}

void configuracionTIMER (void){
    
    // CONF TIMER0 CONTADOR
    
   
    T0CON0bits.EN = 1;
    T0CON0bits.MD16 = 0;
    T0CON0bits.OUTPS = 0000;
    
    T0CON1bits.CS = 000;
    T0CON1bits.CKPS = 0000;
    T0CON1bits.ASYNC = 0;
            
    INTCON0bits.GIE = 0;
    
    return;
    
}

void configuracionPIN (void){
    
    //LEDS
    
    PORTF=0;
    LATF=0;
    ANSELF=0;
    TRISF=0;
    
    // PULSADOR - SIN PULL UP
    
    ANSELA = 0;
    
    return ;
}
