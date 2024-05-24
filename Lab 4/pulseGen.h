/*
 * pulseGen.h
 *
 * Created: 2024-02-20 13:03:31
 *  Author: arvid
 */ 
#include "tinytimber.h"
#include "output.h"

typedef struct {
	Object super; 
	int target; // pin i of socket J405 can be either 0 for pin4 or 1 for pin6
	int frequency; //  pulse interval if that's easier
	int onOff; // this exists so that the frequency can be stored while outputting 0.
	output *op;		
} pulseGen;


#define initpulseGen(trgt, freq, op){initObject(), trgt, freq, 1, op}

void  plusPulse(pulseGen *self);
void  minusPulse(pulseGen *self);
void  toZero(pulseGen *self);
void  outputPulse(pulseGen *self);


	
	




