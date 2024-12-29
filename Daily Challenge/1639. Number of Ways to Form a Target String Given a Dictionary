int numWays(char** words, int wordsSize, char* target) 
{
    long long mod = 1000000007;
    long long length = strlen(target);
    long long len = strlen(words[0]);
    long long freq[26][len];
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < len; j++)
        {
            freq[i][j] = 0;
        }
    }
    for(int i = 0; i < wordsSize; i++)
    {
        for(int j = 0; j < len; j++)
        {
            freq[words[i][j] - 'a'][j]++;
        }
    }

    long long dp[length + 1][len + 1];
    for(int i = 0; i <= length; i++)
    {
        for(int j = 0; j <= len; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i <= len; i++)
    {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= length; i++)
    {
        for(int j = 1; j <= len; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] * freq[target[i - 1] - 'a'][j - 1];
            dp[i][j] %= mod;
        }
    }
    return (int)dp[length][len];
}
