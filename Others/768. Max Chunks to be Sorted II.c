int maxChunksToSorted(int* arr, int arrSize) 
{
    int leftMax[arrSize];
    leftMax[0] = arr[0];
    int rightSmall[arrSize];
    rightSmall[arrSize - 1] = arr[arrSize - 1];
    for(int i = 1; i < arrSize; i++)
    {
        if(arr[i] >= leftMax[i - 1])
        {
            leftMax[i] = arr[i];
        }
        else
        {
            leftMax[i] = arr[i - 1];
        }
    }
    for(int i = arrSize - 2; i >= 0; i--)
    {
        if(arr[i] <= rightSmall[i + 1])
        {
            rightSmall[i] = arr[i];
        }
        else
        {
            rightSmall[i] = arr[i + 1];
        }
    }
    int count = 1;
    for(int i = 0; i < arrSize - 1; i++)
    {
        if(leftMax[i] <= rightSmall[i + 1])
        {
            count++;
        }
    }
    return count;    
}
