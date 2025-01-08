bool isPrefixAndSuffix(char* s1, char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if(len1 > len2)
    {
        return false; 
    }

    for(int i = 0; i < len1; i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
        if(s1[len1 - i - 1] != s2[len2 - i - 1])
        {
            return false;
        }
    }
    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) 
{
    int count = 0;
    for(int i = 0; i < wordsSize - 1; i++)
    {
        for(int j = i + 1; j < wordsSize; j++)
        {
            if(isPrefixAndSuffix(words[i], words[j]))
            {
                count++;
            }
        }
        
    }
    return count;
}
