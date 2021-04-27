//temporizador de 8 bits TMR0 500ms


#include <xc.h>
#include <pic18f57q43.h>
#define _XTAL_FREQ 4000000

void TIMER_config(void);
void OSC_config(void);
uint8_t contador = 0;
void main(void) {
    ANSELB = 0;
    TRISB = 0;
    LATB = 0;
    OSC_config();
    TIMER_config();
    while(1){
        contador = TMR0L;  
        if(contador == 255){
            TMR0L = 0xC3;
            LATBbits.LATB0 ^=(1<<0);
        }
    }
    
    
    return;
}

void TIMER_config(void){
    T0CON0bits.EN = 1; //The module is enabled and operating
    T0CON0bits.MD16 = 0; //TMR0 is a 8-bit timer
    T0CON0bits.OUTPS = 0b0000; //1:1 Postscaler
    T0CON1bits.CS = 0b010; //FOSC/4
    T0CON1bits.ASYNC = 1; // The input to the TMR0 counter is not synchronized to system clocks
    T0CON1bits.CKPS = 0b1101;// 1:8192
    TMR0L = 0xC3;
    
}


void OSC_config(void)
{     OSCCON1bits.NOSC = 0b110; //SE DEFINE EL HFINTOSC
      OSCFRQbits.HFFRQ = 0b0010;// FOSC 4 MHZ
      OSCCON1bits.NDIV = 0b0000; //DIVISOR 1
}
