/*
 * pulseGen.c
 *
 * Created: 2024-02-20 13:03:17
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "pulseGen.h"
#include "output.h"


void  plusPulse(pulseGen *self){
if (self->frequency < 99){
	self->frequency = self->frequency +1; 
	}
}

void  minusPulse(pulseGen *self){
	if (self->frequency > 0){
		self->frequency = self->frequency -1;
	}
}

void delayContPush(pulseGen *self){
		if (!(PINB & (1 << 6)))							//Plus
	{
		plusPulse(self);
		AFTER((SEC(1)/2), self,  delayContPush, 0);
	}
	
	else if (!(PINB & (1 << 7)))
	{
		minusPulse(self);			//Minus		
		AFTER(((SEC(1))/2), self,  delayContPush, 0);
	}
	else{
		self->upDownPushFlag = 0;		//prevents several inputs entering if pressed rapidly
	}
	
}

void  outputPulse(pulseGen *self){
	
	if (self->frequency != 0){
		pinPulse(self->op, self->target);				 //output frequency to oscilloscope
	}
	else if (self->frequency == 0){
		cutPulse(self->op, self->target);
	}
	AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //periodically checks if given pg should re-emit signals by checking the pulseCut variable.
	
}

void savePulse(pulseGen *self){
	self->saved = self->frequency;
	self->frequency = 0;
	
}
void restorePulse(pulseGen *self){
	self->frequency = self->saved;
}
		