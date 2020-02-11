/*
 * timer0_isr.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 *
 * Timer0, 250 Hz
 */ 

#include "timer0_isr.h"

ISR(TIMER0_OVF_vect){
	
	TCNT0 = 0;
	TCCR0 = 0B00010110;	
	
	//PORTA ^= (1 << 7);
	
	int_timer++;

	if(int_timer == 0x80){
		int_timer=0;
	}
	
	TCNT0 = 65;

}
