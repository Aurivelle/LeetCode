int longestMonotonicSubarray(int* nums, int numsSize) 
{
    int inc = 1;
    int dec = 1;
    int max = 0;
    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] > nums[i + 1])
        {
            inc++;
            max = dec > max ? dec : max;
            dec = 1;
        }
        else if(nums[i] < nums[i + 1])
        {
            dec++;
            max = inc > max ? inc : max;
            inc = 1;
        }
        else
        {
            max = inc > max ? inc : max;
            max = dec > max ? dec : max;
            inc = 1;
            dec = 1;
        }
    }
    max = inc > max ? inc : max;
    max = dec > max ? dec : max;
    return max;
}
