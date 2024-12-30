int min(int a, int b)
{
    return a < b ? a : b;
}
int countGoodStrings(int low, int high, int zero, int one) 
{
    long long mod = 1000000007;
    long long dp[high + 1];
    for(int i = 0; i <= high; i++)
    {
        dp[i] = 0;
    }
    dp[one]++;
    dp[zero]++;
    int small = min(zero, one);
    for(int i = small; i <= high; i++)
    {
        if(i - one >= 0)
        {
            dp[i] += dp[i - one];
        }
        if(i - zero >= 0)
        {
            dp[i] += dp[i - zero];
            dp[i] %= mod;
        }
    }
    long long sum = 0;
    for(int i = low; i <= high; i++)
    {
        sum += dp[i];
        sum %= mod;
    }
    
    return (int)sum;

}
