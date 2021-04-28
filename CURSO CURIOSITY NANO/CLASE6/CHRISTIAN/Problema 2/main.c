#include "config.h"
#include "reloj.h"
#include <xc.h>

void OSC_config(void);

void main(void) {
    void config_global_interrupt(void);
    void config_interrupt_TMR1(void);
    
    TRISFbits.TRISF3=0;
    TRISFbits.TRISF1=0;
    TRISFbits.TRISF2=0;
    
    TRISBbits.TRISB4=1;
    WPUBbits.WPUB4=1;
    ANSELBbits.ANSELB4=0;
    while(1){
        LATFbits.LATF1=1;
        if (PORTBbits.RB4==0){
            __delay_ms(90);
            while (PORTBbits.RB4==0){
            LATFbits.LATF1=1;
            LATFbits.LATF3=0;
            LATFbits.LATF2=0;
            }
            
        }
        __delay_ms(2000);
        LATFbits.LATF1=0;
        
        
        
        LATFbits.LATF2=1;
        if (PORTBbits.RB4==0){
            __delay_ms(90);
            while (PORTBbits.RB4==0){
            LATFbits.LATF1=1;
            LATFbits.LATF3=0;
            LATFbits.LATF2=0;
            }
            
        }
        __delay_ms(2000);
        LATFbits.LATF2=0;
        
        
        
        LATFbits.LATF3=1;
        if (PORTBbits.RB4==0){
            __delay_ms(90);
            while (PORTBbits.RB4==0){
            LATFbits.LATF1=1;
            LATFbits.LATF3=0;
            LATFbits.LATF2=0;
            }
            
        }
        __delay_ms(2000);
        LATFbits.LATF3=0; 
    }
   
    
    return;
}

void __interrupt (irq(default), base(0x3008)) DEFAULT_ISR(void){ 
    LATB = 0b11111111;
    __delay_ms(2000);
    TMR0H = 0x0B;
    TMR0L = 0xDC;
    PIR1bits.INT0IF = 0;
}
void config_global_interrupt(){
    INTCON0bits.IPEN = 0;
    INTCON0bits.GIE = 1;
}
void config_interrupt_TMR1(){
    PIE3bits.TMR1IE = 1; 
    PIR3bits.TMR1IF = 1; 
}
