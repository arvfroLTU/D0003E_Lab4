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
	
	if (self->state == 0)
	{
		if (x ==0){
			PORTE = (1<<PE4);
		}
		else if (x ==1){
			PORTE = (1<<PE6);
		}
		self->state =1;
	}
	else
	{
		if (x ==0)
			PORTE = (0<<PE4);
		else if (x ==1)
			PORTE = (0<<PE6);
			
		self->state = 0;
	}
}

void cutPulse(output *self, int x){
	if (x == 0){
		PORTE = (0<<PE4);
	}
	else if (x == 1){
		PORTE = (0<<PE6);
	}
}
