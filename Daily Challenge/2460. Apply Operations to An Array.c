/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) 
{
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    int curr = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int temp = nums[i];
        nums[i] = 0;
        if(temp != 0)
        {
            
            nums[curr++] = temp;
        }
        
    }
    *returnSize = numsSize;
    return nums;
}
