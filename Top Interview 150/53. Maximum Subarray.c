int maxSubArray(int* nums, int numsSize) 
{
    if(numsSize == 1)
    {
        return nums[0];
    }

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i - 1] > 0)
        {
            nums[i] += nums[i - 1];
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }   
    return max;
}
