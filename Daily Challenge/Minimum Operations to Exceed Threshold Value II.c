typedef struct
{
    int size;
    long long* elements;
} Heap;

void siftUp(Heap* heap, int index)
{
    int parent = (index - 1) / 2;
    if(heap->elements[index] < heap->elements[parent])
    {
        long long temp = heap->elements[index];
        heap->elements[index] = heap->elements[parent];
        heap->elements[parent] = temp;
        siftUp(heap, parent);
    }
}

void insert(Heap* heap, long long num)
{
    heap->elements[heap->size++] = num;
    siftUp(heap, heap->size - 1);
}

void siftDown(Heap* heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if(left < heap->size && heap->elements[smallest] > heap->elements[left])
    {
        smallest = left;
    }
    if(right < heap->size && heap->elements[smallest] > heap->elements[right])
    {
        smallest = right;
    }
    if(smallest != index)
    {
        long long temp = heap->elements[smallest];
        heap->elements[smallest] = heap->elements[index];
        heap->elements[index] = temp;
        siftDown(heap, smallest);
    }
}

long long extractMin(Heap* heap)
{
    long long ret = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);
    return ret;
}

int minOperations(int* nums, int numsSize, int k) 
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->elements = (long long*)malloc(sizeof(long long) * numsSize);
    heap->size = 0;

    for(int i = 0; i < numsSize; i++)
    {
        insert(heap, nums[i]);
    }

    int count = 0;

    while(heap->elements[0] < k)
    {
        long long min = extractMin(heap);
        long long second_min = extractMin(heap);
        long long new = min * 2 + second_min;
        insert(heap, new);
        count++;
    }

    return count;

}
