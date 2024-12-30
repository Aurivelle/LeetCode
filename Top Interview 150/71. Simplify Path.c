typedef struct 
{
    char** string;
    int size;
    int capacity;
} Stack;

Stack* create(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->string = (char**)malloc(sizeof(char*) * capacity);
    for (int i = 0; i < capacity; i++) 
    {
        stack->string[i] = NULL;
    }
    return stack;
}

void push(Stack* stack, const char* string)
{
    stack->string[stack->size] = strdup(string);
    stack->size++;
}

void pop(Stack* stack) 
{
    if(stack->size == 0)
    {
        return;
    }
    free(stack->string[--stack->size]);
    stack->string[stack->size] = NULL;
}

void freeStack(Stack* stack) 
{
    for (int i = 0; i < stack->capacity; i++) 
    {
        if (stack->string[i] != NULL) 
        {
            free(stack->string[i]);
        }
    }
    free(stack->string);
    free(stack);
}

char* simplifyPath(char* path) 
{
    int len = strlen(path);
    char* answer = (char*)malloc(sizeof(char) * (len + 1));
    answer[0] = '\0';

    Stack* stack = create(3000);

    char* token = strtok(path, "/");

    while (token != NULL) 
    {
        if (strcmp(token, ".") == 0) 
        {
            token = strtok(NULL, "/");
            continue;
        } 
        else if (strcmp(token, "..") == 0) 
        {
            pop(stack); 
        } 
        else 
        {
            push(stack, token);
        }
        token = strtok(NULL, "/");
    }

    if (stack->size == 0) 
    {
        strcpy(answer, "/");
    } 
    else 
    {
        for (int i = 0; i < stack->size; i++) 
        {
            strcat(answer, "/");
            strcat(answer, stack->string[i]);
        }
    }

    freeStack(stack);
    return answer;
}
