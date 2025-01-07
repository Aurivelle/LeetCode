/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct HashNode
{
    char* key;
    struct HashNode* next;
} HashNode;

typedef struct HashSet
{
    HashNode** table;
    int size;
} HashSet;

unsigned int hashfunction(const char* key, int size)
{
    unsigned int hash = 0;
    while(*key)
    {
        hash *= 31;
        hash += *key;
        (key++);
    }
    return hash % size;
}

HashSet* createSet(int size)
{
    HashSet* set = (HashSet*)malloc(sizeof(HashSet) * size);
    set->table = (HashNode**)malloc(sizeof(HashNode*) * size);
    for(int i = 0; i < size; i++)
    {
        set->table[i] = NULL;

    }
    set->size = size;
    return set;
}

bool contains(HashSet* set, const char* key)
{
    unsigned int hashIndex = hashfunction(key, set->size);
    HashNode* node = set->table[hashIndex];
    while(node)
    {
        if(strcmp(node->key, key) == 0)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

void add(HashSet* set, const char* key)
{
    if(contains(set, key))
    {
        return;
    }

    unsigned int hashIndex = hashfunction(key, set->size);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->next = set->table[hashIndex];
    set->table[hashIndex] = node;

}

void freeHashSet(HashSet* set)
{
    for(int i = 0; i < set->size; i++)
    {
        HashNode* node = set->table[i];
        while(node)
        {
            HashNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(set->table);
    free(set);
}
void LPS(const char* pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool KMP(const char* pat, const char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int* lps = (int*)malloc(sizeof(int) * M);
    LPS(pat, M, lps);

    int i = 0; 
    int j = 0; 
    while((N - i) >= (M - j))
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if(j == M)
        {
            free(lps);
            return true;
        }
        else if(i < N && pat[j] != txt[i])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    free(lps);
    return false;
}
char** stringMatching(char** words, int wordsSize, int* returnSize) 
{
    (*returnSize) = 0;
    if(wordsSize == 1)
    {
        
        return NULL;
    }
    HashSet* set = createSet(200);
    char** answer = (char**)malloc(sizeof(char*) * 200);
    for(int i = 0; i < 200; i++)
    {
        answer[i] = (char*)malloc(sizeof(char*) * 31);
    }
    for(int i = 0; i < wordsSize; i++)
    {
        for(int j = 0; j < wordsSize; j++)
        {
            if(i != j && KMP(words[i], words[j]))
            {
                if(!contains(set, words[i]))
                {
                    strcpy(answer[*returnSize], words[i]);
                    answer[*returnSize][strlen(words[i])] = '\0';
                    (*returnSize)++;
                    add(set, words[i]);
                    break;
                }
            }
        }
    }
    return answer;


}
