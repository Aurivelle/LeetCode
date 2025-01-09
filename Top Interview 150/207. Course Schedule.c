typedef struct Node
{
    int size;
    int capacity;
    int* neighbors;
    int status; // 0 not visited 1 visiting 2 visited
} Node;

Node* createNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->size = 0;
    node->capacity = 2;
    node->neighbors = (int*)malloc(sizeof(int) * 2);
    return node;
}

void addEdge(Node* u, int v)
{
    if(u->size == u->capacity)
    {
        u->capacity *= 2;
        u->neighbors = (int*)realloc(u->neighbors, sizeof(int) * u->capacity);
    }

    u->neighbors[u->size++] = v;
}

void dfs(Node** arr, Node* node, bool* ans)
{
    if(node->status == 2)
    {
        return;
    }
    if(node->status == 1)
    {
        *ans = false;
        return;
    }
    node->status = 1;
    for(int i = 0; i < node->size; i++)
    {
        dfs(arr, arr[node->neighbors[i]], ans);
    }
    node->status = 2;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    Node* node[numCourses];
    bool ans = true;
    for(int i = 0; i < numCourses; i++)
    {
        node[i] = createNode();
    }    
    for(int i = 0; i < prerequisitesSize; i++)
    {
        if(prerequisites[i][1] == prerequisites[i][0])
        {
            return false;
        }
        addEdge(node[prerequisites[i][1]], prerequisites[i][0]);
    }
    for(int i = 0; i < numCourses; i++)
    {
        dfs(node, node[i], &ans);
    }
    return ans;
}
