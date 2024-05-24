/*
 * output.c
 *
 * Created: 2024-02-23 10:26:55
 *  Author: arvid
 */ 

#include "output.h"
#include "tinytimber.h"
//#include "pulseGen.h"
#include <avr/io.h>
/*

void changePulse(output *self) 
{
	self->state = !self->state; // Change state
	if (self->state) 
	{
		//PORTE |= (1 << PE6); // Set pin to 1
	}
	else
	{
		//PORTE &= ~(1 << PE6); // Set pin to 0
	}
}

pulseGen pulsar =initpulseGen;

void genPulse4(output *self, int frequency) 
{
	 float pulses=1000/frequency;
	
	if (self->state == false)
	{
		PORTE = (1<<PE4);
		self->state = true;
	}	
	else
	{
		PORTE = (0<<PE4);
		self->state = false;
	}
	
	for (long i=0; i<2000000; i++) {}						//for fun
	genPulse(self, unused);									//for fun
	//AFTER(MSEC(pulses), genPulse, self, 0); //requeues the function
}

void genPulse6(output *self, int frequency) 
{
	 float pulses=1000/frequency;
	
	if (self->state == false)
	{
		PORTE = (1<<PE6);
		self->state = true;
	}	
	else
	{
		PORTE = (0<<PE6);
		self->state = false;
	}
	
	for (long i=0; i<2000000; i++) {}						//for fun
	genPulse(self, unused);									//for fun
	//AFTER(MSEC(pulses), genPulse, self, 0); //requeues the function
}


void oscilloscope(output *self, pulseGen *pulsar)
{
	int freq = pulsar->frequency;
	
	if((pulsar ->target) == 4){
		genPulse4(self, freq);
	}
	else if((pulsar->target) ==6))
	{
		genPulse6(self, freq);
	}
	
	
}
*/