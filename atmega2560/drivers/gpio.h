#include <stdint.h>
#include "address.h"

#ifndef GPIO_H
#define GPIO_H

#define OUT 1
#define IN 0

#define HIGH 1
#define LOW 0

int constrain_me(char port, int pin)
{
	if(pin > 7 || pin < 0 || port == 'I' || port > 'L' || port < 'A')
		return 1;
	return 0;
}
void MODE_SET(char dir, int pin, char mode)
{
	if(constrain_me(dir, pin))
		return;
	volatile unsigned char* ddr = (volatile unsigned char*) ddr_add[dir-65];
	
	uint8_t mask = (1 << pin);

	if(mode == 1)
		*ddr |= mask;
	else if(mode == 0)
	{
		mask = ~mask;
		*ddr &= mask;
	}
	else
		return;
}

void GIVE_OUT(char pt, int pin, char value)
{
	
	if(constrain_me(pt, pin))
		return;

	volatile unsigned char* port = (volatile unsigned char*) port_add[pt-65];

	uint8_t mask = (1 << pin);

	if(value == 1)
		*port |= mask;
	else if(value == 0)
	{
		mask = ~mask;
		*port &= mask;
	}
	else
		return;
}

#define PULLUP 1
#define PULLDOWN 0

int TAKE_IN(char pt, int pn, char resistor)
{
	if(constrain_me(pt,pn))
		return -1;
	uint8_t mask = ~(1 << pn);
	volatile unsigned char* port = (volatile unsigned char*) port_add[pt-65];
	volatile unsigned char* pin = (volatile unsigned char*) pin_add[pt-65];
	
	uint8_t status = 0;

	//Pull up or down desision making
	if(resistor == 1)
	{	status = 1;
		*port |= (1 << pn);
	}
	else if(resistor == 0)
	{	status = 0;
		*port &= mask;
	}
	
	uint8_t level = (*pin >> pn) & 1;   // read once, 0 or 1

	if(status == 1)                     // pull-up: pressed = low, so flip
		level = !level;
	                                    // pull-down: pressed = high, use as is
	return level;
}

void stay_still(unsigned long duration)
{
	for(volatile unsigned long i = 0; i < duration; i++)
	{
		//Nothing
	}
}

#endif		
