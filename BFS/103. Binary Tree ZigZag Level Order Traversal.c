/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct
{
    int front;
    int rear;
    int size;
    int capacity;
    struct TreeNode** nodes;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    return queue;
}

void enqueue(Queue* queue, struct TreeNode* node)
{
    if(queue->size == queue->capacity)
    {
        return;
    }
    queue->nodes[queue->rear++] = node;
    queue->size++;
}

struct TreeNode* dequeue(Queue* queue)
{
    if(queue->size == 0)
    {
        return NULL;
    }
    struct TreeNode* node = queue->nodes[queue->front++];
    queue->size--;
    return node;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    if(root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    Queue* queue = createQueue(2000);
    enqueue(queue, root);
    *returnSize = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 30);
    int** answer = (int**)malloc(sizeof(int*) * 30);
    while(queue->front < queue->rear)
    {
        int size = queue->rear - queue->front;
        (*returnColumnSizes)[*returnSize] = size;
        answer[*returnSize] = (int*)malloc(sizeof(int) * size);
        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = dequeue(queue);
            if(*returnSize % 2)
            {
                answer[*returnSize][size - i - 1] = node->val;
            }
            else
            {
                answer[*returnSize][i] = node->val;
            }
            if(node->left)
            {
                enqueue(queue, node->left);
            }
            if(node->right)
            {
                enqueue(queue, node->right);
            }

        }
        (*returnSize)++;

    }
    return answer;
}
