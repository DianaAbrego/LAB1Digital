// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
///LIBRERIAS 
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include "SETUPBOT.H"
#include "ADCConf.H"
#include "CONFTMR0.h"
#include "CONFMULTI.h"
#define _XTAL_FREQ 4000000 //La frecencia que yo utlize para el delay

////PROTOTIPOS DE FUNCION
void setup(void);

///Variables Globales
int CONTADORTMR0;
char ADCres;
char ContaBot;

//ISR//VECTOR INTERRUPCION
void __interrupt()isr(void){
if(INTCONbits.RBIF){            //Interrupcion ONCHANGE PORTB
        PORTB = PORTB;
        INTCONbits.RBIF = 0;
        if(RB0 == 0)
            PORTD++;
        //ContaBot++;
        if(RB1 == 0)
            PORTD--;
        //ContaBot--;
        ContaBot = PORTD;
}

    if(T0IF) 
        CONTADORTMR0++;
        T0IF = 0;
        TMR0 = 177;
}

//*********************************MAIN **********************************//
void main(void){
    setup();
    while(1) { 
        ADCres = (char) adc_read(); 
        PORTEbits.RE0 = 1; // transistor 
        PORTEbits.RE1 = 0;
        
        if (ADCres >= ContaBot)
            PORTEbits.RE2 =1;
        else 
            PORTEbits.RE2 =0;
    
         
        
    if (CONTADORTMR0%2 == 0)
    {
        PORTC = CONF_MULTI(ADCres,1); // le manda el valor codificado al display 1 izquierda
        PORTEbits.RE0 = 1; // transistor 
        PORTEbits.RE1 = 0; // asi los dos transistores no estaran encendidos al mismo tiempo
    }
        //__delay_ms(20);
    if (CONTADORTMR0%2 == 1)
    {
        PORTC = CONF_MULTI(ADCres,0); // le manda el valor al display 2
        PORTEbits.RE1 = 1; // transisor
        PORTEbits.RE0 = 0; // transistor
    }
     
}
    return;
}



void setup(void)
{ 
    //CONFIGURACION PINES DIGITALES
    ANSEL = 0;
    ANSELH = 0;
    //CONFIGURACION I/O
    TRISB = 7;
    TRISA = 0B00000010;
    TRISC = 0; //SALIDA
    TRISD = 0; //SALIDA
    TRISE = 0; //SALIDA
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;  //MANDALE VOLTAJE 
    PORTD = 0;  //MANDARLE VOLTAJE 
    PORTE = 0; 
    //RE2 = 1;
    ioc_init(0); //boton 0
    ioc_init(1);  //boton 1
    adc_init(0); //potenciomentro
    
    //PARA CONF DEL TMER0
    conf_TMR0(7,178); //el valor del prescaler puede ir de 0-7 .Con esta conf la 
    // interrupcion sera a cada 20ms   
}

