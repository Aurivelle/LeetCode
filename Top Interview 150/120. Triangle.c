int dfs(int** triangle, int rnum, int row, int cnum, int column, int* columns)
{
    if(rnum == row - 1)
    {
        return triangle[rnum][cnum];
    }
    int ret = dfs(triangle, rnum + 1, row, cnum, columns[rnum + 1], columns) < dfs(triangle, rnum + 1, row, cnum + 1, columns[rnum + 1], columns)?
        dfs(triangle, rnum + 1, row, cnum, columns[rnum + 1], columns) : dfs(triangle, rnum + 1, row, cnum + 1, columns[rnum + 1], columns);
    return ret + triangle[rnum][cnum];
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) 
{
    int min = dfs(triangle, 0, triangleSize, 0, triangleColSize[0], triangleColSize);
    return min;
}
