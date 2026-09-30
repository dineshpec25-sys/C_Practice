#include<stdio.h>

int main()
{
	int number;

	printf("Entre the number : ");
	scanf("%d", &number);

	int i;
	printf("Entre the i : ");
	scanf("%d", &i);

	int mask = (1 << i);
	number ^= mask;
	printf("The number : %d\n", number);
}
