bool isValid(int r, int c, int row, int column)
{
    return r >= 0 && c >= 0 && r < row && c < column;
}
int dfs(int** grid, int row, int column, int r, int c, int** visited)
{
    if(!isValid(r, c, row, column) || visited[r][c] || grid[r][c] == 0)
    {
        return 0;
    }
    visited[r][c] = 1;
    int sum = 0;
    sum += dfs(grid, row, column, r + 1, c, visited);
    sum += dfs(grid, row, column, r - 1, c, visited);
    sum += dfs(grid, row, column, r, c + 1, visited);
    sum += dfs(grid, row, column, r, c - 1, visited);
    sum += grid[r][c];
    return sum;
}
int findMaxFish(int** grid, int gridSize, int* gridColSize) 
{
    int** queue = (int**)malloc(gridSize * *gridColSize * sizeof(int*));
    int front = 0;
    int rear = 0;
    int** visited = (int**)malloc(gridSize *  sizeof(int*));

    for(int i = 0; i < gridSize * *gridColSize; i++)
    {
        queue[i] = (int*)malloc(sizeof(int) * 2);
    }
    for(int i = 0; i < gridSize; i++)
    {
        visited[i] = (int*)calloc(*gridColSize, sizeof(int));
        for(int j = 0; j < *gridColSize; j++)
        {
            if(grid[i][j] > 0)
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }
    int maximum = 0;
    for(int i = 0; i < rear; i++)
    {
        int sum  = dfs(grid, gridSize, *gridColSize, queue[i][0], queue[i][1], visited);
        if(maximum < sum)
        {
            maximum = sum;
        }
    }
     for (int i = 0; i < gridSize * *gridColSize; i++)
    {
        free(queue[i]);
    }
    free(queue);

    for (int i = 0; i < gridSize; i++)
    {
        free(visited[i]);
    }
    free(visited);
    return maximum;



    
    
}
