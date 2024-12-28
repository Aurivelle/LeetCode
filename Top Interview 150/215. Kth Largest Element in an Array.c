int partition(int* nums, int l, int r) 
{
    int x = nums[r];
    int i = l;
    for (int j = l; j < r; j++) 
    {
        if (nums[j] <= x) 
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    int temp = nums[i];
    nums[i] = nums[r];
    nums[r] = temp;
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) 
{
    int l = 0, r = numsSize - 1;
    k = numsSize - k; 

    while (l <= r) 
    {
        int index = partition(nums, l, r);
        if (index == k)
        {
            return nums[index];
        } 
        else if (index < k) 
        {
            l = index + 1;
        } 
        else 
        {
            r = index - 1;
        }
    }
    return INT_MAX;
}
