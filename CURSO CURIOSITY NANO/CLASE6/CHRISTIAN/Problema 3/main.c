

#include <xc.h>
#include "config.h"
#include "reloj.h"

void main(void) {
    TRISF=0;
    ADPCH=0x00;
    ADREFbits.NREF=0;
    ADREFbits.PREF=0b00;
    ADCON0bits.CS=1;
    ADCON0bits.FM=0;
    ADCON0bits.ON=1;
    __delay_ms(100);
    while(1){
        ADCON0bits.GO=1;
        while(ADCON0bits.GO);
        if(ADRES < 200){
            LATFbits.LATF1=1;
            LATFbits.LATF2=0;
            LATFbits.LATF3=0;
        }
        if(ADRES > 200 && ADRES < 500){
            LATFbits.LATF1=0;
            LATFbits.LATF2=1;
            LATFbits.LATF3=0;
        }
        if(ADRES > 500){
            LATFbits.LATF1=0;
            LATFbits.LATF2=0;
            LATFbits.LATF3=1;
        }
        __delay_ms(1000);
    }
    return;
}
