bool areAlmostEqual(char* s1, char* s2) 
{
    int count = 0;
    int len = strlen(s1);
    int hash[26] = {0};
    for(int i = 0; i < len; i++)
    {
        hash[s1[i] - 'a']++;
        hash[s2[i] - 'a']--;
        if(s1[i] == s2[i])
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] != 0)
        {
            return false;
        }
    }
    return count <= 2 && count != 1;    
}
