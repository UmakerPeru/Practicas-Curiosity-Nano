/*
 * File:   main.c
 * Author: USUARIO1
 *
 * Created on 20 de febrero de 2021, 01:19 PM
 */


#include <xc.h>
/*Librerias e inclusiones*/
#include "config.h"
#define _XTAL_FREQ 8000000
/*Variables globales*/

/*Declaracion de funciones*/
int main(void) {
    OSCCON = 0X72;
    TRISD = 0;
    

    while(1){
        LATD = 1;
	__delay_ms(200);
	LATD = 0;
	__delay_ms(200);
    }
    return 0;
}
