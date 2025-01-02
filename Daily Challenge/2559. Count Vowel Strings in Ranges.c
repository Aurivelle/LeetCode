/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;
} 
int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) 
{
    *returnSize = 0;
    int* record = (int*)malloc(sizeof(int) * wordsSize);
    int* sum = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++)
    {
        record[i] = 0;
        int len = strlen(words[i]);
        if(isvowel(words[i][0]) && isvowel(words[i][len - 1]))
        {
            record[i] = 1;
        }
        if(i == 0)
        {
            sum[i] = 0;
        }
        else
        {
            sum[i] = sum[i - 1] + record[i - 1];
        }
    }    
    int* answer = (int*)malloc(sizeof(int) * queriesSize);
    for(int i = 0; i < queriesSize; i++)
    {
        answer[(*returnSize)++] = sum[queries[i][1]] - sum[queries[i][0]] + record[queries[i][1]];
    }
    free(sum);
    free(record);
    return answer;
}
