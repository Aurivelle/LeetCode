int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int tupleSameProduct(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), compare);
    int maxProduct = nums[numsSize - 1] * nums[numsSize - 2];
    int* hash = (int*)calloc(maxProduct + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) 
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            int product = nums[i] * nums[j];
            hash[product]++;
        }
    }

    int count = 0;
   
    for (int i = 0; i <= maxProduct; i++) 
    {
        if (hash[i] >= 2) 
        {
            count += (hash[i] * (hash[i] - 1) / 2) * 8;
        }
    }
    

    free(hash);
    
    return count;
}
