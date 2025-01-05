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
    int size;
    int front;
    int rear;
    int capacity;
    struct TreeNode** arr;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    return queue;
}
void enqueue(Queue* queue, struct TreeNode* node)
{
    if(queue->size == queue->capacity)
    {
        return;
    }
    queue->arr[queue->rear] = node;
    queue->size++;
    queue->rear++;
}
struct TreeNode* dequeue(Queue* queue)
{
    if(queue->size == 0)
    {
        return NULL;
    }
    struct TreeNode* ret = queue->arr[queue->front];
    queue->front++;
    queue->size--;
    return ret;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    if(root == NULL)
    {
        *returnSize = 0;
        (*returnColumnSizes) = NULL;
        return NULL;
    }
    Queue* queue = createQueue(2000);
    enqueue(queue, root);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    int** answer = (int**)malloc(sizeof(int*) * 2000);
    for(int i = 0; i < 2000; i++)
    {
        answer[i] = (int*)malloc(sizeof(int) * 2000);
    }
    int level = 0;
    while(queue->front < queue->rear)
    {
        int size = queue->rear - queue->front;
        int count = 0;
        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = dequeue(queue);
            answer[level][count++] = node->val;
            if(node->left)
            {
                enqueue(queue, node->left);
            }
            if(node->right)
            {
                enqueue(queue, node->right);
            }
        }
        (*returnColumnSizes)[level] = count;
        level++;
    }
    *returnSize = level;
    free(queue->arr);
    free(queue);
    return answer;
}
