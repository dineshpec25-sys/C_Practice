#include<stdio.h>

int odd_or_even(int number)
{
	int mask = (1 << 0);
	return number & mask;
}

int main()
{
	int number;

	printf("Entre the number : ");
	scanf("%d", &number);

	if(odd_or_even(number))
		printf("Odd\n");
	else
		printf("Even\n");
}
	
