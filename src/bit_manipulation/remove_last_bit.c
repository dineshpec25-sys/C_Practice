#include<stdio.h>

int main()
{
	int number;
	
	printf("Entre the number : ");
	scanf("%d",&number);

	int mask = ~(1 << 0);

	number &= mask;

	printf("The number : %d\n", number);
}
