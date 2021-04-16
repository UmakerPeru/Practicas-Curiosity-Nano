/* 
 * File:   main.c
 * Author: Usuario
 *
 * Created on 15 de abril de 2021, 07:00 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f57q43.h>
#define _XTAL_FREQ 4000000UL
//Prototipo de funciones
void OSC_config(void);

int main(int argc, char** argv) {
    OSC_config();
    ANSELF = 0;
    TRISF = 0;
    LATF = 0;
  
    ANSELA = 0;
    TRISA = 0;
    LATA = 0;   
    //Resistencias pull up
    ANSELB = 0;
    TRISB = 0b00000001;
    
    INTCON0 = 0b10000000;//habilitado las interrupciones
    PIE1 = 1;//definido interrupcion externa
    PIR1bits.INT0IF = 0;//Limpia la bandera
    while(1)
    {
        RF3 = 1;
        RF2 = 0;
        __delay_ms(1000);
        RF3 = 0;
        RF2 = 1;
        __delay_ms(1000);
    }
    return (EXIT_SUCCESS);
}
void OSC_config(void)
{ OSCCON1bits.NOSC = 0b110;
  OSCCON1bits.NDIV = 0b0000;
  OSCFRQbits.HFFRQ = 0b0010;
}
void __interrupt (irq(default), base(0x3008)) DEFAULT_ISR(void)
{ LATA = 0b11111111;
  __delay_ms(2000);
  PIR1bits.INT0IF = 0;
}
