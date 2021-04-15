/* Librerias de configuracion */

#include <xc.h>
#include "config.h"
#include "reloj.h"

/* Configuracion de Puertos -> Leds */
void configuracionPorts (void);

/* Funciones de asignacion -> Arreglos*/

void encenderLed (int);
void apagarLed (int);


void main(void) {
    
    // Invocacion de la Funcion de Configuracion //
    configuracionPorts();
    
    /* Variable interna -> CONTADOR EN EL ARREGLO DE LEDS*/
    int i=0;
    
    // Inicio del Bucle Infinito
    while (1){
        /* 1ª Ciclo For -> Encendido y apagado de leds: Derecha -> Izquierda*/
        /* RF0 -> RF1 -> RF2 -> RF3 -> RF4 -> RF5 -> RF6 -> RF7 */
        for(i=0;i<8;i++){
            encenderLed(i);
            __delay_ms(250);
            apagarLed(i);
        }
        
        /* 2ª Ciclo For -> Encendido y apagado de leds (Retorno): Izquierda -> Derecha*/
        /* Para evitar repetitividad, se encienden solo LEDS INTERMEDIOS
          RF1 <- RF2 <- RF3 <- RF4 <- RF5 <- RF6 */  
        for(i=6;i>0;i--){ 
            encenderLed(i);
            __delay_ms(250);
            apagarLed(i);
        }
    }

    return;
}

void configuracionPorts (void){
    
    /* Configuracion de Puertos --> RF -> SALIDAS DIGITALES */
    TRISF = 0;
    
}

void encenderLed (int i){
    switch (i){
        case 0:
            LATFbits.LATF0 = 1;
            break;
        case 1:
            LATFbits.LATF1 = 1;
            break;
        case 2:
            LATFbits.LATF2 = 1;
            break;
        case 3:
            LATFbits.LATF3 = 1;
            break;
        case 4:
            LATFbits.LATF4 = 1;
            break;
        case 5:
            LATFbits.LATF5 = 1;
            break;
        case 6:
            LATFbits.LATF6 = 1;
            break;
        case 7:
            LATFbits.LATF7 = 1;
            break;
    }
}


void apagarLed (int i){
    switch (i){
        case 0:
            LATFbits.LATF0 = 0;
            break;
        case 1:
            LATFbits.LATF1 = 0;
            break;
        case 2:
            LATFbits.LATF2 = 0;
            break;
        case 3:
            LATFbits.LATF3 = 0;
            break;
        case 4:
            LATFbits.LATF4 = 0;
            break;
        case 5:
            LATFbits.LATF5 = 0;
            break;
        case 6:
            LATFbits.LATF6 = 0;
            break;
        case 7:
            LATFbits.LATF7 = 0;
            break;
    }
}
