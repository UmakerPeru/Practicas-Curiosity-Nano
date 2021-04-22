/*
 * File:   main.c
 * Author: Jose
 *
 * Created on 22 de abril de 2021, 04:33 PM
 */

#include <xc.h>
#include "config.h"

/*Declaracion de Funciones*/

void TIMER1_Config(void);
void Config_Interrupt_TMR1(void);
void Config_Global_Interrupt(void);

void main(void) {
    /**/
    TRISFbits.TRISF1=0;
    ANSELFbits.ANSELF1=0;
    LATFbits.LATF1=0;
    
    TRISFbits.TRISF2=0;
    ANSELFbits.ANSELF2=0;
    
    TIMER1_Config();
    Config_Global_Interrupt();
    Config_Interrupt_TMR1();
    while(1){
        __delay_ms(125);
        LATFbits.LATF2^=(1<<0);
        
        
    }
    return;
}

void TIMER1_Config(void)
{
    /*Registro T1CON*/
    T1CONbits.CKPS=0b11;           //Temporizador de entrada Reloj Selección de preescalador 1:8
    T1CONbits.RD16=1;              // Modo 16 bits
    T1CONbits.ON=1;                //Enables Timer
    T1CONbits.NOT_SYNC=1;
    
    /*Registro T1GCON*/
    T1GCONbits.GTM=0;           //El modo Timer Gate Toggle está deshabilitado y Toggle flip-flop está desactivado
    
    /*Registro T1CLK*/
    T1CLKbits.CS=0b0010;        //Selección de la fuente del reloj del temporizador
    /*125 ms*/
    TMR1H=0XB;
    TMR1L=0XDC;
}

void __interrupt (irq(IRQ_TMR1),base(0X4008)) TMR1_ISR(void){
  
    if(PIR3bits.TMR1IF==1)
    {
        LATFbits.LATF1 ^=(1<<0);
        TMR1H=0X0B;
        TMR1L=0XDC;
        PIR3bits.TMR1IF=0;
    }
    
}

void Config_Global_Interrupt(void){
    INTCON0bits.IPEN=0;
    INTCON0bits.GIE=1;  
}

void Config_Interrupt_TMR1(void)
{
    PIE3bits.TMR1IE=1;
    PIR3bits.TMR1IF=1;
}
