/*
 * Lab4
 *
 * Created: 2022-01-21 08:12:45
 * Author : Arvid From, Albin Kuhlberg
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "tinytimber.h"
#include "output.h"
#include "pulseGen.h"
#include "General.h"


int main(void){
	
PORTB = (1<<PB7 | 1<<PB6 | 1<<PB4 );																			//7down, 6up, 4push, 3
PORTE = (1<<PE3 | 1<<PE2);																						//2left 3right
PCMSK1 = (1<<PCINT15)|(1<<PCINT14)|(1<<PCINT13)|(1<<PCINT12)|(1<<PCINT11)|(1<<PCINT10)|(1<<PCINT9)|(1<<PCINT8); //carpet bombing with interrupts
PCMSK0 =(1<<PCINT7)|(1<<PCINT6)|(1<<PCINT5)|(1<<PCINT4)|(1<<PCINT3)|(1<<PCINT2)|(1<<PCINT1)|(1<<PCINT0);
EIMSK |= (1 << PCIE1) | (1 << PCIE0);
PORTE |= (0 << PE4) | (0 << PE6);
DDRE |= (1 << DDE4) | (1 << DDE6);


output op = initOutput(0);				//initialize output with state 0
pulseGen pg1 = initpulseGen(0, 0, &op);
pulseGen pg2 = initpulseGen(1, 4, &op);
GUI	graphics = initGUI(&pg1, &pg2);
General Gnrl = initGeneral(&pg1, &pg2, &graphics);

LCD_Init();

INSTALL(&Gnrl, LRBuffer, IRQ_PCINT0);
INSTALL(&Gnrl, UpDownPushBuffer, IRQ_PCINT1);
return TINYTIMBER(&graphics, start, 0);
}