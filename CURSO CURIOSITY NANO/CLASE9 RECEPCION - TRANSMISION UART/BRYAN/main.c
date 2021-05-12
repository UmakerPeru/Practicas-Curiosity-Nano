/* 
 * File:   main.c
 * Author: Bryan
 *
 * Created on 11 de mayo de 2021, 09:05 AM
 */
#pragma config WDTE = OFF
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 1000000

void UART1_Initialize(void);
void ADC_config(void);
void OSC_config(void);
void UART1_Write(uint8_t);
uint8_t UART1_Read(void);
void config_global_interrupt(void);
void config_interrupt_U1RX(void);

uint16_t resultado_adc;

/*
 * 
 */
int main(int argc, char** argv) {
    OSC_config();
    ADC_config();
    UART1_Initialize();
    config_global_interrupt();
    config_interrupt_U1RX();
    //Configuracion del puerto F para envio y recepcion de datos en serie
    ANSELF = 0;
    LATF = 0;
    TRISF = 0b00000010;
    RF0PPS = 0x20;
    U1RXPPS = 0x29;
    while (1) {
        //Transmision
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

//Configuracion Oscilador
void OSC_config() {
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0b0010;
    OSCFRQbits.HFFRQ = 0b0010;
}

//Configuracion del ADC
void ADC_config() {
    ADPCH = 0x00; //Se selecciona el canal analogico
    ADREFbits.NREF = 0; //Vref- se conecta a AVss
    ADREFbits.PREF = 0b00; //Vref+ se conecta a Vdd
    ADCON0bits.CS = 1; //Se utiliza el oscilador del ADC
    ADCON0bits.FM = 1; //Se selecciona un formato alineado a la derecha
    ADCON0bits.ON = 1; //Se habilita el ADC
    __delay_ms(100);
}

//Configuracion para baud rate de 9600
void UART1_Initialize() {
    //Transmision y emisor habilitados, generador de baudios a alta velocidad
    U1CON0 = 0xB0;
    U1CON1 = 0b10000000; //Bit 7 sirve para habilitar UART
    //Configuracion del generador de baudios (velocidad)
    U1BRGL = 0x19;
    U1BRGH = 0x00;
}

//Transmision
void UART1_Write(uint8_t txData) {
    while (PIR4bits.U1TXIF == 0);
    U1TXB = txData;
}

void putch(char txData) {
    UART1_Write(txData);
}

//Recepcion
uint8_t UART1_Read() {
    while (PIR4bits.U1RXIF == 0);
    return U1RXB;
}

char getch(void) {
    return UART1_Read();
}

//Interrupcion para recepcion de dato
void __interrupt(irq(IRQ_U1RX),base(0x3008)) U1RX_ISR(void){
    if(PIR4bits.U1RXIF == 1){
        //Recepcion
        uint8_t x = UART1_Read();
        if (x == 'a') {
            RF3 = 0;
            printf("ON\n");
        }
        if (x == 'b') {
            RF3 = 1;
            printf("OFF\n");
        }
        PIR4bits.U1RXIF = 0;
    }
}

//Habilitacion de interrupciones
void config_global_interrupt(){
    INTCON0bits.IPEN = 0;
    INTCON0bits.GIE = 1;
}

void config_interrupt_U1RX(){
    PIE4bits.U1RXIE = 1; //Habilita interrupcion de RX UART
    PIR4bits.U1RXIF = 1; //Inicio limpiando el flag de RX UART
}
