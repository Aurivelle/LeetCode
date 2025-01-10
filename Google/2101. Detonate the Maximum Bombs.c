typedef struct
{
    int capacity;
    int size;
    int* neighbors;
} Bomb;

Bomb* createBomb()
{
    Bomb* bomb = (Bomb*)malloc(sizeof(Bomb));
    bomb->size = 0;
    bomb->capacity = 2;
    bomb->neighbors = (int*)malloc(sizeof(int) * 2);
    return bomb;
}

void addEdge(Bomb* u, int v)
{
    if(u->size == u->capacity)
    {
        u->capacity *= 2;
        u->neighbors = (int*)realloc(u->neighbors, sizeof(int) * u->capacity);
    }
    u->neighbors[u->size++] = v;
}

long long calDistance(int** bombs, int u, int v)
{

    return (long long)((long long)bombs[u][0] - (long long)bombs[v][0]) * ((long long)bombs[u][0] - (long long)bombs[v][0]) + ((long long)bombs[u][1] - (long long)bombs[v][1]) * ((long long)bombs[u][1] - (long long)bombs[v][1]);
}
void dfs(Bomb** arr, int bomb, int* visited, int* count)
{
    visited[bomb] = 1;
    (*count)++;

    for(int i = 0; i < arr[bomb]->size; i++)
    {
        int neighbor = arr[bomb]->neighbors[i];
        if(!visited[neighbor])
        {
            dfs(arr, neighbor, visited, count);
        }
    }
    
}

int maximumDetonation(int** bombs, int bombsSize, int* bombsColSize) 
{
    Bomb* arr[bombsSize];
    for(int i = 0; i < bombsSize; i++)
    {
        arr[i] = createBomb();
    }
    
    for(int i = 0; i < bombsSize; i++)
    {
        for(int j = 0; j < bombsSize; j++)
        {
            if(i == j)
            {
                continue;
            }
            if((long long)bombs[i][2] * bombs[i][2] >= calDistance(bombs, i, j))
            {
                addEdge(arr[i], j);
            }
        }
    }

    int max = INT_MIN;
    int visited[bombsSize];

    for(int i = 0; i < bombsSize; i++)
    {
        memset(visited, 0, sizeof(visited));
        int count = 0;
        dfs(arr, i, visited, &count);
        if(count > max)
        {
            max = count;
        }
    }
    return max;
}
