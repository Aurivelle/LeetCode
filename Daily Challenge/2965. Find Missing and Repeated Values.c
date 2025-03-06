/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) 
{
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);
    int* hash = (int*)malloc(sizeof(int) * gridSize * *gridColSize);

    for(int i = 0; i < gridSize * *gridColSize; i++)
    {
        hash[i] = 0;
        
    }

    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < *gridColSize; j++)
        {
            hash[grid[i][j] - 1]++;
        }
    }
    int count = 0;
    for(int i = 0; i < gridSize * *gridColSize; i++)
    {
        
        if(hash[i] == 2)
        {
            ans[0] = i + 1;
            count++;
        }
        else if(hash[i] == 0)
        {
            ans[1] = i + 1;
            count++;
        }
        if(count == 2)
        {
            break;
        }
        
    }
    return ans;
}
