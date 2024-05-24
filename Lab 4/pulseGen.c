/*
 * pulseGen.c
 *
 * Created: 2024-02-20 13:03:17
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "pulseGen.h"
#include "output.h"



void  plusPulse( pulseGen *self){
//	self->frequency = self->frequency +1; 
}

void  minusPulse(pulseGen *self){
	self->frequency = self->frequency -1;
}

void  toZero( pulseGen *self){
	if (self->onOff ==1){
		self->onOff = 0;
	}
	else if (self->onOff ==1){
		self->onOff =0;
	}
}

void  outputPulse(pulseGen *self){
	if (self->onOff ==1){
		ASYNC(self->op, pinPulse, self->target);				 //output frequency to oscilloscope
		AFTER(((SEC(1)) /self->frequency /2), self, outputPulse, 0); //waits for  frequency period before repeating output
	}
	else if (self->onOff == 0){
		ASYNC(self->op, cutPulse, self->target);						//output 0 to oscilloscope
	}
}