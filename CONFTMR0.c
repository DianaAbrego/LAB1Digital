/* 
 * File:   setupbot.c
 * Author: Diana Abrego
 *
 * Created on 18 de julio de 2023, 04:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "CONFTMR0.h"


//AQUI SE CONFIGURA EL TIMER 0 Y LA INTERRUPCION DE TMR0
void conf_TMR0(int PRESCALER, int N){
    
//CONF TMR0
    switch(PRESCALER) {
        case 0:
            OPTION_REGbits.PSA =  1;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b000; //prescaler 1:1
            break;
        case 1:
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b001; //prescaler 1:4 
            break;
        case 2 :
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b010; //prescaler 1:8
            break;
        case 3: 
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b011; //prescaler 1:16
            break;
        case 4: 
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b100; //prescaler 1:32
            break;
        case 5:
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b101; //prescaler 1:64
            break;
        case 6:
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b110; //prescaler 1:128
            break;
        case 7:
            OPTION_REGbits.PSA =  0;  //bit 6 prescaler is to TMR0 
            OPTION_REGbits.PS =  0b111; //prescaler 1:256
            break;        
    }    
    TMR0 = N; //valor de tmr0 va a ser el preload que le mande el usuario
    // si le mando N =178 se hace cada 20ms
    OPTION_REGbits.T0CS = 0;  //bit 5 clock souce select bit FOSC/4
    //Configuracion de interrupcion del TMr0 el iocb
    INTCONbits.T0IF = 0; //BANDERA DE INTERRUPCION 
    INTCONbits.T0IE = 1;  // periferico
    INTCONbits.PEIE = 1; 
    INTCONbits.GIE = 1;  //global
    
}

