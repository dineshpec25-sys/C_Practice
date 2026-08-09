#include<stdio.h>

#define ARRAY_SIZE 100

int get_input(int* arr)
{
	int temp=0;
	printf("The Number of elements : ");
	scanf("%d", &temp);

	for(int i = 0; i < temp ; i++)
	{
		printf("%dth Element : ", i);
		scanf("%d", (arr + i));
	}
	return temp;
}

int array_addition(int* arr, int size)
{
	int sum=0;
	for(int i = 0; i < size; i++)
	{
		sum+=*(arr+i);
	}
	return sum;
}

int main()
{
	int arr[ARRAY_SIZE];
	int size, sum;
	size=get_input(arr);
	sum=array_addition(arr, size);
	printf("The Sum : %d\n", sum);
}
