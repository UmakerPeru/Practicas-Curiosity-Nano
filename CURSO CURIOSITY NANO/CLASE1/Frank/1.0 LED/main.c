#include <xc.h>
#include "config.h"
#include "reloj.h"
void main(void)  {
    /*CONFIGURACIÓN RC0 EN SALIDA */
    TRISFbits.TRISF3 = 0;//TRISC &=~(1);
   /*RF1 EN MODO DIGITAL*/
    ANSELBbits.ANSELB4 = 0;
     /*CONFIGURACIÓN RF1 EN MODO ENTRADA*/
    TRISBbits.TRISB4 = 1;
    /*ACTIVAR RESISTENCIA INTERNA PULL-UP EN EL PIN RB4*/
    WPUBbits.WPUB4 = 1;
    /*INGRESAR A BUCLE INFINITO*/
    while(1) {
        if(PORTBbits.RB4 == 0) {
            /*flanco de bajda (presionado)*/ 
            __delay_ms(90);
            /*¿SIGUE PRESIONADO?*/
            while(PORTBbits.RB4==0);
   
            /*PRENDER LED (RCO)*/
            LATFbits.LATF3=1;
             __delay_ms(2000);
            LATFbits.LATF3=0;
        }
    }
    return;
}
