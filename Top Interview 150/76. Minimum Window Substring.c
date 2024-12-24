char* minWindow(char* s, char* t) 
{
    int len1 = strlen(s);
    int len2 = strlen(t);

    if (len1 < len2) 
    {
        return "";
    }
    
    int m1[128] = {0};
    int m2[128] = {0};

    for (int i = 0; i < len2; i++) 
    {
        m2[t[i]]++;
    }

    int start = 0;     
    int ansIndex = -1;  
    int ansLen = INT_MAX; 
    int count = 0;    

    for (int i = 0; i < len1; i++) 
    {
        char ch = s[i];
        m1[ch]++;

        if (m1[ch] <= m2[ch]) 
        {
            count++;
        }

        
        if (count == len2) 
        {
           
            char temp = s[start];
            while (m1[temp] > m2[temp] || m2[temp] == 0) 
            {
                if (m1[temp] > m2[temp]) 
                {
                    m1[temp]--;
                }
                start++;
                temp = s[start];
            }


            int lengthOfWindow = i - start + 1;
            if (lengthOfWindow < ansLen) 
            {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }

    if (ansIndex == -1) 
    {
        return "";
    }
    char* result = (char*)malloc((ansLen + 1) * sizeof(char));
    strncpy(result, s + ansIndex, ansLen);
    result[ansLen] = '\0';
    return result;
}
