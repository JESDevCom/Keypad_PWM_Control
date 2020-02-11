/*
 * Debounce.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

/********************************************
		Header Files
*********************************************/
#include <avr/io.h>

/********************************************
		Declaration Definitions
*********************************************/
#define true		1
#define false		0
#define KEY_READ	PINE

/********************************************
		Function Prototypes
*********************************************/
uint8_t Debounce(void);



#endif /* DEBOUNCE_H_ */