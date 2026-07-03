#include <stdio.h>

void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[], int low, int high)
{
	int pvoit=arr[high];
	int i=low-1;

	for(int j=low; j< high;j++)
	{
		if(arr[j] < pvoit)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}
void quicksort(int arr[], int low, int high)
{
	if(low >= high) return;

	int pi=partition(arr, low, high);

	quicksort(arr, low, pi-1);
	quicksort(arr, pi+1, high);
}
void printArray(int arr[], int num)
{
	for(int i=0; i<num; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[]={8,3,1,7,0,10,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Before : ");
	printArray(arr, n);

	quicksort(arr, 0, n-1);

	printf("After : ");
	printArray(arr, n);

}
