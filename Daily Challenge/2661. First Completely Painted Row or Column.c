
typedef struct Node
{
    int key;
    int row;
    int col;
    struct Node* next;
} Node;

typedef struct
{
    Node** buckets;
    int size;
} HashTable;

HashTable* createHashTable(int size)
{
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (Node**)malloc(sizeof(Node*) * size);
    table->size = size;
    for(int i = 0; i < size; i++)
    {
        table->buckets[i] = NULL;
    }
    return table;
}

int hash(int key, int size)
{
    return key % size;
}

void insert(HashTable* table, int key, int row, int col)
{
    int index = hash(key, table->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->row = row;
    newNode->col = col;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

Node* find(HashTable* table, int key)
{
    int index = hash(key, table->size);
    Node* current = table->buckets[index];
    while(current != NULL)
    {
        if(current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeHashTable(HashTable* table)
{
    for(int i = 0; i < table->size; i++)
    {
        Node* current = table->buckets[i];
        while(current != NULL)
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) 
{
    int hashTableSize = matSize * *matColSize;
    HashTable* table = createHashTable(hashTableSize);

    for(int i = 0; i < matSize; i++)
    {
        for(int j = 0; j < *matColSize; j++)
        {
            insert(table, mat[i][j], i, j);
        }
    }

    int row_count[matSize];
    int col_count[*matColSize];

    for(int i = 0; i < matSize; i++)
    {
        row_count[i] = 0;
    }
    for(int i = 0; i < *matColSize; i++)
    {
        col_count[i] = 0;
    }

    for(int i = 0; i < arrSize; i++)
    {
        Node* position = find(table, arr[i]);
        if(position != NULL)
        {
            int r = position->row;
            int c = position->col;
            row_count[r]++;
            col_count[c]++;
            if(row_count[r] == *matColSize || col_count[c] == matSize)
            {
                freeHashTable(table);
                return i;
            }
        }

    }
    return -1;

}
