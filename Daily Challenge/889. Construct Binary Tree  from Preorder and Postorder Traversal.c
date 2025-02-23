/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findIndex(int* arr, int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) 
{
    if(preorderSize == 0 || postorderSize == 0)
    {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    root->val = preorder[0];
    if(preorderSize == 1)
    {
        return root;
    }
    int leftRootVal = preorder[1];
    int leftSize = findIndex(postorder, postorderSize, leftRootVal) + 1;

    root->left = constructFromPrePost(preorder + 1, leftSize, postorder, leftSize);
    root->right = constructFromPrePost(preorder + leftSize + 1, preorderSize - leftSize - 1, postorder + leftSize, postorderSize - leftSize - 1 );
    return root;


}
