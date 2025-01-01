typedef struct
{
    int x;
    int y;
}Point;

typedef struct
{
    Point* data;
    int front;
    int rear;
    int size;
    int capacity;
}Queue;

Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Point*)malloc(sizeof(Point) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}
int isEmpty(Queue* queue)
{
    return queue->size == 0;
}

void enqueue(Queue* queue, Point p)
{
    if(queue->size == queue->capacity)
    {
        return;
    }
    queue->data[queue->rear] = p;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

Point dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        return (Point){-1, -1};
    }

    Point p = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return p;
}

void bfs(char** grid, int r, int c, int row, int column)
{
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    Queue* queue = createQueue(row * column);
    enqueue(queue, (Point){r, c});
    grid[r][c] = '0';
    while(!isEmpty(queue))
    {
        Point p = dequeue(queue);
        int x = p.x;
        int y = p.y;
        

        for(int i = 0; i < 4; i++)
        {
            int newx = x + directions[i][0];
            int newy = y + directions[i][1];
            if(newx >= 0 && newx < row && newy >= 0 && newy < column && grid[newx][newy] == '1')
            {
                grid[newx][newy] = '0';
                enqueue(queue, (Point){newx, newy});
            }
            
        }
        

    }
    free(queue->data);
    free(queue);
    
}
int numIslands(char** grid, int gridSize, int* gridColSize) 
{
    if(gridSize * *gridColSize == 0)
    {
        return 0;
    }
    int column = *gridColSize;
    int row = gridSize;

    int count = 0;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(grid[i][j] == '1')
            {
                count++;
                bfs(grid, i, j, row, column);
            }
        }
    }
    return count;
}
