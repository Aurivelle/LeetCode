int minSubArrayLen(int target, int* nums, int numsSize) 
{
    if(numsSize < 2)
    {
        if(nums[0] >= target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int left = 0;
    int right = left;
    int sum = nums[left];
    int min = INT_MAX;
    while(right < numsSize)
    {
        if(sum >= target)
        {
            if(right - left + 1 < min)
            {
                min = right - left + 1;
            }
            sum -= nums[left++];
        }
        else
        {
            right++;
            if(right < numsSize)
            {
                sum += nums[right];
            }
        }
    }
    if(min == INT_MAX)
    {
        return 0;
    }
    return min;
}
