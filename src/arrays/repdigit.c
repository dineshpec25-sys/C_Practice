#include<stdio.h>
#include<stdbool.h>
int main()
{
	int size;
	scanf("%d", &size);
	int number=0;
	printf("Enter the number : ");
	scanf("%d", &number);
	bool num_map[10]={false};
	bool status=false;
	while(number > 0)
	{
		int dig=number%10;
		if(num_map[dig])
		{
			status=true;
			break;
		}
		num_map[dig]=true;
		number/=10;
	}
	if(status)
		printf("There is repeation");
	else
		printf("There is no repeation");
}

