void reverse(char* arr, int start, int end)
{
    while(start < end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

char* smallestNumber(char* pattern) 
{
    int len = strlen(pattern);
    char* answer = (char*)malloc(sizeof(char) * (len + 2));
    for(int i = 0; i <= len; i++)
    {
        answer[i] = i + '1';
    }
    for(int i = 0; i < len; i++)
    {
        if(pattern[i] == 'D')
        {
            int j = i;
            while(j < len && pattern[j] == 'D')
            {
                j++;
            }
            reverse(answer, i, j);
            i = j - 1;
        }
    }
    
    answer[len + 1] = '\0';
    return answer;
}
