
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

bool isValid(int r, int c, int gridSize, int** grid, int** visited)
{
    return r >= 0 && r < gridSize && c >= 0 && c < gridSize && grid[r][c] == 0 && !visited[r][c];
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) 
{
    if(grid[0][0] == 1 || grid[gridSize - 1][gridSize - 1] == 1)
    {
        return -1;
    }
    if(grid[0][0] == 0 && gridSize == 1)
    {
        return 1;
    }

    int directions[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

    int** visited1 = (int**)malloc(sizeof(int*) * gridSize);
    int** visited2 = (int**)malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; i++)
    {
        visited1[i] = (int*)calloc(gridSize, sizeof(int));
        visited2[i] = (int*)calloc(gridSize, sizeof(int));
    }

    Node** queue1 = (Node**)malloc(sizeof(Node*) * gridSize * gridSize);
    int size1 = 0;
    int front1 = 0;
    int rear1 = 0;

    Node** queue2 = (Node**)malloc(sizeof(Node*) * gridSize * gridSize);
    int size2 = 0;
    int front2 = 0;
    int rear2 = 0;
    
    Node* start = createNode(0,0);
    Node* end = createNode(gridSize - 1, gridSize - 1);
    queue1[rear1++] = start;
    queue2[rear2++] = end;
    visited1[0][0] = 1;
    visited2[gridSize - 1][gridSize - 1] = 1;
    int steps = 1;
    while(front1 < rear1 && front2 < rear2)
    {
        if(rear1 - front1 > rear2 - front2)
        {
            Node** tempQueue = queue1;
            queue1 = queue2;
            queue2 = tempQueue;

            int tempsize = size1;
            size1 = size2;
            size2 = tempsize;

            int tempfront = front1;
            front1 = front2;
            front2 = tempfront;

            int temprear = rear1;
            rear1 = rear2;
            rear2 = temprear;

            int** tempvisited = visited1;
            visited1 = visited2;
            visited2 = tempvisited;
        }
        int currentsize = rear1 - front1;
        for(int i = 0; i < currentsize; i++)
        {
            Node* node = queue1[front1++];
            int r = node->r;
            int c = node->c;
            free(node);

            for(int j = 0; j < 8; j++)
            {
                int newr = r + directions[j][0];
                int newc = c + directions[j][1];
                if(isValid(newr, newc, gridSize, grid, visited1))
                {
                    if(visited2[newr][newc])
                    {
                        return steps + 1;
                    }
                    visited1[newr][newc] = 1;
                    queue1[rear1++] = createNode(newr, newc);
                }
            }
        }
        steps++;
    }   
    
    return -1;
}
