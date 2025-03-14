

int maximumCandies(int* candies, int candiesSize, long long k) 
{
   long long left = 1, right = 0, mid;
   for(int i = 0; i < candiesSize; i++)
   {
    if(candies[i] > right)
    {
        right = candies[i];
    }
   }
   long long result = 0;
   while(left <= right)
   {
    mid = (left + right) / 2;
    long long count = 0;
    for(int i = 0; i < candiesSize; i++)
    {
        count += candies[i] / mid;
    }
    if(count >= k)
    {
        result = mid;
        left = mid + 1;
    }
    else
    {
        right = mid - 1;
    }


   }
   return result;
}
