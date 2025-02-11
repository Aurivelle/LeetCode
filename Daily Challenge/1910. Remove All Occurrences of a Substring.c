char* removeOccurrences(char* s, char* part) 
{
    int len_s = strlen(s);
    int len_part = strlen(part);
    char* result = (char*)malloc(sizeof(char) * (len_s + 1));
    int index = 0;

    for(int i = 0; i < len_s; i++)
    {
        result[index++] = s[i];
        if(index >= len_part && strncmp(result + index - len_part, part, len_part) == 0)
        {
            index -= len_part;
        }
    }
    result[index] = '\0';
    return result;
}
