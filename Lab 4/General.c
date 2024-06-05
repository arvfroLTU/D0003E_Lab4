/*
 * General.c
 *
 * Created: 2024-02-23 09:21:21
 *  Author: arvid
 */ 

#include <avr/io.h>
#include "general.h"
#include "pulseGen.h"
#include "output.h"
#include "GUI.h"

/*
void start(General *self)
{
	ASYNC(self->graphics, LCD_Init, 0 );
	ActiveObj = self->pg1;
	ASYNC(self->pg1, outputPulse, 0);
	ASYNC(self->pg2, outputPulse, 0);
	
}
*/
void UpDownPushBuffer(General *self)
{
	if (!(PINB & (1 << 6)))
	{
		ASYNC(self->Active, plusPulse, 0);
		self->graphics->frequency = self->Active->frequency;
		ASYNC(self->graphics, updateGUI, 0);
	}
	
	else if (!(PINB & (1 << 7)))
	{
		ASYNC(self->Active, minusPulse, 0);
		self->graphics->frequency = self->Active->frequency;
		ASYNC(self->graphics, updateGUI, 0);
	}
	
	else if (!(PINB & (1 << 4)))
	{
		if (self->Active->pulseCut == 0)
		{
			self->graphics->frequency = 0;
		}
		else if (self->Active->pulseCut == 1)
		{
			self->graphics->frequency = self->Active->frequency;
		}
		ASYNC(self->Active, toZero, 0);
		ASYNC(self->graphics, updateGUI, 0);
	}
}

void LRBuffer(General *self){

		if (!(PINE & (1 << 2)))
		{	
			self->Active = self->pg1;						//Towards MONITOR IS PG2 (Left)
			
			self->graphics->side = 0;
			//self->graphics->frequency =self->pg1->frequency;
			LCDDR13 = 0x0;
			LCDDR18 = 0x1;
			//ASYNC(self->graphics, updateGUI, 0);

		}
		else if (!(PINE & (1 << 3)))
		{	
			self->Active = self->pg2;					// Away from MONITOR IS PG1 (Right)
			
			self->graphics->side = 4;
			//self->graphics->frequency =self->pg2->frequency;
			LCDDR13 = 0x1;
			LCDDR18 = 0x0;
			//ASYNC(self->graphics, updateGUI, 0);

		}	
}