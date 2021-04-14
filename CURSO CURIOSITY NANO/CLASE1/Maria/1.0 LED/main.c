#include <xc.h>
#include "config.h"

void main(void) 
{
   
    TRISFbits.TRISF3=0;
    LATFbits.LATF3=0;
    while (1)
    {
        LATFbits.LATF3=1;
       __delay_ms(200);
       LATFbits.LATF3=0;
       __delay_ms(1000);
    }
         
    return;
}
