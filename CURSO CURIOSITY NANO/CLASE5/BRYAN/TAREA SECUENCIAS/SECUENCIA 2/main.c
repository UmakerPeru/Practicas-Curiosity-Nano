/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on April 15, 2021, 12:05 PM
 */


#include <xc.h>
#include "config.h"
#include "reloj.h"

/*Declaracion de funciones*/
void configuracionPuertos(void);
void secuenciaAfueraAdentro(void);
void secuenciaAdentroAfuera(void);

/*Se utilizo un arreglo que contiene numeros en hexadecimal que permitiran
 activar los pines del puerto F correspondientes*/
uint8_t arreglo[4] = {
    0x81, 0x42, 0x24, 0x18
};

void main(void) {
    configuracionPuertos();
    while(1){
        secuenciaArribaAbajo();
        secuenciaAbajoArriba();
    }
    return;
}

void configuracionPuertos(){
    /*Configuracion del puerto F como salida digital*/
    PORTF = 0x00;
    LATF = 0x00;
    ANSELF = 0x00;
    TRISF = 0x00;
}


void secuenciaAfueraAdentro(){
    /*Bucle for para escoger los pines que se activaran de afuera hacia 
     * adentro*/
    for(int i = 0; i < 3; i++){
        LATF = arreglo[i];
        __delay_ms(500);
    }
}


void secuenciaAdentroAfuera(){
    /*Bucle for para escoger los pines que se activaran de adentro hacia 
     * afuera*/
    for(int j = 3; j > 0; j--){
        LATF = arreglo[j];
        __delay_ms(500);
    }
}
