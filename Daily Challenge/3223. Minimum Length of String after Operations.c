int minimumLength(char* s) 
{
    int len = strlen(s);
    int hash[26] = {0};
    for(int i = 0; i < len; i++)
    {
        hash[s[i] - 'a']++;
    }
    int sum = 0;
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] % 2)
        {
            sum++;
        }
        else if(hash[i] != 0)
        {
            sum += 2;
        }
    }
    return sum;
}
