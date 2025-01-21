long long gridGame(int** grid, int gridSize, int* gridColSize) 
{
    long long top = 0;
    long long bottom = 0;
    long long minMax = LLONG_MAX;
    for(int i = 0; i < *gridColSize; i++)
    {
        top += (long long)grid[0][i];
    }    
    for(int i = 0; i < *gridColSize; i++)
    {
        top -= (long long)grid[0][i];
        long long second = (top > bottom) ? top : bottom;

        bottom += (long long)grid[1][i];

        if(second < minMax)
        {
            minMax = second;
        }
    }
    return minMax;
}
