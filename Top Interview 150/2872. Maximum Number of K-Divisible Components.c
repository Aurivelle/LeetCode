
typedef struct {
    int* neighbors;
    int size;
    int capacity;
} AdjListNode;

void initAdjListNode(AdjListNode* node) 
{
    node->size = 0;
    node->capacity = 2;
    node->neighbors = (int*)malloc(node->capacity * sizeof(int));
}

void addNeighbor(AdjListNode* node, int neighbor) 
{
    if (node->size == node->capacity) 
    {
        node->capacity *= 2;
        node->neighbors = (int*)realloc(node->neighbors, node->capacity * sizeof(int));
    }
    node->neighbors[node->size++] = neighbor;
}

void freeAdjListNode(AdjListNode* node) 
{
    free(node->neighbors);
}

long long dfs(int node, int parent, AdjListNode* adjList, int* values, int k, int* count) 
{
    long long sum = values[node];

    for (int i = 0; i < adjList[node].size; i++) 
    {
        int child = adjList[node].neighbors[i];
        if (child != parent)
        {
            sum += dfs(child, node, adjList, values, k, count);
        }
    }

    if (sum % k == 0) 
    {
        (*count)++;
        return 0;
    }
    return sum;
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) 
{

    AdjListNode* adjList = (AdjListNode*)malloc(n * sizeof(AdjListNode));
    for (int i = 0; i < n; i++) {
        initAdjListNode(&adjList[i]);
    }

    for (int i = 0; i < edgesSize; i++) 
    {
        int u = edges[i][0], v = edges[i][1];
        addNeighbor(&adjList[u], v);
        addNeighbor(&adjList[v], u);
    }

    int count = 0;

    dfs(0, -1, adjList, values, k, &count);

    for (int i = 0; i < n; i++) 
    {
        freeAdjListNode(&adjList[i]);
    }
    free(adjList);

    return count;
}
