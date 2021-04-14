// LED INTERNO DEL PIC NANO - INTERMITENTE - 2SEG // 

#include <xc.h>
#include "config.h"
#include "reloj.h"


void main(void) {
    
    /* CONFIGURACIÓN --> PIN RF3 -> Salida Digitale -> LED interno*/
    
    TRISFbits.TRISF3 = 0; 
    
    /* INGRESAR AL BUCLE INFINITO */
    while (1){
        /* Prender LED (RF03)*/
        LATFbits.LATF3=0;
        __delay_ms(2000); // Retardo - DELAY
        /* Apagar LED (RF03)*/
        LATFbits.LATF3=1;
        __delay_ms(2000);

    }

    return;
}
