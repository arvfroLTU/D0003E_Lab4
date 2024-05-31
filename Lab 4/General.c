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

void UpDownPushBuffer(General *self)
{
	if (!(PINB & (1 << 6))){
		ASYNC(self->pg, plusPulse, 0);
	}
	
	else if (!(PINB & (1 << 7))){
		ASYNC(self->pg, minusPulse, 0);
	}
	
	else if (!(PINB & (1 << 4))){
		ASYNC(self->pg, toZero, 0);
	}
}

void LRBuffer(General *self){
}

void start(General *self){
	ASYNC(self->pg, outputPulse, 0);
}