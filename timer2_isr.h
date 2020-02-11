/*
 * timer2_isr.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef TIMER2_ISR_H_
#define TIMER2_ISR_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "softPWM.h"

#define KEY_PORT		PORTE
#define KEY_READ		PINE
#define KEY_DIR			DDRE

#define LED_PORT		PORTA
#define LED_DIR			DDRA


extern volatile uint8_t CH1;
extern volatile uint8_t CH2;


#endif /* TIMER2_ISR_H_ */