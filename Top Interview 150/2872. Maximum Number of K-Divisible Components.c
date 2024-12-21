int dfs(int node, int parent, int** adjList, int* adjSize, int* values, int k, int* count)
{
    int sum = values[node];
    for(int i = 0; i < adjSize[node]; i++)
    {
        int child = adjList[node][i];
        if(child != parent)
        {
            sum += dfs(child, node, adjList, adjSize, values, k, count);
        }
    }
    if(sum % k == 0)
    {
        (*count)++;
        return 0;
    }
    return sum;
}
int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) 
{
    int** adjList = (int**)malloc(sizeof(int*) * n);
    int* adjSize = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        adjList[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }
    int count = 0;
    dfs(0, -1, adjList, adjSize, values, k, &count);
    for(int i = 0; i < n; i++)
    {
        free(adjList[i]);
    }
    free(adjList);
    free(adjSize);
    return count;
}
