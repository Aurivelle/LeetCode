
void dfs(char** board, int r, int c, int row, int column, int*** visited, int*** change)
{
    if(r < 0 || c < 0 || r >= row || c >= column || (*visited)[r][c] || board[r][c] == 'X')
    {
        return;
    }
    (*visited)[r][c] = 1;
    (*change)[r][c] = 0;
    dfs(board, r + 1, c, row, column, visited, change);
    dfs(board, r - 1, c, row, column, visited, change);
    dfs(board, r, c + 1, row, column, visited, change);
    dfs(board, r, c - 1, row, column, visited, change);
}

void solve(char** board, int boardSize, int* boardColSize) 
{
    int row = boardSize;
    int column = *boardColSize;
    int** visited = (int**)malloc(sizeof(int*) * row);
    int** change = (int**)malloc(sizeof(int*) * row);
    for(int i = 0; i < row; i++)
    {
        visited[i] = (int*)malloc(sizeof(int) * column);
        change[i] = (int*)malloc(sizeof(int) * column);
        for(int j = 0; j < column; j++)
        {
            visited[i][j] = 0;
            change[i][j] = 1;
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i != 0 && i != row - 1 && j != 0 && j != column - 1)
            {
                continue;
            }
            else
            {
                if(board[i][j] == 'O')
                {
                    dfs(board, i, j, row, column, &visited, &change);
                }
            }
        }
    }
    for(int i = 0; i < row; i++)
    {
        free(visited[i]);
        for(int j = 0; j < column; j++)
        {
            
            if(change[i][j])
            {
                
                board[i][j] = 'X';
            }
        }
        free(change[i]);
    }
    
}
