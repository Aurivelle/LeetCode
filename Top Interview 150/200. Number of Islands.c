void dfs(char** grid, int r, int c, int row, int column)
{
    if(r < 0 || r >= row || c < 0 || c >= column || grid[r][c] == '0')
    {
        return;
    }

    grid[r][c] = '0';
    dfs(grid, r + 1, c, row, column);
    dfs(grid, r, c + 1, row, column);
    dfs(grid, r - 1, c, row, column);
    dfs(grid, r, c - 1, row, column);
}
int numIslands(char** grid, int gridSize, int* gridColSize) 
{
    if(gridSize * *gridColSize == 0)
    {
        return 0;
    }
    int column = *gridColSize;
    int row = gridSize;

    int count = 0;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j, row, column);
            }
        }
    }
    return count;
}
