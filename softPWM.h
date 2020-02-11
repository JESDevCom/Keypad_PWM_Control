/*
 * softPWM.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef SOFTPWM_H_
#define SOFTPWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>


#define LED_PORT		PORTA


void softPWM(uint8_t CH, uint8_t Bit, uint8_t tic);


#endif /* SOFTPWM_H_ */