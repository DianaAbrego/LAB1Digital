/*
 * * File:  SETUP BOTONES 
 * Author: DIANA ABREGO 
 * Comments:
 * Revision history: 
 
 */
 

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SETUPBOT_H
#define	SETUPBOT_H

#include <xc.h> // include processor files - each processor file is guarded.  
///FUNCION PARA CONF PULLUP BOTONES//
void ioc_init(char pin);

#endif	/* SETUPBOT_H */

