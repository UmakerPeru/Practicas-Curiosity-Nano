
#include <xc.h>
#include "config.h"
#include "reloj.h"

void main(void) 
{
    TRISD = 0x00; //inicializo todo el puerto D como salida
    LATD = 0x00; //0b00000000
    unsigned char i; // referencia a una variable de 8 bits que no tiene signo, tambien puede ser int 
    while(1)
    {
        for(i=0; i<8; i++)
        {
           __delay_ms(100);
           LATD = 0x01 << i;
           __delay_ms(100);
        }
        // 0x20 = 0010 0000 
        // 0x40 = 0100 0000
        // 0x80 = 1000 0000
        
        if(LATDbits.LATD7 == 1)
        {
            for(i=0; i<6; i++)
            {
            __delay_ms(100);
             LATD = 0x40 >> i;
            __delay_ms(100);
            }
            
            // 0x80 = 1000 0000
            // 0x40 = 0100 0000
            // 0x20 = 0010 0000
            // 0x10 = 0001 0000
        }
    }
    
    return;
}

