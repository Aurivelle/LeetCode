char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) 
{
    int len = strlen(s);
    int diff[len + 1];
    for(int i = 0; i <= len; i++)
    {
        diff[i] = 0;
    }    
    for(int i = 0; i < shiftsSize; i++)
    {
        if(shifts[i][2])
        {
            diff[shifts[i][0]]++;
            diff[shifts[i][1] + 1]--;
        }
        else
        {
            diff[shifts[i][0]]--;
            diff[shifts[i][1] + 1]++;
        }
    }
    for(int i = 1; i <= len; i++)
    {
        
        diff[i] += diff[i - 1];
    }
    for(int i = 0; i < len; i++)
    {
        printf("%d\n", diff[i]);
    }
    for(int i = 0; i < len; i++)
    {
        s[i] = (char)(((s[i] - 'a' + diff[i]) % 26 + 26) % 26 + 'a');
        
    }
    return s;
}
