
typedef struct
{
    int r;
    int c;
} Node;

Node* createNode(int r, int c)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node-> r = r;
    node-> c = c;
    return node;
}


void enqueue(Node** queue, Node* node, int* size, int capacity, int* rear)
{
    if(*size == capacity)
    {
        return;
    }
    printf("%d %d\n", node->r, node->c);
    queue[(*rear)++] = node;
    (*size)++;
}

Node* dequeue(Node** queue, int* size, int capacity, int* front)
{
    if(*size == 0)
    {
        return NULL;
    }
    Node* node = queue[(*front)++];
    (*size)--;
    return node;
}
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) 
{
    if(grid[0][0] == 1)
    {
        return -1;
    }
    if(grid[0][0] == 0 && gridSize == 1)
    {
        return 1;
    }
    Node** queue = (Node**)malloc(sizeof(Node*) * gridSize * gridSize);
    int capacity = gridSize * gridSize;
    int size = 0;
    int front = 0;
    int rear = 0;
    int count = 1;
    int** visited = (int**)malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; i++)
    {
        visited[i] = (int*)malloc(sizeof(int) * gridSize);
        for(int j = 0; j < gridSize; j++)
        {
            visited[i][j] = 0;
        }
    }
    Node* start = createNode(0, 0);
    visited[0][0] = 1;
    enqueue(queue, start, &size, capacity, &rear);
    while(front < rear)
    {
        int sizes = rear - front;
        count++;
        int directions[2][8] = {{1, 0, -1, 0, 1, 1, -1, -1}, {0, 1, 0, -1, 1, -1, 1, -1}};
        for(int i = 0; i < sizes; i++)
        {
            Node* node = dequeue(queue, &size, capacity, &front);

            int r = node->r;
            int c = node->c;
            free(node);
            for(int j = 0; j < 8; j++)
            {
                int newr = r + directions[0][j];
                int newc = c + directions[1][j];
                
                if(newr < 0 || newr >= gridSize || newc < 0 || newc >= gridSize || visited[newr][newc] || grid[newr][newc])
                {
                    continue;
                }
                if(newr == gridSize - 1 && newc == gridSize - 1)
                {
                    return count;
                }
                Node* newNode = createNode(newr, newc);
                visited[newr][newc] = 1;
                enqueue(queue, newNode, &size, capacity, &rear);
            }
        }
    }   
    
    return -1;
}
