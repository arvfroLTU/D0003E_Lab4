
/*
 * output.h
 *
 * Created: 2024-02-23 13:20:52
 *  Author: arvid
 */ 

#include "tinytimber.h"
#include "output.h"
#include "pulseGen.h"
#include <stdbool.h>


typedef struct {
	Object super;
	int target;
	int frequency;
	bool state;
} output;

#define initOutput() {0, 10000, false}
	
void oscilloscope(output *self, pulseGen *pulsar);
void genPulse(output *p, pulseGen *pulsar);
void changePulse(output *p);
void genPulse(output *p, int frequency);
void genPulse4(output *p, int frequency);
void genPulse6(output *p, int frequency);

