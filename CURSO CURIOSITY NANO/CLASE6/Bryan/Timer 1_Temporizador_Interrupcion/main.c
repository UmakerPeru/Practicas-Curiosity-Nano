/*
 * File:   main.c
 * Author: Bryan
 *
 * Created on 27 de abril de 2021, 04:48 PM
 */


#include <xc.h>
#include "config.h"

//Prototipos de funcion
void TIMER1_config(void);
void config_global_interrupt(void);
void config_interrupt_TMR1(void);

void main(void) {
    ANSELF = 0;
    TRISF = 0;
    LATF = 0;
    TIMER1_config();
    config_global_interrupt();
    config_interrupt_TMR1();
    while(1){
        LATFbits.LATF2 ^= (1 << 0);
        __delay_ms(500);
    }
    return;
}

void TIMER1_config(void){
    //T1CON
    T1CONbits.ON = 1; //Activa el TIMER1
    T1CONbits.CKPS = 0b11; //Activa un prescaler 1:8
    T1CONbits.NOT_SYNC= 1; //La entrada de reloj externo no esta sincronizada
    T1CONbits.RD16 = 1; //La lectura/escritura se realizara en dos operaciones de 8 bits

    //T1GCON
    T1GCONbits.GE = 0; //Deshabilitar GATE del TIMER1
    T1GCONbits.GTM = 0;
    T1GCONbits.GPOL = 1;
    T1GCONbits.GSPM = 1;
    
    //T1CLK
    T1CLKbits.CS = 0b00010;
    
    //3036: valor de TMR1 calculado para temporizador de 0.5s, 0X0BDC
    TMR1H = 0x0B;
    TMR1L = 0xDC;
}

void __interrupt(irq(IRQ_TMR1),base(0x3008)) TMR1_ISR(void){
    if(PIR3bits.TMR1IF == 1){
        LATFbits.LATF3 ^= (1 << 0);
        TMR0H = 0x0B;
        TMR0L = 0xDC;
        PIR3bits.TMR1IF = 0;
    }
}

void config_global_interrupt(){
    INTCON0bits.IPEN = 0;
    INTCON0bits.GIE = 1;
}

void config_interrupt_TMR1(){
    PIE3bits.TMR1IE = 1; //Habilita la interrupcion
    PIR3bits.TMR1IF = 1; //Inicio limpiando el flag
}

