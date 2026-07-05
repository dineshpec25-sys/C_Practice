#include<stdio.h>

int main()
{
	unsigned char LED = 0b00000001;

	printf("Initial patter: ");
	for(int i=7;i>=0;i--) printf("%d", (LED >> i) & 1);
	printf("\n");
	
	for(int i=0; i < 7; i++)
	{
		LED<<=1;
		printf("Step %d:                      ", i+1);
		for(int i=7;i>=0;i--) printf("%d", (LED >> i) & 1);
		printf("\n");
	}

}
