char* clearDigits(char* s) 
{
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * (len + 1));
    int top = 0;
    for(int i = 0; i < len; i++)
    {
        if(isdigit(s[i]))
        {
            top--;
            stack[top] = '\0';
        }
        else
        {
            stack[top++] = s[i];
        }
    }
    stack[top] = '\0';
    return stack;
}
