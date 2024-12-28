/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) 
{
    *returnSize = 3;
    int* answer = (int*)malloc(sizeof(int) * 3);

    int* sum = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* left = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* right = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    sum[0] = 0;
    for(int i = 0; i < k; i++)
    {
        sum[0] += nums[i];
    }
    for(int i = 1; i < numsSize - k + 1; i++)
    {
        sum[i] = (sum[i - 1] - nums[i - 1] + nums[i + k - 1]);
    }
    int max_idx = 0;
    for(int i = 0; i < numsSize - k + 1; i++)
    {
        if(sum[i] > sum[max_idx])
        {
            max_idx = i;
        }
        left[i] = max_idx;
    }
    max_idx = numsSize - k;
    for(int i = numsSize - k; i >= 0; i--)
    {
        if(sum[i] >= sum[max_idx])
        {   
            max_idx = i;
        }
        right[i] = max_idx;
    }

    int max_sum = 0;
    for(int i = k; i < numsSize - 2 * k + 1; i++)
    {
        int l = left[i - k];
        int r = right[i + k];
        int total = sum[l] + sum[r] + sum[i];
        if(total > max_sum)
        {
            max_sum = total;
            answer[0] = l;
            answer[1] = i;
            answer[2] = r;
        }
    }
    free(left);
    free(right);
    free(sum);
    return answer;




}
