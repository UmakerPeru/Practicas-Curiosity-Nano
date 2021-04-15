/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 15 de abril de 2021, 12:32 PM
 */


#include <xc.h>
#include "config.h"
void main(void) {
    /*Puerto F como salida*/
    TRISF=0;
    
    while(1){
        /*Bucle de Iteracion*/
        /*c -> constante para la manipulacion de bits*/
        int c=0;
        for(int c=0;c<8;c++){
            __delay_ms(100);
            LATF=0;
            LATF |=(1<<c);
            if(c==7){
                for (int cn=7;cn>=0;cn--){
                    __delay_ms(100);
                    LATF=0;
                    LATF |=(1<<cn);
                }
            }
            
        }
       
    }
    return;
}
