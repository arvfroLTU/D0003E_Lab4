/*
 * Lab4
 *
 * Created: 2022-01-21 08:12:45
 * Author : Arvid From, Albin Kuhlberg
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "GUI.h"
#include "tinytimber.h"
#include "output.h"
#include "pulseGen.h"


//PORTB = (1<<PB7 | 1<<PB6 | 1<<PB4 );																			// 7down, 6up, 4push, 3		
//PORTE = (1<<PE3 | 1<<PE2);																						//2left 3right
				
//PCMSK1 = (1<<PCINT15)|(1<<PCINT14)|(1<<PCINT13)|(1<<PCINT12)|(1<<PCINT11)|(1<<PCINT10)|(1<<PCINT9)|(1<<PCINT8); //carpet bombing with interrupts
//PCMSK0 =(1<<PCINT7)|(1<<PCINT6)|(1<<PCINT5)|(1<<PCINT4)|(1<<PCINT3)|(1<<PCINT2)|(1<<PCINT1)|(1<<PCINT0);

void  main(){
int j = 1;
GUI graphics = initGUI();
output op = initOutput();
pulseGen pg1 = initpulseGen(0,1000);
pulseGen pg2 = initpulseGen(4, 500)


//PORTE &= ~(1 << self->target);


oscilloscope(&op);
inputHandler(&graphics);
pulseGen left = initpulseGen(4, 1000);
pulseGen right = initpulseGen(6, 1000);

genPulse(&op, 0);
INSTALL(&obj1, meth1, IRQ_1);
INSTALL(&obj2, meth2, IRQ_2);
return TINYTIMBER(&output, genPulse(&op, 0), (&op, 0));


//INSTALL(&graphics,pulseControl(&graphics), IRQ_PCINT0);   //assumes that pcint0 is responsible for up down push
//INSTALL(&graphics sideControl(&graphics), IRQ_PCINT1);
//return TINYTIMBER(&graphics, inputHandler(&graphics), val);

}


