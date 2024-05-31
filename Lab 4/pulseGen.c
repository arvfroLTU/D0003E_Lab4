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


void  plusPulse(pulseGen *self){
	i++;
	self->frequency = self->frequency +1; 
}

void  minusPulse(pulseGen *self){
	if (self->frequency > 0){
		self->frequency = self->frequency -1;
	}
}

void  toZero( pulseGen *self){
	if (self->onOff ==1){
		self->onOff = 0;
	}
	else if (self->onOff ==0){
		self->onOff =1;
	}
}

void  outputPulse(pulseGen *self){
	if (self->onOff ==1 && self->frequency > 0){
		i = self->frequency;
		j = self->target;
		pinPulse(self->op, 0);				 //output frequency to oscilloscope
		AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //waits for  frequency period before repeating output
	}
	else if (self->onOff == 0){
		ASYNC(self->op, cutPulse, self->target);						//output 0 to oscilloscope
	}
}