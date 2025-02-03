int longestMonotonicSubarray(int* nums, int numsSize) 
{
    int max = 1;
    int head = 0;
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] > nums[i + 1])
        {
            
            if(i == numsSize - 2)
            {
                max = max > i - head + 2? max : i - head + 2;
            }
            continue;
        }
        else
        {
            max = max > i - head + 1? max : i - head + 1;
            head = i + 1;
        }
    }
    head = 0;
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] < nums[i + 1])
        {
            if(i == numsSize - 2)
            {
                max = max > i - head + 2? max : i - head + 2;
            }
            continue;
        }
        else
        {
            max = max > i - head + 1? max : i - head + 1;
            head = i + 1;
        }
    }
    return max;
}
