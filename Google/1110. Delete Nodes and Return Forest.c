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
bool deleted(int val, int* to_delete, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(to_delete[i] == val)
        {
            return true;
        }
    }
    return false;
}
bool isleaf(struct TreeNode* node)
{
    if(!node->left && !node->right)
    {
        return true;
    }
    return false;
}
struct TreeNode* postOrderTraversal(struct TreeNode* node, int* to_delete, int size, int* returnSize, struct TreeNode** ans)
{
    if(node == NULL)
    {
        return NULL;
    }

    node->left = postOrderTraversal(node->left, to_delete, size, returnSize, ans);
    node->right = postOrderTraversal(node->right, to_delete, size, returnSize, ans);
    if(deleted(node->val, to_delete, size))
    {
        
        if(node->left)
        {
            ans[(*returnSize)++] = node->left;
        }
        if(node->right)
        {
            ans[(*returnSize)++] = node->right;
        }

        free(node);
        return NULL;
        
    }
    return node;
}
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
{
    if(root == NULL)
    {
        return NULL;
    }
    struct TreeNode** ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    root = postOrderTraversal(root, to_delete, to_deleteSize, returnSize, ans);
    if(root)
    {
        ans[(*returnSize)++] = root;
    }
    return ans;

}
