#include <xc.h>
#include "config.h"

void main(void) {
    PORTF=0;
    LATF=0;
    ANSELF=0;
    TRISF=0;
    
    ANSELC=0;
    INTCON0bits.GIE = 0;
    T1CONbits.ON =  1;
    T1CLKbits.CS = 0b00000;
    T1CONbits.CKPS = 0b00;
    T1GATEbits.GSS = 0b000000;
    
    T1GCONbits.GE = 0;
    T1CONbits.RD16 = 0;
    T1CONbits.NOT_SYNC = 0;

    TMR0L=0;
    while(1){
        LATF=TMR0L;
        __delay_ms(500);
        if(TMR0L==15){
            TMR0L=0;
        }
    }
    
    return;
}
