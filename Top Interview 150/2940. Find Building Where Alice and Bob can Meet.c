typedef struct 
{
    int first;
    int second;
} Pair;

typedef struct 
{
    Pair* data;
    int size;
    int capacity;
} Vector;

void initVector(Vector* vec, int initialCapacity) 
{
    vec->data = (Pair*)malloc(sizeof(Pair) * initialCapacity);
    vec->size = 0;
    vec->capacity = initialCapacity;
}

void pushBack(Vector* vec, Pair value) 
{
    if (vec->size == vec->capacity) 
    {
        vec->capacity *= 2;
        vec->data = (Pair*)realloc(vec->data, sizeof(Pair) * vec->capacity);
    }
    vec->data[vec->size++] = value;
}

void popBack(Vector* vec)
{
    if (vec->size > 0) 
    {
        vec->size--;
    }
}

void freeVector(Vector* vec) 
{
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

int search(int height, Vector* monoStack) 
{
    int left = 0;
    int right = monoStack->size - 1;
    int ans = -1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (monoStack->data[mid].first > height) 
        {
            ans = mid;
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return ans;
}

int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    *returnSize = queriesSize;
    int* result = (int*)malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) 
    {
        result[i] = -1;
    }

    Vector* newQueries = (Vector*)malloc(sizeof(Vector) * heightsSize);
    for (int i = 0; i < heightsSize; i++) 
    {
        initVector(&newQueries[i], 2);
    }

    for (int i = 0; i < queriesSize; i++) 
    {
        int a = queries[i][0];
        int b = queries[i][1];
        if (a > b) 
        {
            int temp = a;
            a = b;
            b = temp;
        }
        if (heights[b] > heights[a] || a == b) 
        {
            result[i] = b;
        } 
        else 
        {
            Pair query = {heights[a], i};
            pushBack(&newQueries[b], query);
        }
    }

    Vector monoStack;
    initVector(&monoStack, 10);

    for (int i = heightsSize - 1; i >= 0; i--) 
    {
        int monoStackSize = monoStack.size;

        for (int j = 0; j < newQueries[i].size; j++) 
        {
            int height = newQueries[i].data[j].first;
            int queryIndex = newQueries[i].data[j].second;
            int position = search(height, &monoStack);
            if (position < monoStackSize && position >= 0) 
            {
                result[queryIndex] = monoStack.data[position].second;
            }
        }

        while (monoStack.size > 0 && monoStack.data[monoStack.size - 1].first <= heights[i]) 
        {
            popBack(&monoStack);
        }
        Pair newElement = {heights[i], i};
        pushBack(&monoStack, newElement);
    }

    for (int i = 0; i < heightsSize; i++) 
    {
        freeVector(&newQueries[i]);
    }
    free(newQueries);
    freeVector(&monoStack);

    return result;
}
