#include <xc.h>
#include "config.h"
#include "reloj.h"

void main(void) {
    
    TRISFbits.TRISF3=0;
    
    LATFbits.LATF3=1;
    __delay_ms(1000);
    LATFbits.LATF3=0;
    __delay_ms(1000);
    return;
}
