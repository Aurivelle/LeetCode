/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recoverFromPreorder(char* traversal) 
{
    int len = strlen(traversal);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * len);
    int top = -1;
    int i = 0;
    while(traversal[i])
    {
        int depth = 0;
        int val = 0;
        while( traversal[i] == '-')
        {
            depth++;
            i++;
        }
        while(traversal[i] >= '0' && traversal[i] <= '9')
        {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;

        while(top >= depth)
        {
            top--;
        }
        
        if(top >= 0)
        {
            if(stack[top]->left == NULL)
            {
                stack[top]->left = node;
            }
            else
            {
                stack[top]->right = node;
            }
        }
        stack[++top] = node;
    }
    return stack[0];
}
