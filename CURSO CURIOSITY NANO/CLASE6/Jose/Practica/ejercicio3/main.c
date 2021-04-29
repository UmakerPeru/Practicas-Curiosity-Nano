/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 27 de abril de 2021, 10:10 PM
 */


#include <xc.h>
#include "config.h"

void main(void) {
    TRISF=0;
    ANSELF=0;
    LATF=0;
    /*Canal 0*/
    ADPCH=0X00;
    /*Referencia Negativa*/
    ADREFbits.NREF=0;
    /*Referencia Positiva*/
    ADREFbits.PREF=0b00;
    /*Reloj de Conversion*/
    ADCON0bits.CS=1;
    /*Formato de salida ADRES izquierda*/
    ADCON0bits.FM=0;
    /*Habilitacion del ADC*/
    ADCON0bits.ON=1;
    __delay_ms(100);
    while(1){
        /*Inicia la Conversion*/
        ADCON0bits.GO=1;
        
        if(ADRESH>500){
            LATFbits.LATF0=1;
            LATFbits.LATF1=1;
            LATFbits.LATF2=1;
        }
        else if(ADRESH>200){
            LATFbits.LATF0=1;
            LATFbits.LATF1=1;
            LATFbits.LATF2=0;
        }
        else if(ADRESH>100){
            LATFbits.LATF0=1;
            LATFbits.LATF1=0;
            LATFbits.LATF2=0;
        }
        else{
            LATFbits.LATF0=0;
            LATFbits.LATF1=0;
            LATFbits.LATF2=0;
        }
        
    }
    
    
    
    return;
}
