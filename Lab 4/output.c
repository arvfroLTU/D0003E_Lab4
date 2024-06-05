/*
 * output.c
 *
 * Created: 2024-02-23 10:26:55
 *  Author: arvid
 */ 

#include "output.h"
#include <avr/io.h>



void pinPulse(output *self, int x)
{
	// Look over
	
	if (x == 0)
	{
		PORTE ^= (1 << 4);
	}
	if (x == 1)
	{
		PORTE ^= (1 << 6);
	}

}


void cutPulse(output *self, int x){
	if (x == 0){
		PORTE |= ( 0<< 4);

		
	}
	else if (x == 1){
		PORTE |= (0 << 6);
	}
	
}
