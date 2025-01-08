typedef struct
{
    char* s;
    int index;
} Node;

Node* createNode(char* s, int index)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->s = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(node->s, s);
    node->s[strlen(s)] = '\0';
    node->index = index;
    return node;
}
bool isNeighbor(char* s, char* t)
{
    int len = strlen(s);
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] != t[i])
        {
            count++;
        }
        if(count > 1)
        {
            return false;
        }
    }
    if(count == 1)
    {
        return true;
    }
    return false;
}

void enqueue(Node** queue, Node* node, int* size, int capacity, int* rear)
{
    if(*size == capacity)
    {
        return;
    }
    queue[*rear] = node;
    (*rear)++;
    (*size)++;
}

Node* dequeue(Node** queue, int* size, int capacity, int* front)
{
    if(*size == 0)
    {
        return NULL;
    }
    (*size)--;
    (*front)++;
    return queue[*front - 1];
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) 
{
    int count = 1;
    int len = strlen(beginWord);
     int capacity = 2 * wordListSize;
    Node** queue = (Node**)malloc(sizeof(Node*) * capacity);
    for(int i = 0; i < capacity; i++)
    {
        queue[i] = NULL;
    }
    

    int front = 0;
    int rear = 0;
    int size = 0;
   
    int visited[wordListSize];
    for(int i = 0; i < wordListSize; i++)
    {
        visited[i] = 0;
    }
    Node* root = createNode(beginWord, -1);
    enqueue(queue, root, &size, capacity, &rear);

    while(front < rear)
    {
        int sizes = rear - front;
        for(int i = 0; i < sizes; i++)
        {
            Node* node = dequeue(queue, &size, capacity, &front);
            if(node->index != -1)
                visited[node->index] = 1;
            for(int j = 0; j < wordListSize; j++)
            {
                if(!(visited[j]))
                {
                    if(isNeighbor(node->s, wordList[j]))
                    {
                        if(strcmp(wordList[j], endWord) == 0)
                        {
                            for (int i = 0; i < rear; i++) 
                            {
                                free(queue[i]->s);
                                free(queue[i]);
                            }
                            free(queue);
                            return count + 1;
                        }
                        Node* new = createNode(wordList[j], j);
                        enqueue(queue, new, &size, capacity, &rear);
                        visited[j] = 1;
                    }
                }
            }
            

        }
        count++;
        
    }
    for (int i = 0; i < rear; i++) 
    {
        free(queue[i]->s);
        free(queue[i]);
    }
    free(queue);
    return 0;
}
