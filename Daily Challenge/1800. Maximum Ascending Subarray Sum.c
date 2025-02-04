int maxAscendingSum(int* nums, int numsSize) 
{
    int max = 0;
    int sum = nums[0];
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] < nums[i + 1])
        {
            sum += nums[i + 1];
        }
        else
        {
            max = max > sum ? max : sum;
            sum = nums[i + 1];
        }
    }  
    max = max > sum ? max : sum;
    return max;
}
