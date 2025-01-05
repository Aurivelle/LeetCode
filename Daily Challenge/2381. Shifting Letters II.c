char forward(char s)
{
    if(s == 'z')
    {
        s = 'a';
    }
    else
    {
        s++;
    }
    return s;
}

char backward(char s)
{
    if(s == 'a')
    {
        s = 'z';
    }
    else
    {
        s--;
    }
    return s;
}

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) 
{
    for(int i = 0; i < shiftsSize; i++)
    {
        for(int j = shifts[i][0]; j <= shifts[i][1]; j++)
        {
            if(shifts[i][2])
            {
                s[j] = forward(s[j]);
            }
            else
            {
                s[j] = backward(s[j]);
            }
        }
    }    
    return s;
}
