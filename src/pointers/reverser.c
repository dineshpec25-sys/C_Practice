#include<stdio.h>

#define SIZE 100

int get_input(int* arr)
{
	int size;
	printf("The Number of elements : ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++)
	{
		printf("%dth element : ", i);
		scanf("%d", (arr+i));
	}

	return size;
}

void reverser(int* arr, int size)
{
	int left = 0;
	int right = size-1;
	while(left < right)
	{
		int temp = *(arr + right);
		*(arr + right--) = *(arr + left);
		*(arr + left++) = temp;
	}
}

void print_array(int* arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

int main()
{
	int arr[SIZE];
	int size = 0;
	size=get_input(arr);
	reverser(arr, size);
	print_array(arr, size);
}
