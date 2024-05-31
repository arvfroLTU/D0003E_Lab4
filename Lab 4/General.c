/*
 * General.c
 *
 * Created: 2024-02-23 09:21:21
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "general.h"
#include "pulseGen.h"
#include "output.h"

pulseGen *ActiveObj;

void UpDownPushBuffer(General *self)
{
	if (!(PINB & (1 << 6))){
		ASYNC(ActiveObj, plusPulse, 0);
	}
	
	else if (!(PINB & (1 << 7))){
		ASYNC(ActiveObj, minusPulse, 0);
	}
	
	else if (!(PINB & (1 << 4))){
		ASYNC(ActiveObj, toZero, 0);
	}
}

void switchSides(General *self){
	if (ActiveObj == self->pg1)
		ActiveObj = self->pg2;
	
	else if	(ActiveObj ==self->pg2)
		ActiveObj = self->pg1;
}

void LRBuffer(General *self){
		if (!(PINE & (1 << 2)))
		{
				ActiveObj = self->pg2;
		}
		else if (!(PINE & (1 << 3)))
		{
				ActiveObj = self->pg1;
		}
			
}

void start(General *self){
	ActiveObj = self->pg1;
	ASYNC(self->pg1, outputPulse, 0);
	ASYNC(self->pg2, outputPulse, 0);
}