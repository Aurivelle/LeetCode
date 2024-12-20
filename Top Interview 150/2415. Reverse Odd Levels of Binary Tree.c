/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void expand(struct TreeNode*** queue, int* capacity)
{
    *capacity *= 2;
    *queue = (struct TreeNode**)realloc(*queue, (*capacity) * sizeof(struct TreeNode*));
}

struct TreeNode** createQueue(int size)
{
    return (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
}

void enqueue(struct TreeNode*** queue, int* rear, int*capacity, struct TreeNode* node)
{
    if(*rear >= *capacity)
    {
        expand(queue, capacity);
    }
    (*queue)[*rear] = node;
    (*rear)++;
}

struct TreeNode* dequeue(struct TreeNode** queue, int* front)
{
    (*front)++;
    return queue[*front - 1];
}
struct TreeNode* reverseOddLevels(struct TreeNode* root) 
{
    int capacity = 16;
    struct TreeNode** queue = createQueue(capacity);
    int front = 0;
    int rear = 0;

    enqueue(&queue, &rear, &capacity, root);
    int level = 0;
    while(front < rear)
    {
        int size = rear - front;
        int* values = (int*)malloc(sizeof(int) * size);
        struct TreeNode** nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
        int index = 0;

        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = dequeue(queue, &front);
            values[index] = node->val;
            nodes[index] = node;
            index++;

            if(node->left)
            {
                enqueue(&queue, &rear, &capacity, node->left);
            }
            if(node->right)
            {
                enqueue(&queue, &rear, &capacity, node->right);
            }
        }
        if(level % 2)
        {
            for(int i = 0; i < size / 2; i++)
            {
                swap(&values[i], &values[size - 1 - i]);
            }
            for(int i = 0; i < size; i++)
            {
                nodes[i]->val = values[i];
            }
        }
        free(values);
        free(nodes);
        level++;
    }
    free(queue);
    return root;
}
