int waysToSplitArray(int* nums, int numsSize) 
{
    long long left[numsSize];
    long long sum = nums[0];
    left[0] = 0;
    for(int i = 1; i < numsSize; i++)
    {
        sum += nums[i];
        left[i] = left[i - 1] + (long long)nums[i - 1];
    }
    
    int count = 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(left[i] >= sum - left[i])
        {
            count++;
        }
    }
    return count;
}
