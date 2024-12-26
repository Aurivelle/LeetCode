
int findTargetSumWays(int* nums, int numsSize, int target) 
{
    int total = 0;
    for(int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    if((total + target) % 2 || total < abs(target))
    {
        return 0;
    }
    total = (total + target) / 2;
    int* dp = (int*)malloc(sizeof(int) * (total + 1));
    for(int i = 0; i < total + 1; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = total; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }
    int sum = dp[total];
    free(dp);
    return sum;
}
