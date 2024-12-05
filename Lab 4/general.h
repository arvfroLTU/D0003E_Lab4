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
#include "GUI.h"


typedef struct {
	Object super;
	pulseGen *pg1;
	pulseGen *pg2;
	GUI *graphics;
	pulseGen *Active;
	int UpDownPushFlag; //prevents several inputs entering if pressed rapidly
} General;

#define initGeneral(pg1, pg2, g){initObject(), pg1, pg2, g, pg1}			//GRAPHICS changed from g !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void switchSides(General *self);
void UpDownPushBuffer(General *self);
void LRBuffer(General *self);
void start(General *self);
void notifyGuiContPush(General *self);

#endif // FUNCTIONS_I