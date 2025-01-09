int prefixCount(char** words, int wordsSize, char* pref) 
{
    int count = 0;
    int preflen = strlen(pref);
    for(int i = 0; i < wordsSize; i++)
    {
        for(int j = 0; j < preflen; j++)
        {
            if(preflen > strlen(words[i]))
            {
                break;
            }
            if(pref[j] == words[i][j])
            {
                
            }
            else
            {
                break;
            }
            if(j == preflen - 1)
            {
                count++;
            }
        }
    }    
    return count;
}
