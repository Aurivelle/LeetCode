/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    bool** reachable = (bool**)malloc(sizeof(bool*) * numCourses);
    for(int i = 0; i < numCourses; i++)
    {
        reachable[i] = (bool*)calloc(numCourses, sizeof(bool));
        reachable[i][i] = true;
    }

    for(int i = 0; i < prerequisitesSize; i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        reachable[u][v] = true;
    }    
    for(int k = 0; k < numCourses; k++)
    {
        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < numCourses; j++)
            {
                reachable[i][j] |= (reachable[i][k] && reachable[k][j]);
            }
        }
    }
    *returnSize = queriesSize;
    bool* answer = (bool*)malloc(sizeof(bool) * queriesSize);
    for(int i = 0; i < queriesSize; i++)
    {
        int u = queries[i][0];
        int v = queries[i][1];
        answer[i] = reachable[u][v];
    }
    for(int i = 0; i < numCourses; i++)
    {
        free(reachable[i]);
    }
    free(reachable);
    return answer;
}
