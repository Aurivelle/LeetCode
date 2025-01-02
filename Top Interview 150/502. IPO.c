int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) 
{
    int n = profitsSize;
    int max;
    int maxidx;
    for(int i = 0; i < k; i++)
    {
        max = -1;
        maxidx = -1;
        for(int j = 0; j < n; j++)
        {
            if(w >= capital[j])
            {
                if(profits[j] > max)
                {
                    max = profits[j];
                    maxidx = j;
                }
            }      
        }
        if(max == -1)
        {
            break;
        }
        w += max;
        profits[maxidx] = -1;
    }
    return w;
}
