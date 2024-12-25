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
void enqueue(struct TreeNode*** queue, struct TreeNode* node, int* rear)
{
    (*queue)[(*rear)++] = node;
}
struct TreeNode* dequeue(struct TreeNode*** queue, int* front)
{
    return (*queue)[(*front)++];
}

int* rightSideView(struct TreeNode* root, int* returnSize) 
{
    *returnSize = 0;
    if(root == NULL)
    {
        return NULL;
    }
    int* answer = (int*)malloc(sizeof(int) * 100);

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 101);
    int front = 0;
    int rear = 0;
    enqueue(&queue, root, &rear);
    while(front < rear)
    {
        int size = rear - front;
        struct TreeNode* n;
        for(int i = 0; i < size; i++)
        {
            n = dequeue(&queue, &front);
            if(n->left)
            {
                enqueue(&queue, n->left, &rear);
            }
            if(n->right)
            {
                enqueue(&queue, n->right, &rear);  
            }
        }
        answer[(*returnSize)++] = n->val;
    }
    free(queue);
    return answer;

}
