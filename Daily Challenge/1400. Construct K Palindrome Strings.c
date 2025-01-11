bool canConstruct(char* s, int k) 
{
    int len = strlen(s) ;
    if(len < k)
    {
        return false;
    }
    int hash[26] = {0};
    for(int i = 0; i < len; i++)
    {
        hash[s[i] - 'a']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] % 2)
        {
            odd++;
        }
    } 
    if(odd > k)
    {
        return false;
    }
    return true;
}
