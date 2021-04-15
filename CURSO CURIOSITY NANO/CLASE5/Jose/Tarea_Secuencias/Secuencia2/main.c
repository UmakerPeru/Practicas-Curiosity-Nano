/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 15 de abril de 2021, 04:11 PM
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
        int cr=7;
        
        for(int c=0;c<4;c++){
            __delay_ms(100);
            LATF=0;
            
            LATF |=(1<<c)|(1<<cr);
            cr--;
            if(c==3){
                for (int cn=3;cn>=0;cn--){
                    __delay_ms(100);
                    
                    LATF=0;     
                    LATF |=(1<<cn)|(1<<cr);
                    cr++;
                }
            }
            
        }
       
    }
    return;
}
