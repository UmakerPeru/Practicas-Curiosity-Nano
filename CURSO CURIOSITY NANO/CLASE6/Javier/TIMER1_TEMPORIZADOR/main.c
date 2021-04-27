//TEMPORIZADOR CON TIMER1 16bits


#include <xc.h>
#include <pic18f57q43.h>
#define _XTAL_FREQ 4000000

void TIMER_config(void);
void OSC_config(void);
uint16_t contador = 0;
void main(void) {
    ANSELB = 0;
    TRISB = 0;
    LATB = 0;
    OSC_config();
    TIMER_config();
    while(1){
        contador = (TMR0H<<8)+TMR0L;  
        if(contador == 65535){
            TMR1H = 0x0B;
            TMR1L = 0xDC;
            LATBbits.LATB0 ^=(1<<0);
        }
    }
    
    
    return;
}

void TIMER_config(void){
    T1CONbits.ON = 1; //The module is enabled and operating
    T1GCONbits.GE = 0;	
    T1CONbits.RD16 = 1; //TMR0 is a 16-bit timer
    T1CLKbits.CS = 0b00001; //FOSC/4
    T1CONbits.CKPS = 0b11;// 1:8
    TMR1H = 0x0B;
    TMR1L = 0xDC;
    
}


void OSC_config(void)
{     OSCCON1bits.NOSC = 0b110; //SE DEFINE EL HFINTOSC
      OSCFRQbits.HFFRQ = 0b0010;// FOSC 4 MHZ
      OSCCON1bits.NDIV = 0b0000; //DIVISOR 1
}
