/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* node, int count, int* max)
{
    if(!node->left && !node->right)
    {
        if(count > *max)
        {
            
            *max = count;
        }
        return;
    }
    if(node->left)
    {
        dfs(node->left, count + 1, max);
    }
    if(node->right)
    {
        dfs(node->right, count + 1, max);
    }
    

}

int maxDepth(struct TreeNode* root) 
{
    if(root == NULL)
    {
        return 0;
    }
    int max = INT_MIN;
    dfs(root, 1, &max);
    return max;
}
