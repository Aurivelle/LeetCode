
typedef struct HashNode 
{
    int key;        
    int count;     
    struct HashNode* next;
} HashNode;


int hashFunction(int key, int size) 
{
    return key % size;
}


void insert(HashNode** table, int key, int size) 
{
    int index = hashFunction(key, size);
    HashNode* node = table[index];

    while (node) {
        if (node->key == key) 
        {
            node->count++;
            return;
        }
        node = node->next;
    }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = table[index];
    table[index] = newNode;
}

int tupleSameProduct(int* nums, int numsSize) {
    int hashSize = 100003; 
    HashNode** hashTable = (HashNode**)calloc(hashSize, sizeof(HashNode*));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++)
        {
            int product = nums[i] * nums[j];
            insert(hashTable, product, hashSize);
        }
    }

    int result = 0;
    for (int i = 0; i < hashSize; i++)
    {
        HashNode* node = hashTable[i];
        while (node) {
            if (node->count >= 2) 
            {
                result += (node->count * (node->count - 1) / 2) * 8;
            }
            node = node->next;
        }
    }

    for (int i = 0; i < hashSize; i++) 
    {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(hashTable);

    return result;
}
