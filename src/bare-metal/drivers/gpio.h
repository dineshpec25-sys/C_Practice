#include <stdint.h>

#ifndef GPIO_H
#define GPIO_H

#define OUT 1
#define IN 0

#define HIGH 1
#define LOW 0

uint16_t ddr_add[12] = {0x21, 0x24, 0x27, 0x2A, 0x2D, 0x30, 0x33, 0x101, 0, 0x104, 0x107, 0x10A};
uint16_t port_add[12] = {0x22, 0x25, 0x28, 0x2B, 0x2E, 0x31, 0x34, 0x102, 0, 0x105, 0x108, 0x10B};

void MODE_SET(char dir, int pin, char mode)
{
	if(pin > 7 || pin < 0 || dir == 'I' || dir > 'L' || dir < 'A')
		return;
	//int ddr_add[11] = {0x21, 0x24, 0x27, 0x2A, 0x2D, 0x30, 0x33, 0x101, NULL, 0x104, 0x107, 0x10A};
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
	//	printf("Invalid Mode\n");
}

void GIVE_OUT(char pt, int pin, char value)
{
	//int port_add[12] = {0x22, 0x25, 0x28, 0x2B, 0x2E, 0x31, 0x34, 0x102, NULL, 0x105, 0x108, 0x10B};
	
	if(pt == 'I' || pt > 'L' || pt < 'A' || pin > 7 || pin < 0)
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
	//else
	//	printf("Invalid value\n");
}

void stay_still(unsigned long duration)
{
	for(volatile unsigned long i = 0; i < duration; i++)
	{
		//Nothing
	}
}

#endif
		
