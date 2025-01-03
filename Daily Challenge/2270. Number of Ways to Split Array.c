int waysToSplitArray(int* nums, int numsSize) 
{
    if(numsSize == 1 || (numsSize == 2 && nums[0] < nums[1]))
    {
        return 0;
    }
    if(numsSize == 2 && nums[1] <= nums[0])
    {
        return 1;
    }
    long long left[numsSize];
    long long right[numsSize];
    left[0] = 0;
    right[numsSize - 1] = nums[numsSize - 1];
    for(int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] + (long long)nums[i - 1];
    }
    long long sum[numsSize];
    
    for(int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + (long long)nums[i];
    }
    int count = 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(left[i] >= right[i])
        {
            count++;
        }
    }
    return count;
}
