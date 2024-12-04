#include <avr/io.h>
#include <stdint-gcc.h>
#include <stdio.h>
#include <math.h>                    //used for floor (not used right now...)
#include <stdbool.h>                //used for the is_prime check
#include <unistd.h>

#include "GUI.h"
#include "tinytimber.h"
#include "output.h"


int *point[16] = {&LCDDR0, &LCDDR1, &LCDDR2, &LCDDR3, &LCDDR5, &LCDDR6, &LCDDR7, &LCDDR8, &LCDDR10, &LCDDR11, &LCDDR12, &LCDDR13, &LCDDR15, &LCDDR16, &LCDDR17, &LCDDR18};
unsigned int num[10][4] = { {0x1, 0x5, 0x5, 0x1}, {0x0, 0x1, 0x1, 0x0}, {0x1, 0x1, 0xe, 0x1},{0x1, 0x1, 0xb, 0x1},{0x0, 0x5, 0xb, 0x0}, {0x1, 0x4, 0xb, 0x1}, {0x1, 0x4, 0xf, 0x1},{0x1, 0x1, 0x1, 0x0}, {0x1, 0x5, 0xf, 0x1},{0x1, 0x5, 0xb, 0x1} };

void LCD_Init()
{
	CLKPR = 0x80;
	CLKPR = 0x00;

	LCDCRB = (1<<LCDCS) | (1<<LCDMUX1)| (1<<LCDMUX0) | (1<<LCDPM2)| (1<<LCDPM1)| (1<<LCDPM0);						/* 1/3 Bias and 1/4 duty, SEG0:SEG24 is used as port pins CLEAR */
	LCDFRR = (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0)|(0<<LCDPS2) | (0<<LCDPS1) | (0<<LCDPS0);						/* Using 16 as prescaler selection and 8 as LCD Clock Divide ÁND gives a frame rate of 8.1  Hz  CHECK DESIRED FRAMERATE*/
	LCDCCR =  (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1)|(1<<LCDCC0) | (0<<LCDDC2) | (0<<LCDDC1)|(0<<LCDDC0);			/* Set segment drive time to 300 ms and output voltage to 3.35 V CLEAR */
	LCDCRA = (1<<LCDEN) |(0<<LCDBL)|(1<<LCDAB)|(0<<LCDIE);															/* Enable LCD, low power waveform and no interrupt enabled, no blanking */
}

void writeChar(char ch, int pos)
{
	//pos out of range
	//input chars
	ch -= 48;
	if (pos < 6 && pos > -1 && ch < 10 && ch > -1)
	{
		long i = floor((pos+2)/2)-1;													//creates correct index values for the pointers that declares what LCDDR should be accessed for the desired position.

		*point[i] = *point[i] + (num[ch][0] << (pos%2)*4);							//inserts the values for LCDDR0, LCDDR1 and LCDDR2					and shifts the hex values into the high nibbles if pos is 1,3 or 5.
		*point[i + 4] = *point[i + 4] + (num[ch][1] << (pos%2)*4);					//inserts the values for LCDDR5, LCDDR6 and LCDDR7					and shifts the hex values into the high nibbles if pos is 1,3 or 5.
		*point[i + 8] = *point[i + 8] + (num[ch][2] << (pos%2)*4);					//inserts the values for LCDDR10, LCDDR11 and LCDDR12				and shifts the hex values into the high nibbles if pos is 1,3 or 5.
		*point[i + 12] = *point[i + 12] + (num[ch][3] << (pos%2)*4);				//inserts the values for LCDDR15, LCDDR16 and LCDDR17				and shifts the hex values into the high nibbles if pos is 1,3 or 5.
	}
}

void clearChar1(int pos){
	if( pos == 0 || pos == 1)
	{
		LCDDR0 =0;
		LCDDR5 =0;
		LCDDR10 =0;
		LCDDR15 =0;
	}
	else if (pos == 3 || pos == 4){
		LCDDR1 =0;
		LCDDR2 =0;
		LCDDR6 =0;
		LCDDR7 =0;
		LCDDR11 =0;
		LCDDR12 =0;
		LCDDR16 =0;
		LCDDR17 =0;
	}
}


void printAt(long num, int pos) {
	
	int pp = pos;
	clearChar1(pp);
	writeChar( (num % 100) / 10 + '0', pp);		//writes the tens place
	
	//for (volatile int g=0; g<10000; g++){}
	pp++;
	writeChar( num % 10 + '0', pp);				// writes the ones place
	
}
void writeLong(GUI *self){
	printAt(self->frequency, self->side);
}


void updateGUI(GUI *self){
	if (self->frequency < 0){
		self->frequency = 0;
	}
	if (self->frequency > 99){
		self->frequency = 99;
	}
		
	clearChar1(self->side);
	printAt(self->frequency, self->side);
}

void start(GUI *self)
{
	printAt(self->frequency, self->side);
	ASYNC(self->pg1, outputPulse, 0);
	ASYNC(self->pg2, outputPulse, 0);
	
	
}



