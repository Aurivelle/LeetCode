char* findDifferentBinaryString(char** nums, int numsSize) 
{
    char* answer = (char*)malloc(sizeof(char) * (numsSize + 1));
    answer[numsSize] = '\0';
    int size = 1 << numsSize;
    int hash[size];
    for(int i = 0; i < size; i++)
    {
        hash[i] = 0;
    }
    for(int i = 0; i < numsSize; i++)
    {
        int num = 0;
        for(int j = 0; j < numsSize; j++)
        {
            num *= 2;
            num += nums[i][j] - '0';
            
        }
        hash[num]++;
    }
    int ans = 0;
    for(int i = 0; i < size; i++)
    {
        if(hash[i] == 0)
        {
            ans = i;
        }
    }
    int count = numsSize - 1;
    while(ans > 0)
    {
        answer[count--] = ans % 2 + '0';
        ans /= 2;
    }
    for(int i = 0; i < numsSize; i++)
    {
        if(!isdigit(answer[i]))
        {
            answer[i] = '0';
        }
    }
    return answer;
}
