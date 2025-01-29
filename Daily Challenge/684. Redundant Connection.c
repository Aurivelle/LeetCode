/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int* parent, int x)
{
    if(parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(int* parent, int* rank, int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if(rootX != rootY)
    {
        if(rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if(rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

}
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) 
{
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);
    int* parent = (int*)malloc(sizeof(int) * (edgesSize + 1));
    int* rank = (int*)calloc(edgesSize + 1, sizeof(int));

    for(int i = 0; i <= edgesSize; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if(find(parent, u) == find(parent, v))
        {
            ans[0] = u;
            ans[1] = v;
        }
        else
        {
            unionSets(parent, rank, u, v);
        }
    }
    free(parent);
    free(rank);
    return ans;
}
