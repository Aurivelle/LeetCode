/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) 
{
    
    
    int** nums = (int**)malloc(sizeof(int*) * (nums1Size + nums2Size));
    for(int i = 0; i < nums1Size + nums2Size; i++)
    {
        nums[i] = (int*)malloc(sizeof(int) * 2);
        
    }    
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i][0] == nums2[j][0])
        {
            nums[count][1] = nums1[i][1] + nums2[j][1];
            nums[count++][0] = nums1[i][0];

            i++;
            j++;
        }
        else if(nums1[i][0] < nums2[j][0])
        {
            nums[count][1] = nums1[i][1];
            nums[count++][0] = nums1[i][0];
            i++;
        }
        else
        {
            nums[count][1] = nums2[j][1];
            nums[count++][0] = nums2[j][0];
            j++;
        }
    }
    while(i < nums1Size)
    {
        nums[count][1] = nums1[i][1];
        nums[count++][0] = nums1[i][0];
        i++;
    }
    while(j < nums2Size)
    {
        nums[count][1] = nums2[j][1];
        nums[count++][0] = nums2[j][0];
        j++;
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) 
    {
        (*returnColumnSizes)[i] = 2;  
    }
    
    
    

    return nums;
}
