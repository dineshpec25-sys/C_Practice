#include<stdio.h>
#include<stdlib.h>

int *get_input(int dynamic_array[], int *cap)
{
	int temp;
	printf("Entre the array element:");
	while(scanf("%d", &temp)==1)
	{
		(*cap)++;
		dynamic_array=realloc(dynamic_array, (*cap) * sizeof(int));
		dynamic_array[*cap-1]=temp;
	}
	return dynamic_array;
}
void display_number(int array[], int cap)
{
	for(int i =0;i<cap;i++)
	{
		printf("%d ",array[i]);
	}
}
int find_maxium(int array[], int cap)
{
	int max=array[0];
	for(int i=0;i<cap;i++)
	{
		if(array[i] > max)
			max=array[i];
	}
	return max;
}
int main()
{
	int capacity=0;
	int *dynamic_array=NULL;
	dynamic_array=get_input(dynamic_array, &capacity);
	display_number(dynamic_array, capacity);
	int max;
	max=find_maxium(dynamic_array, capacity);
	printf("\nThe Maxium:%d\n", max);
	free(dynamic_array);
}
