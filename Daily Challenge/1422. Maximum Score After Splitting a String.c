int maxScore(char* s) 
{
    int len = strlen(s);
    if(len == 2)
    {
        if(strcmp(s, "00") == 0 || strcmp(s, "11") == 0)
        {
            return 1;
        }
        else if(strcmp(s, "01") == 0)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    int zero[len];
    if(s[0] == '0')
    {
        zero[0] = 1;
    }
    else
    {
        zero[0] = 0;
    }
    int one[len];
    if(s[len - 1] == '1')
    {
        one[len - 1] = 1;
    }
    else
    {
        one[len - 1] = 0;
    }

    for(int i = 1; i < len; i++)
    {
        if(s[i] == '0')
        {
            zero[i] = zero[i - 1] + 1;
        }
        else
        {
            zero[i] = zero[i - 1];
        }
    }
    for(int i = len - 2; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            one[i] = one[i + 1] + 1;
        }
        else
        {
            one[i] = one[i + 1];
        }
        
    }
    int max = 0;
    for(int i = 1; i < len - 1; i++)
    {
        int sum = zero[i] + one[i];
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}
