/*
 * general.h
 *
 * Created: 2024-02-23 09:21:21
 *  Author: arvid
 */ 

#ifndef FUNCTIONS_I
#define FUNCTIONS_I

#include <avr/io.h>
#include "tinytimber.h"
#include "pulseGen.h"

typedef struct {
	Object super;
	pulseGen *pg;
} General;

#define initGeneral(pg){initObject(), pg}

void UpDownPushBuffer(General *self);
void LRBuffer(General *self);
void start(General *self);

#endif // FUNCTIONS_I