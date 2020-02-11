/*
 * init.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef INIT_H_
#define INIT_H_

/***********************************************
		Header Files
************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>

/******************************************
	Declaration Definitions
*******************************************/
#define OUTPUT			0xFF
#define INPUT			0x00
#define PullUpEnable	0xFF
#define PullUpDisable	0x00

#define KEY_PORT		PORTE
#define KEY_READ		PINE
#define KEY_DIR			DDRE
#define NO_KEY			0xFF

#define LED_PORT		PORTA
#define LED_DIR			DDRA
#define LED_ON			0xFF
#define LED_OFF			0x00

#define TOIE_0			0
#define OCIE_0			1
#define TOIE_1			2
#define OCIE1_B			3
#define OCIE1_A			4
#define TICIE_1			5
#define TOIE_2			6
#define OCIE_2			7

/******************************************
	Function Prototypes
*******************************************/
void init_ports(void);
void init_timers(void);

 
#endif /* INIT_H_ */