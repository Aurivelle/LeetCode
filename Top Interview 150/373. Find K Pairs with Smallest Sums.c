typedef struct 
{
    int sum;    
    int i;      
    int j;      
} HeapNode;

typedef struct 
{
    HeapNode* array;
    int size;
    int capacity;
} minheap;

void swap(HeapNode* a, HeapNode* b) 
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

minheap* createheap(int capacity) 
{
    minheap* heap = (minheap*)malloc(sizeof(minheap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    return heap;
}

void siftUp(minheap* heap, int index) 
{
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heap->array[parent].sum <= heap->array[index].sum)
        {
            break;
        }
        swap(&heap->array[parent], &heap->array[index]);
        index = parent;
    }
}

void insert(minheap* heap, HeapNode node) 
{
    heap->array[heap->size] = node;
    heap->size++;
    siftUp(heap, heap->size - 1);
}

void siftDown(minheap* heap, int index) 
{
    while (index < heap->size) 
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size && heap->array[left].sum < heap->array[smallest].sum)
            smallest = left;
        if (right < heap->size && heap->array[right].sum < heap->array[smallest].sum)
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap->array[smallest], &heap->array[index]);
        index = smallest;
    }
}

HeapNode extractmin(minheap* heap) 
{
    HeapNode root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);
    return root;
}

void freeHeap(minheap* heap)
{
    free(heap->array);
    free(heap);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, 
                     int k, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0 || k == 0)
    {
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);

    minheap* heap = createheap(k);

    for (int i = 0; i < nums1Size && i < k; i++) 
    {
        HeapNode node = {nums1[i] + nums2[0], i, 0};
        insert(heap, node);
    }

    while (*returnSize < k && heap->size > 0) 
    {
        HeapNode top = extractmin(heap);

        // Store the result
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = nums1[top.i];
        result[*returnSize][1] = nums2[top.j];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        if (top.j + 1 < nums2Size) 
        {
            HeapNode next = {nums1[top.i] + nums2[top.j + 1], top.i, top.j + 1};
            insert(heap, next);
        }
    }

    freeHeap(heap);
    return result;
}
