/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct
{
    int num;
    int* neighbors;
    int size;
    int capacity;
} Node;

Node* createNode(int num)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
    node->size = 0;
    node->capacity = 2;
    node->neighbors = (int*)malloc(sizeof(int) * node->capacity);
    return node;
}

void expand(Node* node)
{
    node->capacity *= 2;
    node->neighbors = (int*)realloc(node->neighbors, sizeof(int) * node->capacity);
}

void addEdge(Node* node, int num)
{
    if(node->size == node->capacity)
    {
        expand(node);
    }
    node->neighbors[node->size++] = num;
}

bool dfs(Node** nodes, Node* node, int answer, bool* visited)
{
    if(visited[node->num])
    {
        return false;
    }
    if(answer == node->num)
    {
        return true;
    }
    visited[node->num] = true;
    bool ret = false;
    for(int i = 0; i < node->size; i++)
    {
        ret |= dfs(nodes, nodes[node->neighbors[i]], answer, visited);
    }
    visited[node->num] = false;
    return ret;
}

bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    Node** nodes = (Node**)malloc(sizeof(Node*) * numCourses);
    bool* visited = (bool*)malloc(sizeof(bool) * numCourses);
    for(int i = 0; i < numCourses; i++)
    {
        nodes[i] = createNode(i);
        visited[i] = false;
    }
    *returnSize = 0;
    for(int i = 0; i < prerequisitesSize; i++)
    {
        addEdge(nodes[prerequisites[i][0]], prerequisites[i][1]);
    }
    bool* answer = (bool*)malloc(sizeof(bool) * queriesSize);
    for(int i = 0; i < queriesSize; i++) 
    {
        answer[(*returnSize)++] = dfs(nodes, nodes[queries[i][0]], queries[i][1], visited);
    }   
    free(visited);
    for(int i = 0; i < numCourses; i++)
    {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
    free(nodes);
    return answer;


}
