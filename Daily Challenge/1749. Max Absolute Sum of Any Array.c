int maxAbsoluteSum(int* nums, int numsSize) 
{
    int maxSum = 0;
    int currentMax = 0;
    int minSum = 0;
    int currentMin = 0;
    for(int i = 0; i < numsSize; i++)
    {
        currentMax += nums[i];
        if(currentMax < 0)
        {
            currentMax = 0;
        }
        if(currentMax > maxSum)
        {
            maxSum = currentMax;
        }

        currentMin += nums[i];
        if(currentMin > 0)
        {
            currentMin = 0;
        }
        if(currentMin < minSum)
        {
            minSum = currentMin;
        }
    }
    return abs(maxSum) > abs(minSum) ? abs(maxSum) : abs(minSum);
}
