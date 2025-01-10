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

struct TreeNode* postOrderTraversal(struct TreeNode* node, int* to_delete, int size, int* returnSize, struct TreeNode** ans, bool* hash)
{
    if(node == NULL)
    {
        return NULL;
    }

    node->left = postOrderTraversal(node->left, to_delete, size, returnSize, ans, hash);
    node->right = postOrderTraversal(node->right, to_delete, size, returnSize, ans, hash);
    if(hash[node->val])
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
    bool hash[1001] = {false};
    for(int i = 0; i < to_deleteSize; i++)
    {
        hash[to_delete[i]] = 1;
    }
    root = postOrderTraversal(root, to_delete, to_deleteSize, returnSize, ans, hash);
    if(root)
    {
        ans[(*returnSize)++] = root;
    }
    return ans;






}
