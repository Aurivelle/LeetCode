/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) 
{
    int* ans = (int*)malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    for(int i = 0; i  < ASize; i++)
    {
        ans[i] = 0;
    }
    int hash[51] = {0};
    if(A[0] == B[0])
    {
        ans[0] = 1;
        hash[A[0]] += 2;
    }
    else
    {
        hash[B[0]]++;
        hash[A[0]]++;
    }
    for(int i = 1; i < ASize; i++)
    {
        ans[i] = ans[i - 1];
        hash[A[i]]++;
        if(hash[A[i]] == 2)
        {
            ans[i]++;
        }
        hash[B[i]]++;
        if(hash[B[i]] == 2)
        {
            ans[i]++;
        }
    }
    return ans;

}
