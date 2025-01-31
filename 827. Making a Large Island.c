# define MAX_ISLANDS 250000
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int** grid, int gridSize, int x, int y, int islandId)
{
    if(x < 0 || x >= gridSize || y < 0 || y >= gridSize || grid[x][y] != 1)
    {
        return 0;
    }
    grid[x][y] = islandId;
    int area = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        area += dfs(grid, gridSize, nx, ny, islandId);
    }
    return area;
}
int largestIsland(int** grid, int gridSize, int* gridColSize) 
{
    int islandArea[MAX_ISLANDS] = {0};
    int islandId = 2;
    int maxArea = 0;
    int hasZero = 0;

    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridSize; j++)
        {
            if(grid[i][j] == 1)
            {
                islandArea[islandId] = dfs(grid, gridSize, i, j, islandId);
                maxArea = (islandArea[islandId] > maxArea)? islandArea[islandId] : maxArea;
                islandId++;
            }
            if(grid[i][j] == 0)
            {
                hasZero = 1;
            }
        }
    }

    if(!hasZero)
    {
        return gridSize * gridSize;
    }
    if(islandId == 2)
    {
        return 1;
    }
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridSize; j++)
        {
            if(grid[i][j] == 0)
            {
                int seen[MAX_ISLANDS] = {0};
                int newArea = 1;
                for(int k = 0; k < 4; k++)
                {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];
                    if(ni >= 0 && ni < gridSize && nj >= 0 && nj < gridSize && grid[ni][nj] > 1)
                    {
                        int island = grid[ni][nj];
                        if(!seen[island])
                        {
                        newArea += islandArea[island];
                        seen[island] = 1;
                        }
                    }
                }
                
                maxArea = (newArea > maxArea)? newArea : maxArea;
            }
        }
    }
    return maxArea;
}
