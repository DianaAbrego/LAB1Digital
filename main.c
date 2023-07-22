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
#include <stdint.h>
#include <pic16f887.h>
#define _tmr0_value 200
#define _XTAL_FREQ 500000 //La frecencia que yo utlize para el delay

////PROTOTIPOS DE FUNCION
void setup(void);
////
///Variables Globales

////

//ISR//VECTOR INTERRUPCION
void __interrupt() isr (void){
if(INTCONbits.RBIF){            //Interrupcion ONCHANGE PORTB
        PORTB = PORTB;
        INTCONbits.RBIF = 0;
        if(RB0 == 0){
            PORTA++;
        }
        if(RB1 == 0){
            PORTA--;
        }
}
}

//
void main(void){
    setup();
    while(1) {
       
    return;
    }
}


///CONF BOTONES 
void setup(void) //La funcion 
{
    
    //CONFIGURACION PINES DIGITALES
    ANSEL = 0;
    ANSELH = 0;
    //CONFIGURACION I/O
    TRISB = 0B00001111;
    TRISA = 0; //PARA COLOCAR EL PUERTO  E COMO SALIDA
   
    
    //CONFITGURACION BOTON 
    OPTION_REGbits.nRBPU = 0;   // Activo pull ups generales
    WPUBbits.WPUB0 = 1;         // Activo pull up B0
    WPUBbits.WPUB1 = 1;         // Activo pull up B1
    WPUBbits.WPUB2 = 1;         // Activo pull up B2

    INTCONbits.GIE = 1;         //GLOBALES
    INTCONbits.RBIE = 1;        // Activo interrupción de botón
    INTCONbits.RBIF = 0;        // Apago bandera de interrupción
    IOCBbits.IOCB0 = 1;         // INTERRUPCIÓN PORTB activada
    IOCBbits.IOCB1 = 1;         // INTERRUPCIÓN PORTB activada
   
}

