/*
 * General.c
 *
 * Created: 2024-02-23 09:21:21
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "tinytimber.h"
#include "general.h"
#include "pulseGen.h"
#include "output.h"
#include "GUI.h"


// Add continuous loop
void UpDownPushBuffer(General *self)
{
	
	if (!(PINB & (1 << 6)))							//Plus
	{
		ASYNC(self->Active, plusPulse, 0);
		ASYNC(self->graphics, setFrequency, (self->Active->frequency));	
		if(self->Active->upDownPushFlag != 1){							//prevents several inputs entering if pressed rapidly
			self->Active->upDownPushFlag = 1;
			ASYNC( self->Active,  delayContPush, 0);
		}
	}
	
	else if (!(PINB & (1 << 7)))
	{											//Minus
		ASYNC(self->Active, minusPulse, 0);		
		ASYNC(self->graphics, setFrequency, (self->Active->frequency));	
		if(self->Active->upDownPushFlag != 1){
			self->Active->upDownPushFlag = 1;
			ASYNC(self->Active,  delayContPush, 0);
		}
	}
	
	else if (!(PINB & (1 << 4)))					//Push
	{
		if (self->Active->frequency != 0)
		{
			ASYNC(self->Active, savePulse, 0);
		}
		else if (self->Active->frequency == 0)
		{
			ASYNC(self->Active, restorePulse, 0);
		}
		 
	}
ASYNC(self->graphics, setFrequency, (self->Active->frequency));	
	ASYNC(self->graphics, updateGUI, 0);
	
}


//LRBuffer complete
void LRBuffer(General *self){

		if (!(PINE & (1 << 2)))
		{	
			self->Active = self->pg1;						
			
			self->graphics->side = 0;		//put gui in line with pGen
			LCDDR13 = 0x0;				//side indicators indicate left
			LCDDR18 = 0x1;
			ASYNC(self->graphics, setFrequency, (self->Active->frequency));	
			ASYNC(self->graphics, updateGUI, 0);

		}
		else if (!(PINE & (1 << 3)))
		{	
			self->Active = self->pg2;					
			
			self->graphics->side = 4;	//put gui in line with pGen
			LCDDR13 = 0x1;				//side indicators indicate right
			LCDDR18 = 0x0;
			ASYNC(self->graphics, setFrequency, (self->Active->frequency));	
			ASYNC(self->graphics, updateGUI, 0);

		}	
}

void start(General *self){
	
	ASYNC(self->graphics, begin, 0);
	
}