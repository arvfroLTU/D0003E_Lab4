/*
 * pulseGen.h
 *
 * Created: 2024-02-20 13:03:31
 *  Author: arvid
 */ 
#include <stdbool.h>

typedef struct {
	Object super; 
	int target; // pin i of socket J405
	int frequency; //  pulse interval if that's easier
	int state; // on or off
} pulseGen;


#define initpulseGen(x, y) {x, y, 0}

	
	




