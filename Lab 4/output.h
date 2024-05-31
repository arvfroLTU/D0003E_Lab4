
/*
 * output.h
 *
 * Created: 2024-02-23 13:20:52
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "tinytimber.h"

#ifndef FUNCTIONS_J
#define FUNCTIONS_J

typedef struct {
	Object super;
	int state;
} output;


#define initOutput(on){initObject(), on}
	
void pinPulse(output *self, int x);
void cutPulse(output *self, int x);

#endif /* FUNCTIONS_J */
