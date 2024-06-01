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
	if (self->onOff ==1){
		self->saved = self->frequency;
		self->frequency = 0;
		self->onOff = 0;
	}
	else if (self->onOff ==0){
		self->frequency = self->saved;
		self->onOff =1;
	}
}

/*
void  outputPulse(pulseGen *self){
	if (self->onOff ==1){
		j = self->target;
		pinPulse(self->op, self->target);				 //output frequency to oscilloscope
		AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //waits for  frequency period before repeating output
	}
	else if (self->onOff == 0){
		ASYNC(self->op, cutPulse, self->target);						//output 0 to oscilloscope
		//AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0);
		
	}
}
*/

void  outputPulse(pulseGen *self){
	
		pinPulse(self->op, self->target);				 //output frequency to oscilloscope
		AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //waits for  frequency period before repeating output
}
		