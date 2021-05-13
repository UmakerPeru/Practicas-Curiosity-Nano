/*
 * File:   main.c
 * Author: Jose
 *
 * Created on May 11, 2021, 1:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
/*Watchdog timer deshabilitado*/
#pragma config WDTE = OFF
#define _XTAL_FREQ 4000000

/*Prototipos de funciones*/
void UART1_Config(void);
void OSC_Config(void);
void ADC_Config(void);
void UART1_Write (uint8_t txData);
uint8_t UART1_Read(void);
void INTERRUPT_Initialize (void);
void INTERRUPT_UART1RX(void);
void HARDWARE_Init(void);
/*Variable  de lectura del canal analogico*/
uint16_t data;

void main(void) {
    /*Inicializacion de los perifericos*/
    HARDWARE_Init();
    ANSELF=0;       //Puerto F digital
    LATF=0;         //Salida en estado bajo
    TRISF=0;        //Configuracion como Salida
    RF0PPS=0X20;    //Rediccionamiento del Tx y Rx
    U1RXPPS=0x29;
    while(1){
        /*Inicio de Conversion*/
        ADCON0bits.GO=1;
        /*¿Se realizo la conversion?*/
        while (ADCON0bits.GO);
        data=(uint16_t)((ADRESH << 8) + ADRESL);
        printf("%u \n",data);
        __delay_ms(250);
    }
    return;
}
/*Configuracion del UART*/
void UART1_Config(void){
    U1CON0bits.TXEN=1;//Transmisor Habilitado
    U1CON0bits.RXEN=1;//Receptor Habilitado
    U1CON0bits.BRGS=1;//El generador de velocidad en baudios es de alta velocidad
    U1CON1bits.ON=1; //Puerto serial habilitado
    /*Velocidad de transmision 9600 baud/s*/
    U1BRGL=0x67;
    U1BRGH=0X00;    
}
/*Configuracion de FOSC*/
void OSC_Config(void){
    /*HFINTOSC*/
    OSCCON1bits.NOSC=0b0110;
    /*Nominal Freq (MHz)    4MHz*/
    OSCFRQbits.HFFRQ=0b0010;
    /*Clock Divider 1:1*/
    OSCCON1bits.NDIV=0b0000; 
}
/*Configuracion del ADC*/
void ADC_Config(void){
        /*Canal 0*/
        ADPCH=0X00;
        /*Referencia Negativa*/
        ADREFbits.NREF=0;
        /*Referencia Positiva*/
        ADREFbits.PREF=0b00;
        /*Reloj de Conversion*/
        ADCON0bits.CS=1;
        /*Formato de salida ADRES derecha*/
        ADCON0bits.FM=1;
        /*Habilitacion del ADC*/
        ADCON0bits.ON=1;
}
/*Configuracion de UART para la Transmision*/
void UART1_Write (uint8_t txData){
    while(PIR4bits.U1TXIF==0);
    U1TXB=txData;
}
/*Para el uso de "printf"*/
void putch(char txData){
    UART1_Write (txData); 
}
/*Configuracion de UART para la Recepcion*/
uint8_t UART1_Read(void){
    return U1RXB;
}
char getch (void){
    return UART1_Read();
}
/*Rutina de Interrupcion del Receptor del UART*/
void __interrupt(irq(IRQ_U1RX), base(0x3008)) U1RX_ISR(void){
    uint8_t x=UART1_Read();       
        if(x=='a'){
            RF3=0;
        }
        if(x=='b'){
            RF3=1;
        }
    PIR4bits.U1RXIF=0;
}
/*Configuracion de Interrupciones Globales*/
void INTERRUPT_Initialize (void){
    INTCON0bits.GIE = 1; // Enable high priority interrupts
    INTCON0bits.IPEN = 0; // Enable interrupt priority
}
/*Configuracion de Interupcion de UART*/
void INTERRUPT_UART1RX(void){
    PIE4bits.U1RXIE=1;
    PIR4bits.U1RXIF=1;
}
/*Inicializacion de los perifericos*/
void HARDWARE_Init(void){
    UART1_Config();
    OSC_Config();
    ADC_Config();
    INTERRUPT_Initialize();
    INTERRUPT_UART1RX();
}
