/* 
 * File:   ADCConf.c
 * Author: Diana Abrego
 *
 * Created on 18 de julio de 2023, 04:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "CONFMULTI.h"
//#define _XTAL_FREQ 4000000 //La frecencia que yo utlize para el delay

int CONF_MULTI(int Num, int Disp){// Num va a ver que opcion ++
      
    if (Disp == 0)
         Num = Num/16; //D1 
    if (Disp == 1)
         Num = Num%16;// D2 
    
    switch (Num) {
        case 0:
            Num = 0b01000000;
            break;
        case 1:
            Num = 0b01111001;
            break;
        case 2:
            Num = 0b00100100;
            break;
        case 3:
            Num = 0b00110000;
            break;
        case 4:
            Num = 0b00011001;
            break;
        case 5:
            Num = 0b00010010;
            break;
        case 6:
            Num = 0b00000010;
            break;
        case 7:
            Num = 0b01111000;
            break;
        case 8:
            Num = 0b00000000;
            break;
        case 9:
            Num = 0b00010000;
            break;
        case 10:
            Num = 0b00001000;
            break;
        case 11:
            Num = 0b00000011;
            break;
        case 12:
            Num = 0b01000110;
            break;
        case 13:
            Num = 0b00100001;
            break;
        case 14:
            Num = 0b00000110;
            break;
        case 15:
            Num = 0b00001110;
            break;
        default:
            Num = 0; // Valor fuera del rango esperado (0 al 15 en decimal).
            break;
    }
    return Num;
}