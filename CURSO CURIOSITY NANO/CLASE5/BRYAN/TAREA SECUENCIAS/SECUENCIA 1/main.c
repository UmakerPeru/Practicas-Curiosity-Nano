/* 
 * File:   main.c
 * Author: Bryan
 *
 * Created on April 14, 2021, 11:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "reloj.h"

/*
 * 
 */

/*Declaracion de funciones*/
void configuracionPuertos(void);
void secuenciaArribaAbajo(void);
void secuenciaAbajoArriba(void);

/*Se utilizo un arreglo para escoger el numero que se desea colocar en el
 puerto F*/
uint8_t arreglo[8] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};

int main(int argc, char** argv) {
    configuracionPuertos();
    while(1){
        secuenciaArribaAbajo();
        secuenciaAbajoArriba();
    }
    return (EXIT_SUCCESS);
}

void configuracionPuertos(){
    /*Configuracion de puerto F como salida digital*/
    PORTF = 0x00;
    LATF = 0x00;
    ANSELF = 0x00;
    TRISF = 0x00;
}

void secuenciaArribaAbajo(){
    /*Bucle for para escoger los numeros del arreglo de manera ascendente*/
    for(int i = 0; i < 7; i++){
        LATF = arreglo[i];
        __delay_ms(200);
    }
}


void secuenciaAbajoArriba(){
    /*Bucle for para escoger los numeros del arreglo de manera descendente*/
    for(int j = 7; j > 0; j--){
        LATF = arreglo[j];
        __delay_ms(200);
    }
}

