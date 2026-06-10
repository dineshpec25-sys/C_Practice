void sortColors(int* nums, int numsSize) {
    int slow=0;
    int fast=0;
    int target=0;
    for(fast;fast<numsSize;fast++)
    {
        if(nums[slow]==0)
        {
            slow++;
            continue;
        }
        else if(nums[fast]==0)
        {
            target=nums[slow];
            nums[slow]=nums[fast];
            nums[fast]=target;
            slow++;
        }
    }
    fast=slow;
    for(fast;fast<numsSize;fast++)
    {
        if(nums[slow]==1)
        {
            slow++;
            continue;
        }
        else if(nums[fast]==1)
        {
            target=nums[slow];
            nums[slow]=nums[fast];
            nums[fast]=target;
            slow++;
        }
    }
}