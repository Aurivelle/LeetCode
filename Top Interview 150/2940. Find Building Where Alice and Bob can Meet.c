/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    *returnSize = queriesSize;
    int* ret = (int*)malloc(sizeof(int) * *returnSize);
    for(int i = 0; i < queriesSize; i++)
    {
        ret[i] = -1;
        if(queries[i][0] > queries[i][1])
        {
            int temp = queries[i][1];
            queries[i][1] = queries[i][0];
            queries[i][0] = temp;
        }
        int Alice = queries[i][0];
        int Bob = queries[i][1];
        if(queries[i][0] == queries[i][1] || heights[Alice] < heights[Bob])
        {
            ret[i] = queries[i][1];
        }
        else
        {
            for(int j = Bob + 1; j < heightsSize; j++)
            {
                if(heights[j] > heights[Alice])
                {
                    ret[i] = j;
                    break;
                }
            }
        }
    }
    return ret;

}
