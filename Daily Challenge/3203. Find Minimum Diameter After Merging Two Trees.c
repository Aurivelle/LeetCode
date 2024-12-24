typedef struct
{
    int node;
    int dist;
}Node;

typedef struct
{
    int size;
    int capacity;
    int* neighbors;
}adjList;

adjList graph[100000];

void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        graph[i].size = 0;
        graph[i].capacity = 2;
        graph[i].neighbors = (int*)malloc(sizeof(int) * graph[i].capacity);
    }
}
void addEdge(int u, int v)
{
    if(graph[u].size == graph[u].capacity)
    {
        graph[u].capacity *= 2;
        graph[u].neighbors = (int*)realloc(graph[u].neighbors, sizeof(int) * graph[u].capacity);
    }
    graph[u].neighbors[graph[u].size++] = v;

    if(graph[v].size == graph[v].capacity)
    {
        graph[v].capacity *= 2;
        graph[v].neighbors = (int*)realloc(graph[v].neighbors, sizeof(int) * graph[v].capacity);
    }
    graph[v].neighbors[graph[v].size++] = u;

}
void dfs(int node, int parent, int dist, Node* result)
{
    if(dist > result->dist)
    {
        result->dist = dist;
        result->node = node;
    }
    for(int i = 0; i < graph[node].size; i++)
    {
        int neighbor = graph[node].neighbors[i];
        if(neighbor != parent)
        {
            dfs(neighbor, node, dist + 1, result);
        }
    }
}

int tree(int n)
{
    Node first = {0,0};
    dfs(0, -1, 0, &first);

    Node second = {first.node, 0};
    dfs(first.node, -1, 0, &second);
    return second.dist;
}
int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize) 
{
    int n1 = edges1Size + 1;
    int n2 = edges2Size + 1;

    init(n1);
    for(int i = 0; i < edges1Size; i++)
    {
        int u = edges1[i][0];
        int v = edges1[i][1];
        addEdge(u, v);
    }
    int d1 = tree(n1);
    int r1 = (d1 + 1) / 2;

    init(n2);
    for (int i = 0; i < edges2Size; i++) 
    {
        int u = edges2[i][0];
        int v = edges2[i][1];
        addEdge(u, v);
    }
    int d2 = tree(n2);
    int r2 = (d2 + 1) / 2;

    return d1 > d2 ? (d1 > r1 + r2 + 1 ? d1 : r1 + r2 + 1) : (d2 > r1 + r2 + 1 ? d2 : r1 + r2 + 1);

}
