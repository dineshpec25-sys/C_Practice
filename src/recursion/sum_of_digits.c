#include <stdio.h>
int sum_of_digits(int num)
{
	if(num / 10 == 0)
		return num;
	else
		return (num % 10) + sum_of_digits((num/10));
}
int main()
{
	int num;
	printf("Entre the number : ");
	scanf("%d", &num);

	printf("The sum of digits : %d\n", sum_of_digits(num));
}
