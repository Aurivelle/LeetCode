/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct
{
    int key;
    UT_hash_handle hh;
} HashNode;

typedef struct 
{
    HashNode* hash_table;
    struct TreeNode* root;
} FindElements;

void insert(HashNode** hash_table, int key)
{
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    HASH_ADD_INT(*hash_table, key, node);
}

void recover(struct TreeNode* node, int value, HashNode** hash_table)
{
    if(!node)
    {
        return;
    }
    node->val = value;
    insert(hash_table, value);
    recover(node->left, 2 * value + 1, hash_table);
    recover(node->right, 2 * value + 2, hash_table);
}


FindElements* findElementsCreate(struct TreeNode* root) 
{
    FindElements* find = (FindElements*)malloc(sizeof(FindElements));
    find->hash_table = NULL;
    find->root = root;
    if(root)
    {
        recover(root, 0, &(find->hash_table));
    }
    
    return find;   
}

bool findElementsFind(FindElements* obj, int target) 
{
    HashNode* node;
    HASH_FIND_INT(obj->hash_table, &target, node);
    return node != NULL;
}

void findElementsFree(FindElements* obj) 
{
    free(obj);    
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
