
/*
 * output.h
 *
 * Created: 2024-02-23 13:20:52
 *  Author: arvid
 */ 

#include "tinytimber.h"

#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H


typedef struct {
	Object super;
	int state;
} output;


#define initOutput(on){initObject(), on}
	
void pinPulse(output *self, int x);
void cutPulse(output *self, int x);

#endif /* OUTPUTHANDLER_H */
