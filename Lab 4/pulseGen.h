/*
 * pulseGen.h
 *
 * Created: 2024-02-20 13:03:31
 *  Author: arvid
 */ 
#include <avr/io.h>
#include "tinytimber.h"
#include "output.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef struct {
	Object super; 
	int target; // pin i of socket J405 can be either 0 for pin4 or 1 for pin6
	int frequency; //  pulse interval if that's easier
	int saved;
	int pulseCut;
	output *op;		
} pulseGen;


#define initpulseGen(trgt, freq, op){initObject(), trgt, freq, 1, 0, 0, op}

void  plusPulse(pulseGen *self);
void  minusPulse(pulseGen *self);
void  toZero(pulseGen *self);
void  outputPulse(pulseGen *self);


#endif // FUNCTIONS_H


	
	




