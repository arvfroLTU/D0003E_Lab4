/*
 * pulseGen.c
 *
 * Created: 2024-02-20 13:03:17
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "pulseGen.h"
#include "output.h"

int i = 0;
int j = 0;
int k = 1;


void  plusPulse(pulseGen *self){
	i++;
	k++;
	self->frequency = self->frequency +1; 
}

void  minusPulse(pulseGen *self){
	j++;
	k--;
	if (self->frequency > 1){
		self->frequency = self->frequency -1;
	}
}

void  toZero( pulseGen *self){
	if (self->pulseCut == 0){
		self->pulseCut = 1;
	}
	else if (self->pulseCut ==1){
		self->pulseCut =0;
	}
}

void  outputPulse(pulseGen *self){
	
	if (self->pulseCut == 0)
		pinPulse(self->op, self->target);				 //output frequency to oscilloscope
	else if (self->pulseCut == 1)
		cutPulse(self->op, self->target);
	AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //waits for  frequency period before repeating output
}
		