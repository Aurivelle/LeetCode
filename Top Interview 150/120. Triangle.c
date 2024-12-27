int min(int a, int b)
{
    return a < b ? a : b;
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) 
{
    if(triangleSize == 1)
    {
        return triangle[0][0];
    }
    int minn = INT_MAX;
    for(int i = 1; i < triangleSize; i++)
    {
        
        for(int j = 0; j < triangleColSize[i]; j++)
        {
            if(j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if(j == triangleColSize[i] - 1)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            if(i == triangleSize - 1)
            {
                if(triangle[i][j] < minn)
                {
                    minn = triangle[i][j];
                }
            }
        }
    }
    return minn;
}
