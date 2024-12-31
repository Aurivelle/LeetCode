int mincostTickets(int* days, int daysSize, int* costs, int costsSize) 
{
    int set[366] = {0};
    for(int i = 0; i < daysSize; i++)
    {
        set[days[i]]++;
    }
    int dp[days[daysSize - 1] + 1];
    for(int i = 0; i <= days[daysSize - 1]; i++)
    {
        dp[i] = 0;
    }
    for(int i = 1; i <= days[daysSize - 1]; i++)
    {
        if(!set[i])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            int smallest = costs[0] + dp[i - 1];
            if(i - 7 >= 0 && costs[1] + dp[i - 7] <= smallest)
            {
                smallest = costs[1] + dp[i - 7];
            }
            else if(i - 7 < 0)
            {
                if(costs[1] < smallest)
                {
                    smallest = costs[1];
                }
            }
            if(i - 30 >= 0 && costs[2] + dp[i - 30] < smallest)
            {
                smallest = costs[2] + dp[i - 30];
            }
            else if(i - 30 < 0)
            {
                if(costs[2] < smallest)
                {
                    smallest = costs[2];
                }
            }
            dp[i] = smallest;
            
        }
    }
    return dp[days[daysSize - 1]];
    
}
