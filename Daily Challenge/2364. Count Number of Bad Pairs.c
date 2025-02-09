int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
long long countBadPairs(int* nums, int numsSize) 
{
    for(int i = 0; i < numsSize; i++)
    {
        nums[i] = nums[i] - i;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int same_Num = 1;
    long long count = 0;
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] == nums[i + 1])
        {
            same_Num++;
        }
        else
        {
            count += same_Num * (same_Num - 1) / 2;
            same_Num = 1;
        }
    }
    count += (long long)same_Num * ((long long)same_Num - 1) / (long long)2;
    return ((long long)numsSize * (long long)(numsSize - 1) / (long long)2) - (long long)count;


}
