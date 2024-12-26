int dfs(int index, int currentsum, int target, int numsSize, int* nums)
{
    if(index == numsSize)
    {
        if(currentsum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int plus = dfs(index + 1, currentsum + nums[index], target, numsSize, nums);
    int minus = dfs(index + 1, currentsum - nums[index], target, numsSize, nums);
    return plus + minus;

    
}
int findTargetSumWays(int* nums, int numsSize, int target) 
{
    int sum = dfs(0, 0, target, numsSize, nums);
    return sum;
}
