// Merge sort
// It is know for its efficiency and stability
// It follows Divide and Conqure apporach
// It recurvesly divides the array and sort them and merge them to form a sorted array
//
// The steps:
// 1. Divide : divide the given array by halve until no further can be divided
// 2. Conqure : sort the subarray 
// 3. Merge : merge the sorted sub array to get the sorted array
//

#include<stdio.h>

void divide(int *arr, int start, int end, int n)
{
    if(end == 0 || end-n == 0)
    {
        return;
    }
    int mid = (start+end)/2;
    divide(arr, 

void sort(int *arr, int n)
{   
    int mid = (0+(n-1))/2; //identifying the boundary
    divide(arr,0,mid, n);

int main()
{
    int arr[]={8,5,3,9,11};
    int n = 5;

    sort(arr, n);
    dis(arr, n);
}
