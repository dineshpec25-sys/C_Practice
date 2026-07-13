#include<stdio.h>
#include<stdlib.h>

int *get_input(int *number_input)
{
	int *arr;
	printf("Enter the number of input:");
	scanf("%d",&(*number_input));
	if((*number_input)%2 == 0)
	{
		printf("There will be two odd one out now");
		return NULL;
	}
	arr=malloc(*number_input*sizeof(int));
	for(int i=0; i<*number_input; i++)
	{
		printf("Enter the element number %d : ", i);
		scanf("%d", &arr[i]);
	}
	return arr;
}

int finding_odd(int arr[], int size)
{
	int ans=0;
	for(int i=0 ;i < size; i++)
	{
		ans=ans^arr[i];
	}
	return ans;
}

int main()
{
	int result, size;
	int *arr=NULL;
	arr = get_input(&size);
	result=finding_odd(arr, size);
	printf("The odd one out : %d", result);
	free(arr);
}
