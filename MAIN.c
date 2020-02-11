/*
 * MAIN.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 

/***********************************************
		Header Files
************************************************/
#include "MAIN.h"


/***********************************************
		Global Variables
************************************************/
volatile uint8_t int_timer = 0;
volatile uint8_t CH1 = 0;
volatile uint8_t CH2 = 0;


/**********************************************
		Main
***********************************************/
int main(void)
{
	
	// 16-bit static variable declaration
	static uint8_t time_srv = 0; //timer service flags for scheduling

	// 16-bit variable declaration
	uint8_t temp = 0;
	
	// 8-bit variable declaration
	uint8_t prev_key = 0;
	uint8_t key = 0;
		
	//User Defined Initialization Processes
	init_ports();
	init_timers();
	sei(); //enable global interrupts



	/************************ MAIN WHILE LOOP ************************/
	while(1){
		temp = time_srv^int_timer;
		
		if(temp & 0x01){ //service every 4.0 [ms]
			
			time_srv = time_srv ^ 0x01;
			
			
					
			key = Debounce(); //Debounce all 4 buttons
			
			if (key != prev_key){ //stop auto repeat
				
				//************* PWM Pair 1 **************//
				if((key & 0xC0) != 0){		//ignore if both buttons are pressed
					if(key == 0x7F){		// (x)%
						if(CH1 < 20){
							CH1 = CH1 + 1;
							//LED_PORT ^= (1 << 7);
						}
					}
					else if(key == 0xBF){	// (100-x)%
						if(CH1 > 0){
							CH1 = CH1 - 1;
							//LED_PORT ^= (1 << 6);
						}
					}
				}

				//************* PWM Pair 2 **************//
				if((key & 0x30) != 0){		//ignore if both buttons are pressed
					if(key == 0xDF){		// (x)%
						if(CH2 < 20){
							CH2 = CH2 + 1;
						}
					}
					else if(key == 0xEF){	// (100-x)%
						if(CH2 > 0){
							CH2 = CH2 - 1;
						}
					}
				}
				prev_key = key;				
							
			}//if				
		}//if		
	}//while
	
	
}// END MAIN


