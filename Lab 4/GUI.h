
/*
 * GUI.h
 *
 * Created: 2024-02-23 13:16:33
 *  Author: arvid
 */ 
#include "tinytimber.h"
#include <stdbool.h>
#include "pulseGen.h"


#ifndef FUNCTIONS_K
#define FUNCTIONS_K

typedef struct {
	Object super;				//2 variabler?
	long frequency;		
	int side; // left = 0 or right 4	
	int saved1;
	int saved2;
	pulseGen *pg1;
	pulseGen *pg2;
} GUI;

#define initGUI(pg1, pg2){initObject(), 1, 0, 0, 0, pg1, pg2}

void begin (GUI *self);
void arithmetic(GUI *x); // + och - på frekvensens hz
void swap(GUI *x); //switches active generators
void writeLong(GUI *x);
void inputHandler(GUI *x);
int pulseControl(GUI *self);
int decreasePulse(int x);
int sideControl(GUI *self);
int increasePulse(int x);
void updateGUI(GUI *x);
void LCD_Init();					//INITITITIT
void setFrequency(GUI *d, int x);
void recieveContPush(GUI *d);

#endif // FUNCTIONS_K
 