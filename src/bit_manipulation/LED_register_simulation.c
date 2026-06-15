#include<stdio.h>

int main()
{
	unsigned char LED = 0;
	LED |= (1<<2); // turning ON LED3
	LED &= ~(1<<2); //turning OFF LED3
	LED ^= (1<<2); //toggle LED 3
	if(LED & (1<<2))
	{
		printf("LED ON");
	}
	else
	{
		printf("LED OFF");
	}
}
