typedef struct
{
    char gene[9];
    int steps;
} Node;

typedef struct
{
    Node nodes[100];
    int front;
    int rear;
} Queue;

void enqueue(Queue* queue, char* gene, int steps)
{
    strcpy(queue->nodes[queue->rear].gene, gene);
    queue->nodes[queue->rear].steps = steps;
    queue->rear++;
}

Node dequeue(Queue *queue)
{
    return queue->nodes[queue->front++];
}

int is_empty(Queue *queue)
{
    return queue->front == queue->rear;
}

bool isNeighbor(char* a, char* b)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        if(a[i] != b[i])
        {
            count++;
        }
        if(count >= 2)
        {
            return false;
        }
    }
    return count == 1;
}


int minMutation(char* startGene, char* endGene, char** bank, int bankSize) 
{
    if(bankSize == 0)
    {
        return -1;
    }
    Queue queue = {.front = 0, .rear = 0};
    enqueue(&queue, startGene, 0);
    int visited[bankSize];
    for(int i = 0; i < bankSize; i++)
    {
        visited[i] = 0;
    }

    while(!is_empty(&queue))
    {
        Node current = dequeue(&queue);

        if(strcmp(current.gene, endGene) == 0)
        {
            return current.steps;
        }

        for(int i = 0; i < bankSize; i++)
        {
            if(!visited[i] && isNeighbor(current.gene, bank[i]))
            {
                visited[i] = 1;
                enqueue(&queue, bank[i], current.steps + 1);
            }
        }
    }
    return -1;


}
