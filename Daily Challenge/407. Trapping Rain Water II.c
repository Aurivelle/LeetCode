int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct
{
    int x;
    int y;
    int height;
} Cell;

typedef struct
{
    Cell* cells;
    int size;
} Heap;

Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->cells = (Cell*)malloc(sizeof(Cell) * capacity);
    heap->size = 0;
    return heap;
}

void push(Heap* heap, int x, int y, int height)
{
    int i = heap->size++;
    while(i > 0 && height < heap->cells[(i - 1) / 2].height)
    {
        heap->cells[i] = heap->cells[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->cells[i] = (Cell){x, y, height};
}

Cell pop(Heap* heap)
{
    Cell root = heap->cells[0];
    Cell last = heap->cells[--heap->size];
    int i = 0;
    int child;
    while((child = 2 * i + 1) < heap->size)
    {
        if(child + 1 < heap->size && heap->cells[child].height > heap->cells[child + 1].height)
        {
            child++;
        }
        if(last.height <= heap->cells[child].height)
        {
            break;
        }
        heap->cells[i] = heap->cells[child];
        i = child;
    }
    heap->cells[i] = last;
    return root;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) 
{
    int row = heightMapSize;
    int column = *heightMapColSize;   
    if(row < 3 || column < 3)
    {
        return 0;
    } 
    int total = 0;
    int max = 0;
    bool** visited = (bool**)malloc(sizeof(bool*) * row);
    for(int i = 0; i < row; i++)
    {
        visited[i] = (bool*)malloc(sizeof(bool) * column);
        for(int j = 0; j < column; j++)
        {
            visited[i][j] = false;
        }
    }
    Heap* heap = createHeap(row * column);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == 0 || i == row - 1 || j == 0 || j == column - 1)
            {
                push(heap, i, j, heightMap[i][j]);
                visited[i][j] = true;
            }
        }
    }
    while(heap->size > 0)
    {
        Cell cell = pop(heap);
        if(cell.height > max)
        {
            max = cell.height;
        }
        for(int i = 0; i < 4; i++)
        {
            int newX = cell.x + directions[i][0];
            int newY = cell.y + directions[i][1];
            if(newX >= 0 && newX < row && newY >= 0 && newY < column && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                if(heightMap[newX][newY] < max)
                {
                    total += max - heightMap[newX][newY];
                }
                push(heap, newX, newY, heightMap[newX][newY] > max ? heightMap[newX][newY] : max);
            }
        }
        

    }
    for(int i = 0; i < row; i++)
    {
        free(visited[i]);
    }
    free(visited);
    free(heap->cells);
    free(heap);
    return total;
}
