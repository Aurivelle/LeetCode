int maximumCount(int* nums, int numsSize) 
{
    int p = 0;
    int n = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > 0)
        {
            p++;
        }
        else if(nums[i] < 0)
        {
            n++;
        }
    }    
    return p > n ? p : n;
}
