//INTERRUPCION CON TIMER1


#include <xc.h>
#include <pic18f57q43.h>
#define _XTAL_FREQ 4000000

void TIMER_config(void);
void OSC_config(void);
void config_global_interrupt(void);
void config_interrupt_TMR0(void);

uint16_t contador = 0;
void main(void) {
    ANSELB = 0;
    TRISB = 0;
    LATB = 0;
    ANSELF = 0;
    TRISF = 0;
    LATF = 0;
    OSC_config();
    TIMER_config();
    config_global_interrupt();
    config_interrupt_TMR0();
    
    while(1){
        LATFbits.LATF3 ^=(1<<0);
        __delay_ms(500);

        }
    return;
}

void TIMER_config(void){
    T1CONbits.ON = 1; //The module is enabled and operating
    T1GCONbits.GE = 0;	
    T1CONbits.RD16 = 1; //TMR1 is a 16-bit timer
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

void __interrupt(irq(IRQ_TMR1), base(0x3008)) TMR1_ISR(void)
{
if(PIR3bits.TMR1IF==1)
{
LATBbits.LATB0 ^=(1<<0);
TMR0L = 0xDC;
TMR0H =0x0B;
PIR3bits.TMR1IF=0;
}
}


void config_global_interrupt(void)
{
INTCON0bits.IPEN = 0;
INTCON0bits.GIE = 1;

}

void config_interrupt_TMR0(void)
{
PIE3bits.TMR1IE = 1;	
PIR3bits.TMR1IF = 0;
}
