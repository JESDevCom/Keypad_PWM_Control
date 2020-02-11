/*
 * init.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 */

#include "init.h"

 void init_ports (void) {
	 
	 //LED PORT A
	 LED_PORT	= PullUpDisable;	//0x00
	 LED_DIR	= OUTPUT;			//0xFF
	 
	 //KEY PORT D
	 KEY_PORT	= PullUpEnable;		//0xFF
	 KEY_DIR	= INPUT;			//0x00
	 
	 //PWM PIN For Checking
	 PORTB		= PullUpDisable;
	 DDRB		= OUTPUT;
	 
 }
 
/*******************************************************************
					User Defined Function:	Initialize Timer0, 250 Hz
											Initialize Timer2, 40,000 Hz
*******************************************************************/
void init_timers(void){

	TCNT0= 193;
	TCCR0=0B00000110;							//TCCR0 Register
	//| FOC0 | WGM00 | COM01 | COM00 | WGM01 | CS02 | CS01 | CS00 |
	//|	  0  |   0   |   0   |   0   |   0   |   1  |   1  |   0  |

	//WGM00, WGM01		Setting: Normal Mode
	//COM01. COM00		Setting: Clear OC0 on compare match (non-inverting)
	//CS02, CS01, CS00	Setting: 256 Prescalar
	
	// d8   d7   d6   d5   d4  d3  d2  d1  d0
	// 1024 512  256  128  64  32  16  8   4 [ms]

	
	TCNT2 = 50; 
	TCCR2 = 0B00000001;							//TCCR2 Register
	//| FOC0 | WGM00 | COM01 | COM00 | WGM01 | CS02 | CS01 | CS00 |
	//|	  0  |   0   |   0   |   0   |   0   |   0  |   0  |   1  |

	//WGM00, WGM01		Setting: Normal Mode
	//COM01. COM00		Setting: Clear OC2 on compare match (non-inverting)
	//CS02, CS01, CS00	Setting: 1 Prescalar
	

	TIMSK = TIMSK | 0x41;			// Enable Timer0 and Timer2 Compare Match Interrupt
}	 

	 
