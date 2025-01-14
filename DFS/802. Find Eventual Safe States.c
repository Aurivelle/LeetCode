/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int* neighbors;
    int size;
    int capacity;
} Node;

Node* createNode(int num)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->size = 0;
    node->capacity = 2;
    node->neighbors = (int*)malloc(sizeof(int) * 2);
    return node;
}

void addEdge(Node* node, int num)
{
    if(node->size == node->capacity)
    {
        node->capacity *= 2;
        node->neighbors = (int*)realloc(node->neighbors, sizeof(int) * node->capacity);
    }
    node->neighbors[node->size++] = num;
}
bool dfs(Node** nodes, int num, int* visited)
{
    if(visited[num] != 0)
    {
        return visited[num] == 2;
    }
    
    visited[num] = 1;
    for(int i = 0; i < nodes[num]->size; i++)
    {
        if(!dfs(nodes, nodes[num]->neighbors[i], visited))
        {
            return false;
        }
        
    }

    visited[num] = 2;
    return true;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) 
{
    Node** nodes = (Node**)malloc(sizeof(Node*) * graphSize);
    int* visited = (int*)malloc(sizeof(int) * graphSize);
    int* answer = (int*)malloc(sizeof(int) * graphSize);
    for(int i = 0; i < graphSize; i++)
    {
        visited[i] = 0;
        nodes[i] = createNode(i);
    }
    
    for(int i = 0; i < graphSize; i++)
    {
        for(int j = 0; j < graphColSize[i]; j++)
        {
            addEdge(nodes[i], graph[i][j]);
        }
    }

    *returnSize = 0;
    for(int i = 0; i < graphSize; i++)
    {

        if(dfs(nodes, i, visited))
        {
            answer[(*returnSize)++] = i;
        }
    }
    for (int i = 0; i < graphSize; i++) 
    {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
    free(nodes);
    free(visited);
    return answer;
}
