int max(int a, int b)
{
    return a > b ? a : b;
}
int rob(int* nums, int numsSize) 
{
    if(numsSize == 1)
    {
        return nums[0];
    }
    int dp[numsSize];
    for(int i = 0; i < numsSize; i++)
    {
        dp[i] = 0;
    }
    dp[0] = nums[0];
    dp[1] = max(nums[1], dp[0]);

    for(int i = 2; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[numsSize - 1];
}
