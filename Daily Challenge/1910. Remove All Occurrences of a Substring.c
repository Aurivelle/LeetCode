char* removeOccurrences(char* s, char* part) 
{
    char* pos = NULL;
    int len = strlen(part);

    while((pos = strstr(s, part)) != NULL)
    {
        memmove(pos, pos + len, strlen(pos + len) + 1);
    }
    return s;
}
