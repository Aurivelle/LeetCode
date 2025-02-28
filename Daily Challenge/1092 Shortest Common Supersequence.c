void LCS(char* str1, char* str2, int m, int n, int dp[m + 1][n + 1])
{
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] )? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
}
char* shortestCommonSupersequence(char* str1, char* str2) 
{
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m + 1][n + 1];
    LCS(str1, str2, m, n, dp);   

    char* answer = (char*)malloc(sizeof(char) * (m + n + 1));
    int i = m;
    int j = n;
    int index = 0;
    while(i > 0 && j > 0)
    {
        if(str1[i - 1] == str2[j - 1])
        {
            answer[index++] = str1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1])
        {
            answer[index++] = str1[i - 1];
            i--;
        }
        else
        {
            answer[index++] = str2[j - 1];
            j--;
        }
    }

    while(i > 0)
    {
        answer[index++] = str1[--i];
    }
    while(j > 0)
    {
        answer[index++] = str2[--j];
    }

    answer[index] = '\0';
    for(int k = 0; k < index / 2; k++)
    {
        char temp = answer[k];
        answer[k] = answer[index - k - 1];
        answer[index - k - 1] = temp;
    }
    return answer;
}
