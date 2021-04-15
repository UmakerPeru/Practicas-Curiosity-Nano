

#include <xc.h>
#include "config.h"
#include "reloj.h"

char arreglo[8]={1,2,4,8,16,32,64,128};
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
    for(i=0;i<8;i++){
        LATC=arreglo[i];
        __delay_ms(500);
    }
    for(i=6;i>0;i--){
        LATC=arreglo[i];
        __delay_ms(500);
    }
}
