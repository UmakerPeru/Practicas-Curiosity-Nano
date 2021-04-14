/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 13 de abril de 2021, 06:10 PM
 */


#include <xc.h>
#include "config.h"

/*-----BLINK-----*/
#define LED TRISDbits.TRISD0
#define LED_SWITCH LATDbits.LATD0
void main(void) {
    LED=0;                  //SALIDA
    
    while(1){
        
        LED_SWITCH=1;       //ENCENDIDO DEL LED
        __delay_ms(4000);
        LED_SWITCH=0;       //APAGADO DEL LED
        __delay_ms(4000);
    }
    return;
}
