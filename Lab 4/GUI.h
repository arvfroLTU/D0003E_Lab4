
/*
 * GUI.h
 *
 * Created: 2024-02-23 13:16:33
 *  Author: arvid
 */ 
#include "tinytimber.h"
#include <stdbool.h>

typedef struct {
	Object super;				//2 variabler?
	long frequency;		
	int side; // left = 0 or right 4	
	int saved1;
	int saved2;
	
} GUI;

#define initGUI() {3, 3, 25, 0}
void arithmetic(GUI *x); // + och - på frekvensens hz
void swap(GUI *x); //switches active generators
void writeLong(GUI *x);
void inputHandler(GUI *x);
int pulseControl(GUI *self);
int decreasePulse(int x);
int sideControl(GUI *self);
int increasePulse(int x);
void updateGUI(GUI *x);
int save(GUI *x);
void LCD_Init();					//INITITITIT
 