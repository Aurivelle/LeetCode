typedef struct Node
{
    struct Node* children[26];
    bool end;
} Node;

typedef struct 
{
    Node* root;
} Trie;

Node* createNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->end = false;
    for(int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

Trie* trieCreate() 
{
    Trie* trie = (Trie*)malloc(sizeof(Trie)); 
    trie->root = createNode();
    return trie;   
}

void trieInsert(Trie* obj, char* word) 
{
    int len = strlen(word);
    Node* ptr = obj->root;
    for(int i = 0; i < len; i++)
    {
        if(ptr->children[word[i] - 'a'] == NULL)
        {
            ptr->children[word[i] - 'a'] = createNode();
        }

        ptr = ptr->children[word[i] - 'a'];
        
    }
    ptr->end = true;
}
    

bool trieSearch(Trie* obj, char* word) 
{
    int len = strlen(word);
    Node* ptr = obj->root;
    for(int i = 0; i < len; i++)
    {
        if(ptr->children[word[i] - 'a'] == NULL)
        {
            return false;
        }
        ptr = ptr->children[word[i] - 'a'];
    }
    return ptr->end;
}

bool trieStartsWith(Trie* obj, char* prefix) 
{
    int len = strlen(prefix);
    Node* ptr = obj->root;
    for(int i = 0; i < len; i++)
    {
        if(ptr->children[prefix[i] - 'a'] == NULL)
        {
            return false;
        }
        ptr = ptr->children[prefix[i] - 'a'];
    }
    return true;
}

void freeNode(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    for(int i = 0; i < 26; i++)
    {
        freeNode(node->children[i]);
    }
    free(node);
}
void trieFree(Trie* obj) 
{
    if(obj != NULL)
    {
        freeNode(obj->root);
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
