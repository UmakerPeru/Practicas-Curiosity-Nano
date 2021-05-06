/* 
 * File:   main.c
 * Author: Bryan
 *
 * Created on 5 de mayo de 2021, 08:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 1000000

//Declaracion de prototipos de funciones
void UART1_Initialize(void);
void ADC_config(void);
void OSC_config(void);
void UART1_Write(uint8_t);

//Variable que almacena el valor del ADC
uint16_t resultado_adc;

/*
 * 
 */

int main(int argc, char** argv) {
    OSC_config();
    ADC_config();
    UART1_Initialize();
    //Configuracion del puerto F para envio de datos en serie
    ANSELF = 0;
    LATF = 0;
    TRISF = 0;
    RF0PPS = 0x20;
    while (1) {
        ADCON0bits.GO = 1; //Se empieza el ciclo de conversion
        while (ADCON0bits.GO); //Se verifica si la conversion acabo
        //Se guarda la salida del ADC en la variable resultado_adc
        resultado_adc = (ADRESH << 8) + ADRESL;
        //Se imprime la variable mediante la funcion printf
        printf("%u\n", resultado_adc);
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

void ADC_config() {
    ADPCH = 0x00; //Se selecciona el canal analogico
    ADREFbits.NREF = 0; //Vref- se conecta a AVss
    ADREFbits.PREF = 0b00; //Vref+ se conecta a Vdd
    ADCON0bits.CS = 1; //Se utiliza el oscilador del ADC
    ADCON0bits.FM = 1; //Se selecciona un formato alineado a la derecha
    ADCON0bits.ON = 1; //Se habilita el ADC
    __delay_ms(100);
}

void OSC_config() {
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0b0010;
    OSCFRQbits.HFFRQ = 0b0010;
}

void UART1_Initialize() {
    //Transmision y emisor habilitados, generador de baudios a alta velocidad
    U1CON0 = 0xB0;
    U1CON1 = 0b10000000; //Bit 7 sirve para habilitar UART
    //Configuracion del generador de baudios (velocidad)
    U1BRGL = 0x19;
    U1BRGH = 0x00;
}

void UART1_Write(uint8_t txData) {
    while (PIR4bits.U1TXIF == 0);
    U1TXB = txData;
}

void putch(char txData) {
    UART1_Write(txData);
}
