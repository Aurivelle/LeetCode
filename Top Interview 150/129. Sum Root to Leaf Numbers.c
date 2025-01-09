/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* node, int pathsum, int* totalsum)
{
    if(node == NULL)
    {
        return;
    }
    if(!node->right && !node->left)
    {
        *totalsum += 10 * pathsum + node->val;
    }
    pathsum = 10 * pathsum + node->val;
    dfs(node->left, pathsum, totalsum);
    dfs(node->right, pathsum, totalsum);
    
}
int sumNumbers(struct TreeNode* root) 
{
    int totalsum = 0;
    dfs(root, 0, &totalsum);
    return totalsum;
}
