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

struct GUI;

typedef struct {
	Object super; 
	int target; // pin i of socket J405 can be either 0 for pin4 or 1 for pin6
	int frequency; //  pulse interval if that's easier
	int saved;
	int pulseCut;
	int upDownPushFlag;
	int firstPushFlag;
	output *op;
	struct GUI *observer;		
} pulseGen;


#define initpulseGen(trgt, freq, op){initObject(), trgt, freq, 0, 0, 0, 0, op}

void  plusPulse(pulseGen *self);
void  minusPulse(pulseGen *self);
void  outputPulse(pulseGen *self);
void savePulse(pulseGen *self);
void restorePulse(pulseGen *self);
void delayContPush(pulseGen *self);
void notifyContPush(pulseGen *self);


#endif // FUNCTIONS_H


	
	




