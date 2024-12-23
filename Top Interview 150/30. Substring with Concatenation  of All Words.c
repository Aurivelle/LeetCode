typedef struct 
{
    char word[30];
    int count;
} wordHash;

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) 
{
    int lens = strlen(s);
    int lenw = strlen(words[0]);
    int countw = wordsSize;
    int total = wordsSize * lenw;
    if (lens < lenw || lens < total || wordsSize == 0) 
    {
        *returnSize = 0;
        int* answer = (int*)malloc(sizeof(int));
        return answer;
    }
    int* answer = (int*)malloc(sizeof(int) * (lens - total + 1));

    

    *returnSize = 0;

    wordHash wordhash[wordsSize];
    memset(wordhash, 0, sizeof(wordhash));

    for (int i = 0; i < wordsSize; i++) 
    {
        int found = 0;
        for (int j = 0; j < i; j++) 
        {
            if (strcmp(wordhash[j].word, words[i]) == 0) 
            {
                wordhash[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            strcpy(wordhash[i].word, words[i]);
            wordhash[i].count = 1;
        }
    }

    for (int i = 0; i < lenw; i++) 
    {
        int left = i;
        int right = i;
        int currentcount[wordsSize];
        memset(currentcount, 0, sizeof(currentcount));
        int valid = 0;

        while (right + lenw <= lens) 
        {
            char word[lenw + 1];
            strncpy(word, s + right, lenw);
            word[lenw] = '\0';
            right += lenw;

            int found = -1;
            for (int j = 0; j < wordsSize; j++)
            {
                if (strcmp(wordhash[j].word, word) == 0) 
                {
                    found = j;
                    break;
                }
            }

            if (found != -1) 
            {
                currentcount[found]++;
                if (currentcount[found] <= wordhash[found].count) 
                {
                    valid++;
                } 
                else 
                {
                    while (currentcount[found] > wordhash[found].count) 
                    {
                        char temp[lenw + 1];
                        strncpy(temp, s + left, lenw);
                        temp[lenw] = '\0';
                        left += lenw;
                        for (int j = 0; j < wordsSize; j++) 
                        {
                            if (strcmp(wordhash[j].word, temp) == 0) 
                            {
                                currentcount[j]--;
                                if (currentcount[j] < wordhash[j].count) {
                                    valid--;
                                }
                                break;
                            }
                        }
                    }
                }

                if (valid == wordsSize) 
                {
                    answer[(*returnSize)++] = left;
                }
            } 
            else 
            {
                memset(currentcount, 0, sizeof(currentcount));
                valid = 0;
                left = right;
            }
        }
    }
    return answer;
}
