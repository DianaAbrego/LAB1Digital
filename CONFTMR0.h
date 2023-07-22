/*
 * * File:  SETUP BOTONES 
 * Author: DIANA ABREGO 
 * Comments:
 * Revision history: 
 
 */
 

  
#ifndef CONFTMR0_H
#define	CONFTMR0_H

#include <xc.h> // include processor files - each processor file is guarded.  
///FUNCION PARA CONF PULLUP BOTONES//
void conf_TMR0(int PRESCALER, int N);//N Es el preload

#endif	/* CONFTMR0_H */
