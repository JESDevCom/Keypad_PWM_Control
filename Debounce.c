/*
 * Debounce.c
 *
 * Bradley University
 * ECE 205
 * Project 7
 */ 

#include "Debounce.h"

uint8_t Debounce(void){
	
	//Variable Declaration
	uint8_t new_key = false;
	uint8_t still_pressed_key = false;
	uint8_t released_key = false;
	uint8_t temp = KEY_READ;
	uint8_t element = 0;
	uint8_t key = 0xFF;
	uint8_t pinvalue[8];
	static uint8_t pinstate[8] = {4,4,4,4,4,4,4,4};
	static uint8_t prev_pinvalue[8];

	for(uint8_t i = 0; i<8; i++){
		switch(i){
			case 0:
			element = temp & 0x01 ;
			break;
			case 1:
			element = temp & 0x02;
			break;
			case 2:
			element = temp & 0x04;
			break;
			case 3:
			element = temp & 0x08;
			break;
			case 4:
			element = temp & 0x10;
			break;
			case 5:
			element = temp & 0x20;
			break;
			case 6:
			element = temp & 0x40;
			break;
			case 7:
			element = temp & 0x80;
			break;
		}// end switch

		if (element >= 1) {
			element = 1;
		}
		else {
			element = 0;
		}
		pinvalue[i] = element;
		element = 0;
	}// end for


	for(uint8_t i = 0; i<8; i++){
		if (pinvalue[i] == 0) {
			switch (pinstate[i]) {
				case 0:
				new_key = true;
				break;
				case 1:
				still_pressed_key = true;
				break;
				case 4:
				new_key = true;
				break;
				default:
				break;
			}// end switch
		}// end if
		else {
			if(pinstate[i] == 1){
				still_pressed_key = true;
				released_key = true;
			}// end if
		}// end else
	}// end for

	for(uint8_t i=0; i<8; i++){
		if(new_key == true){

			if(pinvalue[i] == 0){
				for(uint8_t j=0; j<8; j++){
					prev_pinvalue[j] = pinvalue[j];
				}// end for
				pinstate[i] = 1;
			}// end if
			else {
			}// end else
		}// end if

		if(still_pressed_key == true){
			if(pinvalue[i] == 0){
				pinstate[i] = 1;
			}
			else{
				if(prev_pinvalue[i] != pinvalue[i]){
					pinstate[i] = 2;
					released_key = true;
				}// end if
			}// end else
		}// end if

		if(released_key == true){
			switch(pinstate[i]){
				case 2:
				key &= ~(1<<i);
				pinstate[i] = 4;
				break;
				default:
				key |= (1<<i);
				break;
			}// end switch
			prev_pinvalue[i] = pinvalue[i];
		}// end if
	}// end for

	//key = key ^ 0xFF;
	return key;
}// end DeBouncePro