int countPalindromicSubsequence(char* s) 
{
    int left[26] = {0};
    int right[26] = {0};
    bool seen[26][26] = {false};

    int count = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        right[s[i] - 'a']++;
    }

    for(int i = 0; s[i] != '\0'; i++)
    {
        right[s[i] - 'a']--;
        for(int c = 0; c < 26; c++)
        {
            if(left[c] && right[c])
            {
                if(!seen[c][s[i] - 'a'])
                {
                    seen[c][s[i] - 'a'] = true;
                    count++;
                }
                
            }
        }
        left[s[i] - 'a'] = 1;
        
    }
    return count;


    
}
