/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min = INT_MAX;
int prev = -1;
void InorderTraversal(struct TreeNode* node)
{
    if(node == NULL)
    {
        return;
    }
    
    InorderTraversal(node->left);
    if(prev != -1)
    {
        if(abs(node->val - prev) < min)
        {
            min = abs(node->val - prev);
        }
    }
    prev = node->val;
    InorderTraversal(node->right);
    

}
int getMinimumDifference(struct TreeNode* root) 
{
    min = INT_MAX;
    prev = -1;
    InorderTraversal(root);
    return min;
}
