/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* inorder, int val, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int pstart, int pend, int istart, int iend)
{
    if(pstart > pend || istart > iend)
    {
        return NULL;
    }

    int rootval = preorder[pstart];
    struct TreeNode* root = createNode(rootval);

    int rootIndex = findIndex(inorder, rootval, istart, iend);

    int left = rootIndex - istart;

    root->left = build(preorder, inorder, pstart + 1, pstart + left, istart, rootIndex - 1);
    root->right = build(preorder, inorder, pstart + left + 1, pend, rootIndex + 1, iend);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
    return build(preorder, inorder, 0, preorderSize - 1, 0, inorderSize - 1);

}
