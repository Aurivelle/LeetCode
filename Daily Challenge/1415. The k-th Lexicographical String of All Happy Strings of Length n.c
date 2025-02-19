bool build(char* result, int n, int k, int* count, int index)
{
    if(index == n && *count == k)
    {
        return true;
    }
    if(index == n)
    {
        (*count)++;
        return false;
    }
    for(int i = 0; i < 3; i++)
    {
        if(index > 0 && 'a' + i == result[index - 1])
        {
            continue;
        }
        result[index] = 'a' + i;
        if(build(result, n, k, count, index + 1))
        {
            return true;
        }
    }
    
    return false;
}

char* getHappyString(int n, int k) 
{
    int val = 1;
    for(int i = 0; i < n - 1; i++)
    {
        val *= 2;
    }    
    if(3 * val < k)
    {
        return "";
    }
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    result[n] = '\0';
    int count = 1;
    build(result, n, k, &count, 0);

    return result;
}
