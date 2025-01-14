typedef struct
{
    int size;
    int capacity;
    int** events;
} Heap;

Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->events = (int**)malloc(sizeof(int*) * capacity);
    return heap;
}

void siftUp(Heap* heap, int index)
{
    int parent = (index - 1) / 2;
    while(index > 0 && heap->events[index][1] < heap->events[parent][1])
    {
        int* temp = heap->events[index];
        heap->events[index] = heap->events[parent];
        heap->events[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(Heap* heap, int* events)
{
    if(heap->size == heap->capacity)
    {
        return;
    }

    heap->events[heap->size++] = events;
    siftUp(heap, heap->size - 1);
}

void siftDown(Heap* heap, int index)
{
    int smallest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < heap->size && heap->events[smallest][1] > heap->events[left][1])
    {
        smallest = left;
    }
    if(right < heap->size && heap->events[smallest][1] > heap->events[right][1])
    {
        smallest = right;
    }
    if(index != smallest)
    {
        int* temp = heap->events[index];
        heap->events[index] = heap->events[smallest];
        heap->events[smallest] = temp;
        index = smallest;
        siftDown(heap, index);
    }
    
}

int* extractMin(Heap* heap)
{
    if (heap->size == 0)
    {
        return NULL; 
    }
    int* event = heap->events[0];
    heap->events[0] = heap->events[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);
    return event;
}
int cmp(const void* a, const void* b)
{
    int* eventsA = *(int**)a;
    int* eventsB = *(int**)b;

    if(eventsA[0] == eventsB[0])
    {
        return eventsA[1] - eventsB[1];
    }
    return eventsA[0] - eventsB[0];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) 
{
    qsort(events, eventsSize, sizeof(events[0]), cmp);
    int count = 0;
    Heap* heap = createHeap(eventsSize);
    int day = 0;
    int eventIndex = 0;
    while(eventIndex < eventsSize || heap->size > 0)
    {
        if(heap->size == 0)
        {
            day = events[eventIndex][0];
        }
        while(eventIndex < eventsSize && events[eventIndex][0] <= day)
        {
            insert(heap, events[eventIndex]);
            eventIndex++;
        }

        int* currentEvent = extractMin(heap);
        if (currentEvent != NULL && day <= currentEvent[1])
        {
            count++;
            day++;
        }
    }
    free(heap->events);
    free(heap);
    return count;
    

}
