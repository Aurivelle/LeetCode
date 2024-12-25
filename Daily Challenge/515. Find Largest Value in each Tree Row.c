/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void expand (struct TreeNode*** queue, int* capacity)
{
    *capacity *= 2;
    *queue = (struct TreeNode**)realloc(*queue, (*capacity) * sizeof(struct TreeNode*));
}
struct TreeNode** createQueue(int size)
{
    return (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
}
void enqueue(struct TreeNode*** queue, int* rear, int* capacity, struct TreeNode* node)
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
int* largestValues(struct TreeNode* root, int* returnSize) 
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int capacity = 16;
    struct TreeNode** queue = createQueue(capacity);
    int front = 0;
    int rear = 0;
    int* answer = (int*)malloc(sizeof(int) * 10000);

    enqueue(&queue, &rear, &capacity, root);
    *returnSize = 0;
    while(front < rear)
    {
        int size = rear - front;
        int max = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = dequeue(queue, &front);
            if(node->val > max)
            {
                max = node->val;
            }
            

            if(node->left)
            {
                enqueue(&queue, &rear, &capacity, node->left);
            }
            if(node->right)
            {
                enqueue(&queue, &rear, &capacity, node->right);
            }
        }
        answer[(*returnSize)++] = max;
    }
    free(queue);
    return answer;

}
