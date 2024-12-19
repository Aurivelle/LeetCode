int min(int a, int b)
{
    return a < b? a : b;
}
int max(int a, int b)
{
    return a > b? a : b;
}
int maxArea(int* height, int heightSize) 
{
    int ret = INT_MIN;
    for(int i = 0; i < heightSize; i++)
    {
        for(int j = heightSize - 1; j > i; j--)
        {
            int min_height = min(height[i], height[j]);
            ret = max(ret, min_height * (j - i));
        }
        
    }
    return ret;
}
