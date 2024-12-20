int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;  
    int capacity = 10;

    int** answer = (int**)malloc(sizeof(int*) * capacity);

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++) 
    {
        if (i > 0 && nums[i] == nums[i - 1]) 
        {
            continue;
        }
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int inner_sum = nums[i] + nums[left] + nums[right];

            if (inner_sum < 0) 
            {
                left++;
            } 
            else if (inner_sum > 0) 
            {
                right--;
            } 
            else 
            {
                
                if (*returnSize >= capacity) 
                {
                    capacity *= 2;
                    answer = realloc(answer, sizeof(int*) * capacity);
                }

                answer[*returnSize] = (int*)malloc(sizeof(int) * 3);

                answer[*returnSize][0] = nums[i];
                answer[*returnSize][1] = nums[left];
                answer[*returnSize][2] = nums[right];
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) 
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                     right--;
                }

                left++;
                right--;
            }
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));


    for (int i = 0; i < *returnSize; i++) 
    {
        (*returnColumnSizes)[i] = 3;
    }

    return answer;
}
