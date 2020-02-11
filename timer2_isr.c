/*
 * timer2_isr.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 

#include "timer2_isr.h"

static uint8_t tick = 0;

ISR(TIMER2_OVF_vect){
	
	TCNT2 = 0;
	TCCR2 = 0B00000001;	
	
	//PORTA ^= (1 << 6);
	
	if(tick == 20){
		tick = 0;		
	}
	
	

	softPWM(CH1, 0, tick);
	softPWM(CH2, 2, tick);

	tick = tick + 1;	
	

	TCNT2 = 50;
	
	
	
}