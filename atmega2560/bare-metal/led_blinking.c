#include "/home/acer/C_Practice/src/drivers/gpio.h"

int main()
{
	mode(E, OUT);
	while(1)
	{
		status(E, HIGH);
		for(volatile int i = 0; i < 50000; i++)
		{
		}
		status(E, LOW);
	}
}
