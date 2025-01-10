/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) 
{
    int maxfreq[26] = {0};
    *returnSize = 0;
    for(int i = 0; i < words2Size; i++)
    {
        int len = strlen(words2[i]);
        int freq[26] = {0};
        for(int j = 0; j < len; j++)
        {
            freq[words2[i][j] - 'a']++;
        }
        for(int j = 0; j < 26; j++)
        {
            if(freq[j] > maxfreq[j])
            {
                maxfreq[j] = freq[j];
            }
        }
    }
    char** answer = (char**)malloc(sizeof(char*) * words1Size);
    for(int i = 0; i < words1Size; i++)
    {
        answer[i] = (char*)malloc(sizeof(char) * 11);
        int len = strlen(words1[i]);
        int freq[26] = {0};
        for(int j = 0; j < len; j++)
        {
            freq[words1[i][j] - 'a']++;
        }
        bool add = true;
        for(int j = 0; j < 26; j++)
        {
            if(freq[j] < maxfreq[j])
            {
                add = false;
                break;
            }
        }
        if(add)
        {
            strcpy(answer[(*returnSize)++], words1[i]);
        }
    }
    return answer;
    
}
