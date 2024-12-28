typedef struct
{
    int* array;
    int size;
    int capacity;  
} MaxHeap;

MaxHeap* createHeap(int capacity)
{
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

void siftUp(MaxHeap* heap, int index)
{
    int parent = (index - 1) / 2;

    while(index > 0 && heap->array[index] > heap->array[parent])
    {
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(MaxHeap* heap, int value)
{
    if(heap->size == heap->capacity)
    {
        return;
    }

    heap->array[heap->size] = value;
    heap->size++;
    siftUp(heap, heap->size - 1);
}
void siftDown(MaxHeap* heap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap->size && heap->array[left] > heap->array[largest])
    {
        largest = left;
    }
    if(right < heap->size && heap->array[right] > heap->array[largest])
    {
        largest = right;
    }
    if(largest != index)
    {
        int temp = heap->array[largest];
        heap->array[largest] = heap->array[index];
        heap->array[index] = temp;

        siftDown(heap, largest);
    }
}
int extractMax(MaxHeap* heap)
{
    if(heap->size <= 0)
    {
        return INT_MAX;
    }

    int temp = heap->array[heap->size - 1];
    heap->array[heap->size - 1] = heap->array[0];
    heap->array[0] = temp;
    heap->size--;

    siftDown(heap, 0);
    return heap->array[heap->size];
}

int findKthLargest(int* nums, int numsSize, int k) 
{
    MaxHeap* heap = createHeap(numsSize);

    for(int i = 0; i < numsSize; i++)
    {
        insert(heap, nums[i]);
    }
    for(int i = 0; i < k - 1; i++)
    {
        extractMax(heap);
    }
    return extractMax(heap);
}
