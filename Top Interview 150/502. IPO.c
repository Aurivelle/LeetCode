typedef struct
{
    int profit;
    int capital;
} Project;

int cmp(const void* a, const void* b)
{
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

typedef struct
{
    int size;
    int capacity;
    int* profits;
}Heap;

Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->profits = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftUp(Heap* heap, int index)
{
    if(index == 0)
    {
        return;
    }
    int parent = (index - 1) / 2;
    if(heap->profits[parent] < heap->profits[index])
    {
        swap(&heap->profits[parent], &heap->profits[index]);
    }
    siftUp(heap, parent);
}

void insert(Heap* heap, int profit)
{
    if(heap->size == heap->capacity)
    {
        return;
    }
    heap->profits[heap->size] = profit;
    heap->size++;
    siftUp(heap, heap->size - 1);
}

void siftDown(Heap* heap, int index)
{
    if(index >= heap->size)
    {
        return;
    }
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if(left < heap->size && heap->profits[smallest] < heap->profits[left])
    {
        smallest = left;
    }
    if(right < heap->size && heap->profits[smallest] < heap->profits[right])
    {
        smallest = right;
    }
    if(smallest != index)
    {
        swap(&heap->profits[smallest], &heap->profits[index]);
        siftDown(heap, smallest);
    }
    
}

int extractMax(Heap* heap)
{
    int ret = heap->profits[0];
    swap(&heap->profits[0], &heap->profits[heap->size - 1]);
    heap->size--;
    siftDown(heap, 0);
    return ret;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) 
{
    Project* project = (Project*)malloc(sizeof(Project) * profitsSize);
    for(int i = 0; i < profitsSize; i++)
    {
        project[i].profit = profits[i];
        project[i].capital = capital[i];
    }

    qsort(project, profitsSize, sizeof(Project), cmp);
    Heap* heap = createHeap(profitsSize);

    int i = 0;
    for(int start = 0; start < k; start++)
    {
        while(i < profitsSize && project[i].capital <= w)
        {
            insert(heap, project[i].profit);
            i++;
        }
        if(heap->size == 0)
        {
            break;
        }
        int max = extractMax(heap);
        w += max;
    }
    free(heap->profits);
    free(heap);
    free(project);
    return w;



}
