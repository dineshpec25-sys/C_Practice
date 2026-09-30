#include<stdio.h>

int main()
{
	int i;
	int number=0;

	printf("Enter the ith : ");
	scanf("%d", &i);

	int mask=(1 << i);
	number |= mask;

	printf("After set of ith bit : %d\n", number);
	return 0;
}
