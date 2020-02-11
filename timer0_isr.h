/*
 * timer0_isr.h
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#ifndef TIMER0_ISR_H_
#define TIMER0_ISR_H_

#include <avr/io.h>
#include <avr/interrupt.h>







// interrupt timer
// d15  d14  d13  d12 d11 d10 d9   d8   d7   d6   d5   d4  d3   d2  d1  d0
// 4194 2097 1024 524 262 131 65.5 32.8 16.4 8.1  4.1  2.1 1.0 .51 .26 .13 [ms]
extern volatile uint8_t int_timer; //interrupt timer




#endif /* TIMER0_ISR_H_ */