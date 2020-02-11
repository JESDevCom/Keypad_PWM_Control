/*
 * MAIN.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/***********************************************
		Header Files
************************************************/
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "init.h"
#include "Debounce.h"
#include "timer0_isr.h"
#include "timer2_isr.h"
#include "softPWM.h"

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

extern volatile uint8_t CH1;
extern volatile uint8_t CH2;


extern volatile uint8_t int_timer;

#endif /* MAIN_H_ */