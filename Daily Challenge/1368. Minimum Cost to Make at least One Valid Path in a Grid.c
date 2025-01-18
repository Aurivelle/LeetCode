typedef struct 
{
    int r;
    int c;
    int cost;
} Node;

Node* createNode(int r, int c, int cost)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->r = r;
    node->c = c;
    node->cost = cost;
    return node;
}

void pushFront(Node** queue, Node* node, int* front)
{
    queue[--(*front)] = node;
}

void pushBack(Node** queue, Node* node, int* rear)
{
    queue[(*rear)++] = node;
}   

Node* popFront(Node** queue, int* front)
{
    return queue[(*front)++];
}

bool isValid(int r, int c, int gridSize, int gridColSize)
{
    if(r < 0 || r >= gridSize || c < 0 || c >= gridColSize)
    {
        return false;
    }
    return true;
}
int minCost(int** grid, int gridSize, int* gridColSize) 
{
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int capacity = gridSize * *gridColSize;
    Node** queue = (Node**)malloc(sizeof(Node*) * capacity * 2);
    int** cost = (int**)malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; i++)
    {
        cost[i] = (int*)malloc(sizeof(int) * *gridColSize);
        for(int j = 0; j < *gridColSize; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }

    int front = capacity;
    int rear = capacity;
    Node* start = createNode(0, 0, 0);
    pushFront(queue, start, &front);
    cost[0][0] = 0;
    while(front < rear)
    {   
        Node* node = popFront(queue, &front);
        int r = node->r;
        int c = node->c;
        int currentCost = node->cost;

        if(r == gridSize - 1 && c == *gridColSize - 1)
        {
            free(node);
            for(int i = 0; i < gridSize; i++)
            {
                free(cost[i]);
            }
            free(cost);
            free(queue);
            return currentCost;
        }

        for(int i = 0; i < 4; i++)
        {
            int newr = r + directions[i][0];
            int newc = c + directions[i][1];
            if(isValid(newr, newc, gridSize, *gridColSize))
            {
                int newCost = currentCost + (i + 1 == grid[r][c] ? 0 : 1);

                if(newCost < cost[newr][newc])
                {
                    cost[newr][newc] = newCost;
                    if(newCost == currentCost)
                    {
                        pushFront(queue, createNode(newr, newc, newCost), &front);
                    }
                    else
                    {
                        pushBack(queue, createNode(newr, newc, newCost), &rear);
                    }
                }
            }
        }
        free(node);
    }
    for(int i = 0; i < gridSize; i++)
    {
        free(cost[i]);
    }
    free(cost);
    free(queue);
    return -1;

}
