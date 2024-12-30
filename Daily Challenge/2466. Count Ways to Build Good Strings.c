int countGoodStrings(int low, int high, int zero, int one) 
{
    int mod = 1000000007;
    long long dp[high + 1];
    for(int i = 0; i <= high; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i <= high; i++)
    {
        if(i - one >= 0)
        {
            dp[i] += dp[i - one];
        }
        if(i - zero >= 0)
        {
            dp[i] += dp[i - zero];
        }
        dp[i] %= mod;
    }
    int sum = 0;
    for(int i = low; i <= high; i++)
    {
        sum += dp[i];
        sum %= mod;
    }
    
    return sum;

}
