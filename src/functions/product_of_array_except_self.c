/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int remaining_product(int* arr, int size, int target)
{
    int product=1;
    for(int i = 0; i < size; i++)
    {
        if(i == target) continue;
        product *= arr[i];
    }
    return product;
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer;
    answer=malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++)
    {
        answer[i] = remaining_product(nums, numsSize, i);
    }

    return answer;
}
