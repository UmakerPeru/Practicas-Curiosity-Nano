

#include <xc.h>
#include "config.h"
#include "reloj.h"

char arreglo[4]={0b10000001,0b01000010,0b00100100,0b00011000};
void ConfigPuerto(void);
void secuencia(void);

void main(void) {
    ConfigPuerto();
    
    while(1){
    secuencia(); 
    }
    return;
}

void ConfigPuerto(){
    ANSELF=0;
    TRISC=0;
    LATC=0;
}

void secuencia(void){
    int i;
    for(i=0;i<4;i++){
        LATC=arreglo[i];
        __delay_ms(500);
    }
    for(i=2;i>0;i--){
        LATC=arreglo[i];
        __delay_ms(500);
    }
}
