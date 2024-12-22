/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    int* stack = (int*)malloc(sizeof(int) * heightsSize);
    int* nextHigher = (int*)malloc(sizeof(int) * heightsSize);
    int top = -1;
   
    for(int i = heightsSize - 1; i >= 0; i--)
    {
        while(top >= 0 && heights[stack[top]] <= heights[i])
        {
            top--;
        }
        nextHigher[i] = (top >= 0)? stack[top] : -1;
        stack[++top] = i;
    }
    free(stack);

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
            int current = Bob;
            while(current != -1 && heights[current] <= heights[Alice])
            {
                current = nextHigher[current];
            }
            ret[i] = current;
        }
    }
    free(nextHigher);
    return ret;

}
