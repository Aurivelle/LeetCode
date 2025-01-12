void dfs(char** board, int row, int column, int r, int c, char* word, int** visited, int count, int len, bool* ans)
{
    if(r < 0 || c < 0 || r >= row || c >= column || count >= len || board[r][c] != word[count] || visited[r][c])
    {
        return;
    }
    visited[r][c] = 1;
    if(count == len - 1)
    {
        *ans = true;
        return;
    }
    dfs(board, row, column, r + 1, c, word, visited, count + 1, len, ans);
    dfs(board, row, column, r - 1, c, word, visited, count + 1, len, ans);
    dfs(board, row, column, r, c + 1, word, visited, count + 1, len, ans);
    dfs(board, row, column, r, c - 1, word, visited, count + 1, len, ans);
    visited[r][c] = 0;
}


bool exist(char** board, int boardSize, int* boardColSize, char* word) 
{
    int row = boardSize;
    int column = *boardColSize;
    int len = strlen(word);
    bool ans = false;
    int** visited = (int**)malloc(sizeof(int*) * row);

    for(int i = 0; i < row; i++)
    {
        visited[i] = (int*)malloc(sizeof(int) * column);
        for(int j = 0; j < column; j++)
        {
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            dfs(board, row, column, i, j, word, visited, 0, len, &ans);
            if(ans == true)
            {
                return ans;
            }
        }
    }
    return ans;

}
