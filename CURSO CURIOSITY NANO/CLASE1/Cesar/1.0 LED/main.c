
#include <xc.h>
#include "config.h"
#include "reloj.h"

void main(void) 
{
    /*CONFIGURACIÓN RF3 EN SALIDA*/
    TRISFbits.TRISF3=0; // TRISC &=~(1);
    /*INGRESAR A BUCLE INFINITO*/
    
    while(1)
    {
        LATFbits.LATF3=1;
        __delay_ms(2000);
        LATFbits.LATF3=0;
        __delay_ms(2000);
    }
    return;
}
