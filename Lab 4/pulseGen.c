/*
 * pulseGen.c
 *
 * Created: 2024-02-20 13:03:17
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "pulseGen.h"
#include "output.h"
#include "general.h"
#include "GUI.h"
#include "tinytimber.h"


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
		if(self->firstPushFlag == 0){
			self->firstPushFlag =1;
			ASYNC(self->observer, setFrequency, self->frequency);
			ASYNC(self->observer, updateGUI, 0);
			AFTER(((SEC(5)/3)), self,  delayContPush, 0);
			
		
		}else if (self->firstPushFlag == 1){
		ASYNC(self, plusPulse, 0);
		ASYNC(self->observer, setFrequency, self->frequency);
		ASYNC(self->observer, updateGUI, 0);
		AFTER(((SEC(1))/2), self,  delayContPush, 0);
		
		}
	}
	
	else if (!(PINB & (1 << 7)))
	{
		if(self->firstPushFlag == 0){
			self->firstPushFlag =1;
			ASYNC(self->observer, setFrequency, self->frequency);
			ASYNC(self->observer, updateGUI, 0);
			AFTER(((SEC(5)/3)), self,  delayContPush, 0);
			
			
		}else if (self->firstPushFlag == 1){
		minusPulse(self);			//Minus	
		ASYNC(self->observer, setFrequency, self->frequency);
		ASYNC(self->observer, updateGUI, 0);
		AFTER(((SEC(1))/2), self,  delayContPush, 0);
		}
	ASYNC(self->observer, setFrequency, self->frequency);
	ASYNC(self->observer, updateGUI, 0);
	}
	
	else{
		self->upDownPushFlag = 0;		//prevents several inputs entering if pressed rapidly
		self->firstPushFlag = 0;
	}
	
}

void savePulse(pulseGen *self){
	self->saved = self->frequency;
	self->frequency = 0;
	
}
void restorePulse(pulseGen *self){
	self->frequency = self->saved;
}

void notifyContPush(pulseGen *self){
	AFTER(SEC(1)/100, self->observer, recieveContPush, 0);
	
}

void  outputPulse(pulseGen *self){
	
	if (self->frequency != 0){
		pinPulse(self->op, self->target);				 //output frequency to oscilloscope
		AFTER(((SEC(1)) /(self->frequency) /2), self, outputPulse, 0); //periodically checks if given pg should re-emit signals by checking the pulseCut variable.
	}
	else if (self->frequency == 0){
		AFTER(((SEC(1)) /10), self, outputPulse, 0); //periodically checks if given pg should re-emit signals by checking if frequency is 0.
	}
	
	
}
		