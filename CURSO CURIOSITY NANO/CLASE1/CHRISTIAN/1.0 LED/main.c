#include <xc.h>
#include "config.h"
#include "RELOJ.h"

void main(void) {
    while(1){
        TRISCbits.TRISC1=0;
    
        LATFCits.LATC1=1;
        __delay_ms(1000);
        LATCbits.LATC1=0;
        __delay_ms(1000);
    }
    return;
            
}
