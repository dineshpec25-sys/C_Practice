#include<stdio.h>

int clear_bit(int target, int i)
{
	int mask=~(1 << i);
	return target &= mask;
}

int main()
{
	int i;
	int number;

	printf("Entre the target number : ");
	scanf("%d", &number);
	
	printf("Entre the ith : ");
	scanf("%d", &i);
	
	number=clear_bit(number,i);

	printf("The number : %d\n", number);
}
