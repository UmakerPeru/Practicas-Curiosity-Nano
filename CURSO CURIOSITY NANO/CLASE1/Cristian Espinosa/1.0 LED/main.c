#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 1000000


void main(void) {
    
    /* CONFIGURACIÓN --> PIN RF3 -> Salida Digital 
    TRISFbits.TRISF3 = 0; 
    
    /* INGRESAR AL BUCLE INFINITO */
    while (1){
        /* Prender LED (RF03)*/
        LATFbits.LATF3=0;
        __delay_ms(1000); // Retardo - DELAY
        /* Apagar LED (RF03)*/
        LATFbits.LATF3=1;
        __delay_ms(1000);

    }

    return;
}
