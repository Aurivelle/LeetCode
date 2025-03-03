/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) 
{
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int count = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == pivot)
        {
            count++;
        }
    }
    int idx = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] < pivot)
        {
            ans[idx++] = nums[i];
        }
    }
    for(int i = 0; i < count; i++)
    {
        ans[idx++] = pivot;
    }
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > pivot)
        {
            ans[idx++] = nums[i];
        }
    }
    return ans;
}
