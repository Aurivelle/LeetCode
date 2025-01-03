/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min = INT_MAX;
void InorderTraversal(struct TreeNode* node, int* array, int* count)
{
    if(node->left)
    {
        InorderTraversal(node->left, array, count);
    }

    array[(*count)++] = node->val;

    if(node->right)
    {
        InorderTraversal(node->right, array, count);
    }

}
int getMinimumDifference(struct TreeNode* root) 
{
    int array[100000];
    int count = 0;
    InorderTraversal(root, array, &count);
    int min = INT_MAX;
    for(int i = 1; i < count; i++)
    {
        int diff = array[i] - array[i - 1];
        if(diff < min)
        {
            min = diff;
        }
    }
    return min;
}
