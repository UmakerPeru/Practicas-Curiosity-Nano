/*
 * File:   main.c
 * Author: Jose
 *
 * Created on May 11, 2021, 1:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000

/*Prototipos de funciones*/
void UART1_Config(void);
void OSC_Config(void);
void UART1_Write (uint8_t txData);
void ADC_Config(void);

/*Variable  de lectura del canal analogico*/
uint16_t data;

void main(void) {
    UART1_Config();
    OSC_Config();
    ADC_Config();
    ANSELF=0;
    LATF=0;
    TRISF=0;
    RF0PPS=0X20;
    
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

void UART1_Config(void){
    U1CON0bits.TXEN=1;//Transmisor Habilitado
    U1CON0bits.RXEN=1;//Receptor Habilitado
    U1CON0bits.BRGS=1;//El generador de velocidad en baudios es de alta velocidad
    U1CON1bits.ON=1; //Puerto serial habilitado
    /*Velocidad de transmision 9600 baud/s*/
    U1BRGL=0x19;
    U1BRGH=0X00;    
}

void OSC_Config(void){
    OSCCON1bits.NOSC=0b0110;
    OSCCON1bits.NDIV=0b0010;
    OSCFRQbits.HFFRQ=0b0010;
}


void UART1_Write (uint8_t txData)
{
    while(PIR4bits.U1TXIF==0);
    U1TXB=txData;
}

void putch(char txData){
    UART1_Write (txData); 
}

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

