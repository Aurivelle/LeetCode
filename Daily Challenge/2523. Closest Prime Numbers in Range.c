/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void SoE(int n, bool* prime)
{
    
    for(int p = 2; p * p <= n; p++)
    {
        if(prime[p] == true)
        {
            for(int i = p * p; i <= n; i+= p)
            {
                prime[i] = false;
            }
        }
    }
    
}
int* closestPrimes(int left, int right, int* returnSize) 
{
    *returnSize = 2;

    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;
    bool* prime = (bool*)malloc(sizeof(bool) * (right + 1));
    memset(prime, true, (right + 1) * sizeof(bool));
    prime[0] = prime[1] = false;
    SoE(right, prime);
    
     int prev = -1, minDiff = right - left + 1;
    for (int i = left; i <= right; i++) 
    {
        if (prime[i])
         {
            if (prev != -1 && (i - prev) < minDiff) 
            {
                minDiff = i - prev;
                ans[0] = prev;
                ans[1] = i;
            }
            prev = i;
        }
    }
    if(*returnSize < 2)
    {
        ans[0] = -1;
        ans[1] = -1;
    }
    free(prime);
    return ans;
    
}
