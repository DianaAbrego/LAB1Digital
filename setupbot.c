/* 
 * File:   setupbot.c
 * Author: Diana Abrego
 *
 * Created on 18 de julio de 2023, 04:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
///
#include "setupbot.h"

void ioc_init(char pin){
    INTCONbits.GIE = 1;         //GLOBALES
    INTCONbits.RBIE = 1;        // Activo interrupción de botón
    INTCONbits.RBIF = 0;        // Apago bandera de interrupción
    OPTION_REGbits.nRBPU = 0;   // Activo pull ups generales
   if (pin == 0)
   { 
     IOCBbits.IOCB0 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB0 = 1;         // Activo pull up B0
   }
   if(pin == 1){
     IOCBbits.IOCB1 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB1 = 1;         // Activo pull up B1
   }
    
     if(pin == 2){
     IOCBbits.IOCB2 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB2 = 1;         // Activo pull up B2
   }
    if(pin == 3){
     IOCBbits.IOCB3 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB3 = 1;         // Activo pull up B3
   }
    if(pin == 4){
     IOCBbits.IOCB4 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB4 = 1;         // Activo pull up B4
   }
    if(pin == 5){
     IOCBbits.IOCB5 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB5 = 1;         // Activo pull up B5
   }
    if(pin == 6){
     IOCBbits.IOCB6 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB6 = 1;         // Activo pull up B6
   } 
    if(pin == 7){
     IOCBbits.IOCB7 = 1;         // INTERRUPCIÓN PORTB activada 
     WPUBbits.WPUB7 = 1;         // Activo pull up B6
   }  
      
       
}

