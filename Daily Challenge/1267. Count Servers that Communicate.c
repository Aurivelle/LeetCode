int countServers(int** grid, int gridSize, int* gridColSize) 
{
    int hashRow[gridSize];
    int hashColumn[*gridColSize];
    for(int i = 0; i < gridSize; i++)
    {
        hashRow[i] = 0;
    }
    for(int i = 0; i < *gridColSize; i++)
    {
        hashColumn[i] = 0;
    }
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < *gridColSize; j++)
        {
            if(grid[i][j])
            {
                hashRow[i]++;
                hashColumn[j]++;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < *gridColSize; j++)
        {
            if(grid[i][j])
            {
                if(hashRow[i] > 1 || hashColumn[j] > 1)
                {
                    count++;
                }
            }
        }
    }
    return count;    
}
