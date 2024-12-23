
int minSwaps(int* arr, int size) 
{
    struct Pair 
    {
        int val;
        int idx;
    };
    struct Pair* pairs = (struct Pair*)malloc(sizeof(struct Pair) * size);
    for (int i = 0; i < size; i++) 
    {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
    }
    int compare(const void* a, const void* b) 
    {
        return ((struct Pair*)a)->val - ((struct Pair*)b)->val;
    }
    qsort(pairs, size, sizeof(struct Pair), compare);

    int* visited = (int*)calloc(size, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < size; i++) 
    {
        if (visited[i] || pairs[i].idx == i) 
        {
            continue;
        }

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) 
        {
            visited[j] = 1;
            j = pairs[j].idx;
            cycle_size++;
        }
        swaps += cycle_size - 1;
    }

    free(pairs);
    free(visited);
    return swaps;
}

int minimumOperations(struct TreeNode* root) 
{
    if (!root) return 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(100000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int count = 0;

    while (front < rear) 
    {
        int size = rear - front;
        int* values = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) 
        {
            struct TreeNode* node = queue[front++];
            values[i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        count += minSwaps(values, size);
        free(values);
    }

    free(queue);
    return count;
}
