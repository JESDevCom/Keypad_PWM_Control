/*
 * SoftPWM.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 


#include "softPWM.h"

void softPWM(uint8_t CH, uint8_t Bit, uint8_t tic){
				
	if( CH == 0){
		LED_PORT &= ~(1 << Bit);
		LED_PORT |= (1 << (Bit+1)); //Inverted Bit
	}
	else if( tic < CH){
		LED_PORT |= (1 << Bit);
		LED_PORT &= ~(1 << (Bit+1)); //Inverted Bit
	}
	else if(CH == 20){
		LED_PORT |= (1 << Bit);
		LED_PORT &= ~(1 << (Bit+1)); //Inverted Bit
	}
	else{
		LED_PORT &= ~(1 << (Bit));
		LED_PORT |= (1 << (Bit+1)); //Inverted Bit
	}

			

}//function	